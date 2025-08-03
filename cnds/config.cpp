#include "config.hpp"


// Direct Boot
void Config::setDirectBoot(int directBoot) {
    Settings::directBoot = directBoot;
}

int Config::getDirectBoot() {
    return Settings::directBoot;
}

// ROM in RAM
void Config::setRomInRam(int romInRam) {
    Settings::romInRam = romInRam;
}

int Config::getRomInRam() {
    return Settings::romInRam;
}

// FPS Limiter
void Config::setFpsLimiter(int fpsLimiter) {
    Settings::fpsLimiter = fpsLimiter;
}

int Config::getFpsLimiter() {
    return Settings::fpsLimiter;
}

// Frame Skip
void Config::setFrameSkip(int frameSkip) {
    Settings::frameskip = frameSkip;
}

int Config::getFrameSkip() {
    return Settings::frameskip;
}

// Threaded 2D
void Config::setThreaded2D(int threaded2D) {
    Settings::threaded2D = threaded2D;
}

int Config::getThreaded2D() {
    return Settings::threaded2D;
}

// Threaded 3D
void Config::setThreaded3D(int threaded3D) {
    Settings::threaded3D = threaded3D;
}

int Config::getThreaded3D() {
    return Settings::threaded3D;
}

// High Resolution 3D
void Config::setHighRes3D(int highRes3D) {
    Settings::highRes3D = highRes3D;
}

int Config::getHighRes3D() {
    return Settings::highRes3D;
}

// Screen Ghost
void Config::setScreenGhost(int screenGhost) {
    Settings::screenGhost = screenGhost;
}

int Config::getScreenGhost() {
    return Settings::screenGhost;
}

// Emulate Audio
void Config::setEmulateAudio(int emulateAudio) {
    Settings::emulateAudio = emulateAudio;
}

int Config::getEmulateAudio() {
    return Settings::emulateAudio;
}

// Audio 16 Bit
void Config::setAudio16Bit(int audio16Bit) {
    Settings::audio16Bit = audio16Bit;
}

int Config::getAudio16Bit() {
    return Settings::audio16Bit;
}

// Saves Folder
void Config::setSavesFolder(int savesFolder) {
    Settings::savesFolder = savesFolder;
}

int Config::getSavesFolder() {
    return Settings::savesFolder;
}

// States Folder
void Config::setStatesFolder(int statesFolder) {
    Settings::statesFolder = statesFolder;
}

int Config::getStatesFolder() {
    return Settings::statesFolder;
}

// Cheats Folder
void Config::setCheatsFolder(int cheatsFolder) {
    Settings::cheatsFolder = cheatsFolder;
}

int Config::getCheatsFolder() {
    return Settings::cheatsFolder;
}

// Screen Filter
void Config::setScreenFilter(int screenFilter) {
    Settings::screenFilter = screenFilter;
}

int Config::getScreenFilter() {
    return Settings::screenFilter;
}

// ARM7 HLE
void Config::setArm7Hle(int arm7Hle) {
    Settings::arm7Hle = arm7Hle;
}

int Config::getArm7Hle() {
    return Settings::arm7Hle;
}

// DSi Mode
void Config::setDsiMode(int dsiMode) {
    Settings::dsiMode = dsiMode;
}

int Config::getDsiMode() {
    return Settings::dsiMode;
}

// BIOS Paths
void Config::setBios9Path(const std::string& bios9Path) {
    Settings::bios9Path = bios9Path;
}

std::string Config::getBios9Path() {
    return Settings::bios9Path;
}

void Config::setBios7Path(const std::string& bios7Path) {
    Settings::bios7Path = bios7Path;
}

std::string Config::getBios7Path() {
    return Settings::bios7Path;
}

void Config::setFirmwarePath(const std::string& firmwarePath) {
    Settings::firmwarePath = firmwarePath;
}

std::string Config::getFirmwarePath() {
    return Settings::firmwarePath;
}

void Config::setGbaBiosPath(const std::string& gbaBiosPath) {
    Settings::gbaBiosPath = gbaBiosPath;
}

std::string Config::getGbaBiosPath() {
    return Settings::gbaBiosPath;
}

void Config::setSdImagePath(const std::string& sdImagePath) {
    Settings::sdImagePath = sdImagePath;
}

std::string Config::getSdImagePath() {
    return Settings::sdImagePath;
}

void Config::setBasePath(const std::string& basePath) {
    Settings::basePath = basePath;
}

std::string Config::getBasePath() {
    return Settings::basePath;
}

