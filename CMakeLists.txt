cmake_minimum_required(VERSION 3.10)

project(tic-tac-toe)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tic-tac-toe
    src/main.cpp
    src/player.cpp
    src/player.h
)
