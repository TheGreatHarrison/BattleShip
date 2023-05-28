cmake_minimum_required(VERSION 3.13)

project(battleship)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/Boat.cpp)

add_executable(simple_example ${SOURCE_FILES})