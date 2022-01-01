cmake_minimum_required(VERSION 3.21)
project(casino_simulation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(casino_simulation
        Dice.cc
        Dice.h
        Game.h Game.cc Player.h Player.cc Datapool.h Datapool.cc main.cc)
