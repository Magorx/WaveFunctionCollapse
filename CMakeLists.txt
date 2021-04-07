cmake_minimum_required(VERSION 3.15)
project(WaveFunctionCollapse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(WARNING_FLAGS "-Wall -Wextra -Wno-multichar -Wno-unused-result")

include_directories(src)

set(CMAKE_EXE_LINKER_FLAGS "-pthread")
set(CMAKE_CXX_FLAGS_RELEASE  "-O3 ${WARNING_FLAGS} ")
set(CMAKE_CXX_FLAGS_DEBUG   "-g3 -O3 ${WARNING_FLAGS}")

find_package(SFML 2 COMPONENTS system window graphics network audio REQUIRED)

add_executable(persival
        src/main.cpp
        src/sample/sample.h
        src/sample/sample_set.h
        src/sample/sample_set.cpp
        src/color/color.h
        src/color/color_map.h
        src/color/color_map.cpp
        src/sample/tyle.h
        src/sample/tyle.cpp
        src/sample/collection_samples.h
        src/wfc.h
        src/wfc.cpp)

target_link_libraries(persival sfml-graphics sfml-window sfml-system)