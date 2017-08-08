cmake_minimum_required(VERSION 3.8)
project(arduino_send)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(arduino_send ${SOURCE_FILES})