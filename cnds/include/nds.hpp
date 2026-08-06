#pragma once

#include <vector>
#include <nanobind/ndarray.h>

#include "noods.h"

namespace nb = nanobind;

class Nds {
    public:
        Nds(std::string filePath, std::string savePath, bool isGba);
        ~Nds();

        void runTask();
        void runUntilFrame();
        bool getFrame();

        // Grab emulator frame methods
        nb::ndarray<nb::numpy, uint8_t> getGbaFrame();
        nb::ndarray<nb::numpy, uint8_t> getTopNdsFrame();
        nb::ndarray<nb::numpy, uint8_t> getBotNdsFrame();

        // Audio methods
        nb::ndarray<nb::numpy, int16_t> getAudioSamples(int count);
        uint32_t getAudioBufferNumber();

        // Savestate methods
        void saveState(std::string path);
        void loadState(std::string path);

        // Save game methods
        void saveGame(const std::string& path, bool alwaysSave);

        // Touch input methods
        void setTouchInput(int x, int y);
        void clearTouchInput();
        void touchInput();
        void releaseTouchInput();

        // Joystick input methods
        void pressKey(int key);
        void releaseKey(int key);

        // Read ram methods
        uint8_t readRamu8(bool arm7, uint32_t address, bool tcm);
        uint16_t readRamu16(bool arm7, uint32_t address, bool tcm);
        uint32_t readRamu32(bool arm7, uint32_t address, bool tcm);
        uint64_t readRamu64(bool arm7, uint32_t address, bool tcm);

        int8_t readRami8(bool arm7, uint32_t address, bool tcm);
        int16_t readRami16(bool arm7, uint32_t address, bool tcm);
        int32_t readRami32(bool arm7, uint32_t address, bool tcm);
        int64_t readRami64(bool arm7, uint32_t address, bool tcm);

        float readRamf32(bool arm7, uint32_t address, bool tcm);
        double readRamf64(bool arm7, uint32_t address, bool tcm);

        std::vector<uint8_t> readMap(uint32_t sAddress, uint32_t eAddress);

        // Write ram methods
        void writeRamu8(bool arm7, uint32_t address, uint8_t value, bool tcm);
        void writeRamu16(bool arm7, uint32_t address, uint16_t value, bool tcm);
        void writeRamu32(bool arm7, uint32_t address, uint32_t value, bool tcm);
        // void writeRamu64(bool arm7, uint32_t address, uint64_t value, bool tcm);

        void writeRami8(bool arm7, uint32_t address, int8_t value, bool tcm);
        void writeRami16(bool arm7, uint32_t address, int16_t value, bool tcm);
        void writeRami32(bool arm7, uint32_t address, int32_t value, bool tcm);
        // void writeRami64(bool arm7, uint32_t address, int64_t value, bool tcm);

        void writeRamf32(bool arm7, uint32_t address, float value, bool tcm);
        // void writeRamf64(bool arm7, uint32_t address, double value, bool tcm);

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
