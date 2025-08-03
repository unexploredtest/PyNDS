#pragma once

#include "noods.h"

class Config {
    public:
        // Direct Boot
        static void setDirectBoot(int directBoot);
        static int getDirectBoot();

        // ROM in RAM
        static void setRomInRam(int romInRam);
        static int getRomInRam();

        // FPS Limiter
        static void setFpsLimiter(int fpsLimiter);
        static int getFpsLimiter();

        // Frame Skip
        static void setFrameSkip(int frameSkip);
        static int getFrameSkip();

        // Threaded 2D
        static void setThreaded2D(int threaded2D);
        static int getThreaded2D();

        // Threaded 3D
        static void setThreaded3D(int threaded3D);
        static int getThreaded3D();

        // High Resolution 3D
        static void setHighRes3D(int highRes3D);
        static int getHighRes3D();

        // Screen Ghost
        static void setScreenGhost(int screenGhost);
        static int getScreenGhost();

        // Emulate Audio
        static void setEmulateAudio(int emulateAudio);
        static int getEmulateAudio();

        // Audio 16 Bit
        static void setAudio16Bit(int audio16Bit);
        static int getAudio16Bit();

        // Saves Folder
        static void setSavesFolder(int savesFolder);
        static int getSavesFolder();

        // States Folder
        static void setStatesFolder(int statesFolder);
        static int getStatesFolder();

        // Cheats Folder
        static void setCheatsFolder(int cheatsFolder);
        static int getCheatsFolder();

        // Screen Filter
        static void setScreenFilter(int screenFilter);
        static int getScreenFilter();

        // ARM7 HLE
        static void setArm7Hle(int arm7Hle);
        static int getArm7Hle();

        // DSi Mode
        static void setDsiMode(int dsiMode);
        static int getDsiMode();

        // BIOS Paths
        static void setBios9Path(const std::string& bios9Path);
        static std::string getBios9Path();

        static void setBios7Path(const std::string& bios7Path);
        static std::string getBios7Path();

        static void setFirmwarePath(const std::string& firmwarePath);
        static std::string getFirmwarePath();

        static void setGbaBiosPath(const std::string& gbaBiosPath);
        static std::string getGbaBiosPath();

        static void setSdImagePath(const std::string& sdImagePath);
        static std::string getSdImagePath();

        static void setBasePath(const std::string& basePath);
        static std::string getBasePath();
};
