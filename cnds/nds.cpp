#include <algorithm>
#include <iostream>

#include "nds.hpp"


Nds::Nds(std::string filePath, bool isGba) {
    if(isGba) {
        m_core = new Core("", filePath);
    } else {
        m_core = new Core(filePath);
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

void Nds::saveState(std::string path) {
    m_core->saveStates.setPath(path, m_isGba);
    m_core->saveStates.saveState();
}

void Nds::loadState(std::string path) {
    m_core->saveStates.setPath(path, m_isGba);
    m_core->saveStates.loadState();
}
