#include "config.hpp"


void Config::setDirectBoot(bool directBoot) {
    Settings::directBoot = directBoot;
}

void Config::setFrameSkip(int frameSkip) {
    Settings::frameskip = frameSkip;
}
