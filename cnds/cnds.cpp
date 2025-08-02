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
        .def("read_ramu8", &Nds::readRamu8)
        .def("read_ramu16", &Nds::readRamu16)
        .def("read_ramu32", &Nds::readRamu32)
        .def("read_ramu64", &Nds::readRamu64)
        .def("read_rami8", &Nds::readRami8)
        .def("read_rami16", &Nds::readRami16)
        .def("read_rami32", &Nds::readRami32)
        .def("read_rami64", &Nds::readRami64)
        .def("read_ramf32", &Nds::readRamf32)
        .def("read_ramf64", &Nds::readRamf64)
        .def("read_map", &Nds::readMap)

        // Write memory methods
        .def("write_ramu8", &Nds::writeRamu8)
        .def("write_ramu16", &Nds::writeRamu16)
        .def("write_ramu32", &Nds::writeRamu32)
        .def("write_ramu64", &Nds::writeRamu64)
        .def("write_rami8", &Nds::writeRami8)
        .def("write_rami16", &Nds::writeRami16)
        .def("write_rami32", &Nds::writeRami32)
        .def("write_rami64", &Nds::writeRami64)
        .def("write_ramf32", &Nds::writeRamf32)
        .def("write_ramf64", &Nds::writeRamf64)
        .def("write_map", &Nds::writeMap);

    m.def("set_direct_boot", &Config::setDirectBoot, "Set direct boot mode");
    m.def("set_frame_skip", &Config::setFrameSkip, "Set frame skip value");
}
