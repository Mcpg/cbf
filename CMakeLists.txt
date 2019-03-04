cmake_minimum_required(VERSION 2.6)
project(cbf C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES src/*.c)
include_directories(src)
add_executable(cbf ${SOURCES})
