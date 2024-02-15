cmake_minimum_required(VERSION 3.10)

project(tic-tac-toe)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tic-tac-toe
    src/board.cpp
    src/board.h
    src/invalid_move_exception.cpp
    src/invalid_move_exception.h
    src/main.cpp
    src/mark.h
    src/move.cpp
    src/move.h
    src/player.cpp
    src/player.h
)
