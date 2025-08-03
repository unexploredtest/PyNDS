#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include "noods.h"
#include "nds.hpp"
#include "config.hpp"

namespace nb = nanobind;

NB_MODULE(cnds, m) {
    nb::class_<Nds>(m, "Nds")
        .def(nb::init<const std::string&, bool>())
        .def("run_task", &Nds::runTask)
        .def("run_until_frame", &Nds::runUntilFrame)
        .def("get_frame", &Nds::getFrame)
        .def("get_gba_frame", &Nds::getGbaFrame)
        .def("get_top_nds_frame", &Nds::getTopNdsFrame)
        .def("get_bot_nds_frame", &Nds::getBotNdsFrame)

        // Input methods
        .def("set_touch_input", &Nds::setTouchInput)
        .def("clear_touch_input", &Nds::clearTouchInput)
        .def("save_state", &Nds::saveState)
        .def("load_state", &Nds::loadState)
        .def("touch_input", &Nds::touchInput)
        .def("release_touch_input", &Nds::releaseTouchInput)
        .def("press_key", &Nds::pressKey)
        .def("release_key", &Nds::releaseKey)

        // Read memory methods
        .def("read_ram_u8", &Nds::readRamu8)
        .def("read_ram_u16", &Nds::readRamu16)
        .def("read_ram_u32", &Nds::readRamu32)
        .def("read_ram_u64", &Nds::readRamu64)
        .def("read_ram_i8", &Nds::readRami8)
        .def("read_ram_i16", &Nds::readRami16)
        .def("read_ram_i32", &Nds::readRami32)
        .def("read_ram_i64", &Nds::readRami64)
        .def("read_ram_f32", &Nds::readRamf32)
        .def("read_ram_f64", &Nds::readRamf64)
        .def("read_map", &Nds::readMap)

        // Write memory methods
        .def("write_ram_u8", &Nds::writeRamu8)
        .def("write_ram_u16", &Nds::writeRamu16)
        .def("write_ram_u32", &Nds::writeRamu32)
        .def("write_ram_u64", &Nds::writeRamu64)
        .def("write_ram_i8", &Nds::writeRami8)
        .def("write_ram_i16", &Nds::writeRami16)
        .def("write_ram_i32", &Nds::writeRami32)
        .def("write_ram_i64", &Nds::writeRami64)
        .def("write_ram_f32", &Nds::writeRamf32)
        .def("write_ram_f64", &Nds::writeRamf64)
        .def("write_map", &Nds::writeMap);

    nb::class_<Config>(m, "config")
        .def_static("set_direct_boot", &Config::setDirectBoot, "Set direct boot mode")
        .def_static("get_direct_boot", &Config::getDirectBoot, "Get direct boot mode")

        .def_static("set_rom_in_ram", &Config::setRomInRam, "Set ROM in RAM")
        .def_static("get_rom_in_ram", &Config::getRomInRam, "Get ROM in RAM")

        .def_static("set_fps_limiter", &Config::setFpsLimiter, "Set FPS limiter")
        .def_static("get_fps_limiter", &Config::getFpsLimiter, "Get FPS limiter")

        .def_static("set_frame_skip", &Config::setFrameSkip, "Set frame skip value")
        .def_static("get_frame_skip", &Config::getFrameSkip, "Get frame skip value")

        .def_static("set_threaded_2d", &Config::setThreaded2D, "Set threaded 2D rendering")
        .def_static("get_threaded_2d", &Config::getThreaded2D, "Get threaded 2D rendering status")

        .def_static("set_threaded_3d", &Config::setThreaded3D, "Set threaded 3D rendering")
        .def_static("get_threaded_3d", &Config::getThreaded3D, "Get threaded 3D rendering status")

        .def_static("set_high_res_3d", &Config::setHighRes3D, "Set high resolution 3D")
        .def_static("get_high_res_3d", &Config::getHighRes3D, "Get high resolution 3D status")

        .def_static("set_screen_ghost", &Config::setScreenGhost, "Set screen ghosting")
        .def_static("get_screen_ghost", &Config::getScreenGhost, "Get screen ghosting status")

        .def_static("set_emulate_audio", &Config::setEmulateAudio, "Set audio emulation")
        .def_static("get_emulate_audio", &Config::getEmulateAudio, "Get audio emulation status")

        .def_static("set_audio_16_bit", &Config::setAudio16Bit, "Set 16-bit audio")
        .def_static("get_audio_16_bit", &Config::getAudio16Bit, "Get 16-bit audio status")

        .def_static("set_saves_folder", &Config::setSavesFolder, "Set saves folder")
        .def_static("get_saves_folder", &Config::getSavesFolder, "Get saves folder")

        .def_static("set_states_folder", &Config::setStatesFolder, "Set states folder")
        .def_static("get_states_folder", &Config::getStatesFolder, "Get states folder")

        .def_static("set_cheats_folder", &Config::setCheatsFolder, "Set cheats folder")
        .def_static("get_cheats_folder", &Config::getCheatsFolder, "Get cheats folder")

        .def_static("set_screen_filter", &Config::setScreenFilter, "Set screen filter")
        .def_static("get_screen_filter", &Config::getScreenFilter, "Get screen filter")

        .def_static("set_arm7_hle", &Config::setArm7Hle, "Set ARM7 HLE")
        .def_static("get_arm7_hle", &Config::getArm7Hle, "Get ARM7 HLE status")

        .def_static("set_dsi_mode", &Config::setDsiMode, "Set DSi mode")
        .def_static("get_dsi_mode", &Config::getDsiMode, "Get DSi mode")

        .def_static("set_bios_9_path", &Config::setBios9Path, "Set BIOS 9 path")
        .def_static("get_bios_9_path", &Config::getBios9Path, "Get BIOS 9 path")

        .def_static("set_bios_7_path", &Config::setBios7Path, "Set BIOS 7 path")
        .def_static("get_bios_7_path", &Config::getBios7Path, "Get BIOS 7 path")

        .def_static("set_firmware_path", &Config::setFirmwarePath, "Set firmware path")
        .def_static("get_firmware_path", &Config::getFirmwarePath, "Get firmware path")

        .def_static("set_gba_bios_path", &Config::setGbaBiosPath, "Set GBA BIOS path")
        .def_static("get_gba_bios_path", &Config::getGbaBiosPath, "Get GBA BIOS path");
}
