cmake_minimum_required(VERSION 3.18)
project(CNDS)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

find_package(Python 3.8 COMPONENTS Interpreter Development.Module REQUIRED)

add_subdirectory(externals/nanobind)
add_subdirectory(externals/NooDS)

nanobind_add_module(cnds cnds/cnds.cpp cnds/nds.cpp cnds/nds_input.cpp cnds/nds_memory.cpp cnds/config.cpp)
target_include_directories(cnds PRIVATE cnds/include)
target_link_libraries(cnds PRIVATE NooDS)
