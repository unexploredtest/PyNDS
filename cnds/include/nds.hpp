#pragma once

#include <vector>
#include <nanobind/ndarray.h>

#include "noods.h"

namespace nb = nanobind;

class Nds {
    public:
        Nds(std::string filePath, bool isGba);
        ~Nds();

        void runTask();
        void runUntilFrame();
        bool getFrame();

        // Grab emulator frame methods
        nb::ndarray<nb::numpy, uint8_t> getGbaFrame();
        nb::ndarray<nb::numpy, uint8_t> getTopNdsFrame();
        nb::ndarray<nb::numpy, uint8_t> getBotNdsFrame();

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

        // Read ram methods
        uint8_t readRamu8(uint32_t address);
        uint16_t readRamu16(uint32_t address);
        uint32_t readRamu32(uint32_t address);
        uint64_t readRamu64(uint32_t address);

        int8_t readRami8(uint32_t address);
        int16_t readRami16(uint32_t address);
        int32_t readRami32(uint32_t address);
        int64_t readRami64(uint32_t address);

        float readRamf32(uint32_t address);
        double readRamf64(uint32_t address);

        std::vector<uint8_t> readMap(uint32_t sAddress, uint32_t eAddress);

        // Write ram methods
        void writeRamu8(uint32_t address, uint8_t value);
        void writeRamu16(uint32_t address, uint16_t value);
        void writeRamu32(uint32_t address, uint32_t value);
        void writeRamu64(uint32_t address, uint64_t value);

        void writeRami8(uint32_t address, int8_t value);
        void writeRami16(uint32_t address, int16_t value);
        void writeRami32(uint32_t address, int32_t value);
        void writeRami64(uint32_t address, int64_t value);

        void writeRamf32(uint32_t address, float value);
        void writeRamf64(uint32_t address, double value);

        void writeMap(uint32_t sAddress, uint32_t size, const std::vector<uint8_t>& buffer);

    private:
        static const uint16_t GBA_WIDTH = 240;
        static const uint16_t GBA_HEIGHT = 160;
        static const uint16_t NDS_WIDTH = 256;
        static const uint16_t NDS_HEIGHT = 192;

        uint32_t m_framebuffer[NDS_WIDTH * NDS_HEIGHT * 16];
        Core* m_core;
        bool m_isGba;
};
