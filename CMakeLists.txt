cmake_minimum_required(VERSION 3.10)

project(tic-tac-toe)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tic-tac-toe
    src/board.cpp
    src/board.h
    src/game_state.h
    src/game.cpp
    src/game.h
    src/human_player.cpp
    src/human_player.h
    src/main.cpp
    src/mark.cpp
    src/mark.h
    src/minimax_player.cpp
    src/minimax_player.h
    src/move.cpp
    src/move.h
    src/player.cpp
    src/player.h
    src/random_player.cpp
    src/random_player.h
)
