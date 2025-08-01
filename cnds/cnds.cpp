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
        .def("set_touch_input", &Nds::setTouchInput)
        .def("clear_touch_input", &Nds::clearTouchInput)
        .def("touch_input", &Nds::touchInput)
        .def("release_touch_input", &Nds::releaseTouchInput)
        .def("press_key", &Nds::pressKey)
        .def("release_key", &Nds::releaseKey);


    m.def("set_direct_boot", &Config::setDirectBoot, "Set direct boot mode");
    m.def("set_frame_skip", &Config::setFrameSkip, "Set frame skip value");
}
