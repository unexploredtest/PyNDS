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

std::vector<uint32_t> Nds::getGbaFrame() {
    if(m_isGba) {
        const uint32_t size = GBA_WIDTH*GBA_HEIGHT;

        std::vector<uint32_t> frame(size);
        std::copy(m_framebuffer, m_framebuffer + size, frame.begin());

        return std::move(frame);
    } else {
        return std::vector<uint32_t>(0);
    }
}

std::vector<uint32_t> Nds::getTopNdsFrame() {
    if(!m_isGba) {
        const uint32_t size = NDS_WIDTH*NDS_HEIGHT;

        std::vector<uint32_t> frame(size);
        std::copy(m_framebuffer, m_framebuffer + size, frame.begin());

        return std::move(frame);
    } else {
        return std::vector<uint32_t>(0);
    }
}

std::vector<uint32_t> Nds::getBotNdsFrame() {
    if(!m_isGba) {
        const uint32_t size = NDS_WIDTH*NDS_HEIGHT;

        std::vector<uint32_t> frame(size);
        std::copy(&m_framebuffer[size], &m_framebuffer[size] + size, frame.begin());

        return std::move(frame);
    } else {
        return std::vector<uint32_t>(0);
    }
}

void Nds::setTouchInput(int x, int y) {
    m_core->spi.setTouch(x, y);
}

void Nds::clearTouchInput() {
    m_core->spi.clearTouch();
}

void Nds::touchInput() {
    m_core->input.pressScreen();
}

void Nds::releaseTouchInput() {
    m_core->input.releaseScreen();
}

void Nds::pressKey(int key) {
    m_core->input.pressKey(key);
}

void Nds::releaseKey(int key) {
    m_core->input.releaseKey(key);
}

