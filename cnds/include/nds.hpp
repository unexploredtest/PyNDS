#pragma once

#include <vector>

#include "noods.h"


class Nds {
    public:
        Nds(std::string filePath, bool isGba);
        ~Nds();

        void runTask();
        void runUntilFrame();
        bool getFrame();

        // Grab emulator frame methods
        std::vector<uint32_t> getGbaFrame();
        std::vector<uint32_t> getTopNdsFrame();
        std::vector<uint32_t> getBotNdsFrame();

        // Savestate methods
        void saveState(std::string path);
        void loadState(std::string path);

        // Touch input methods
        void setTouchInput(int x, int y);
        void clearTouchInput();
        void touchInput();
        void releaseTouchInput();

        // Joystick input methods
        void pressKey(int key);
        void releaseKey(int key);

    private:
        static const uint16_t GBA_WIDTH = 240;
        static const uint16_t GBA_HEIGHT = 160;
        static const uint16_t NDS_WIDTH = 256;
        static const uint16_t NDS_HEIGHT = 192;

        uint32_t m_framebuffer[NDS_WIDTH * NDS_HEIGHT * 8];
        Core* m_core;
        bool m_isGba;
};