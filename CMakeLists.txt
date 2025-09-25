cmake_minimum_required(VERSION 4.1)
project(upm)

set(CMAKE_CXX_STANDARD 26)

find_package(CURL REQUIRED)

add_executable(upm src/main.cpp
        src/download.cpp
        src/args.cpp
        src/args.h)

target_link_libraries(upm ${CURL_LIBRARIES})