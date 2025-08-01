#pragma once

#include "noods.h"

class Config {
    public:
        static void setDirectBoot(bool directBoot);
        static void setFrameSkip(int frameSkip);
};

// int Settings::directBoot = 1;
// int Settings::romInRam = 0;
// int Settings::fpsLimiter = 1;
// int Settings::frameskip = 0;
// int Settings::threaded2D = 1;
// int Settings::threaded3D = 1;
// int Settings::highRes3D = 0;
// int Settings::screenGhost = 0;
// int Settings::emulateAudio = 1;
// int Settings::audio16Bit = 1;
// int Settings::savesFolder = 0;
// int Settings::statesFolder = 1;
// int Settings::cheatsFolder = 1;
// int Settings::screenFilter = 2;
// int Settings::arm7Hle = 0;
// int Settings::dsiMode = 0;

// std::string Settings::bios9Path = "bios9.bin";
// std::string Settings::bios7Path = "bios7.bin";
// std::string Settings::firmwarePath = "firmware.bin";
// std::string Settings::gbaBiosPath = "gba_bios.bin";
// std::string Settings::sdImagePath = "sd.img";
// std::string Settings::basePath = ".";