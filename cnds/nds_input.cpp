#include "nds.hpp"


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
