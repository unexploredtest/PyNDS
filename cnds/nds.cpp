#include <algorithm>
#include <fcntl.h>
#include <iostream>

#include "nds.hpp"


Nds::Nds(std::string filePath, std::string savePath, bool isGba) {
    int saveFd = savePath != "" ? open(savePath.c_str(), O_RDONLY) : -1;
    if(isGba) {
        m_core = new Core("", filePath, 0, -1, -1, -1, saveFd);
    } else {
        m_core = new Core(filePath, "", 0, -1, -1, saveFd, -1);
    }

    m_isGba = isGba;
}

Nds::~Nds() {
    delete m_core;
}

void Nds::runTask() {
    m_core->runCore();
}

void Nds::runUntilFrame() {
    while(!m_core->gpu.getBufferSize()) {
        m_core->runCore();
    }
}

bool Nds::getFrame() {
    bool isFrame = m_core->gpu.getFrame(m_framebuffer, m_isGba);
    return isFrame;
}

nb::ndarray<nb::numpy, uint8_t> Nds::getGbaFrame() {
    bool shift = (Settings::highRes3D || Settings::screenFilter == 1);
    if(m_isGba) {
        const uint32_t width = GBA_WIDTH << shift;
        const uint32_t height = GBA_HEIGHT << shift;
        return nb::ndarray<nb::numpy, uint8_t>(reinterpret_cast<void*>(m_framebuffer), {height, width, 4});
    } else {
        return nb::ndarray<nb::numpy, uint8_t>();
    }
}

nb::ndarray<nb::numpy, uint8_t> Nds::getTopNdsFrame() {
    bool shift = (Settings::highRes3D || Settings::screenFilter == 1);
    if(!m_isGba) {
        const uint32_t width = NDS_WIDTH << shift;
        const uint32_t height = NDS_HEIGHT << shift;
        return nb::ndarray<nb::numpy, uint8_t>(reinterpret_cast<void*>(m_framebuffer), {height, width, 4});
    } else {
        return nb::ndarray<nb::numpy, uint8_t>();
    }
}

nb::ndarray<nb::numpy, uint8_t> Nds::getBotNdsFrame() {
    bool shift = (Settings::highRes3D || Settings::screenFilter == 1);
    if(!m_isGba) {
        const uint32_t size = (NDS_WIDTH * NDS_HEIGHT) << (2 * shift);
        const uint32_t width = NDS_WIDTH << shift;
        const uint32_t height = NDS_HEIGHT << shift;
        return nb::ndarray<nb::numpy, uint8_t>(reinterpret_cast<void*>(m_framebuffer + size), {height, width, 4});
    } else {
        return nb::ndarray<nb::numpy, uint8_t>();
    }
}

nb::ndarray<nb::numpy, int16_t> Nds::getAudioSamples(int count) {
    uint32_t* raw = m_core->spu.getSamples(count);
    int16_t* samples = new int16_t[count * 2];
    for (int i = 0; i < count; i++) {
        samples[i * 2]     = (int16_t)(raw[i] & 0xFFFF);
        samples[i * 2 + 1] = (int16_t)((raw[i] >> 16) & 0xFFFF);
    }
    nb::capsule owner(samples, [](void* p) noexcept {
        delete[] (int16_t*)p;
    });
    return nb::ndarray<nb::numpy, int16_t>(samples, {(size_t)count, 2}, owner);
}

void Nds::saveState(std::string path) {
    m_core->saveStates.setPath(path, m_isGba);
    m_core->saveStates.saveState();
}

void Nds::loadState(std::string path) {
    m_core->saveStates.setPath(path, m_isGba);
    m_core->saveStates.loadState();
}

void Nds::saveGame(const std::string& path, bool alwaysSave) {
    if(m_isGba) {
        m_core->cartridgeGba.writeSaveToPath(path, alwaysSave);
    } else {
        m_core->cartridgeNds.writeSaveToPath(path, alwaysSave);
    }
}
