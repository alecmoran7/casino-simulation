cmake_minimum_required(VERSION 3.21)
project(casino_simulation)

set(CMAKE_CXX_STANDARD 14)

include_directories(programs/cpp_version/craps/oop_version)

add_executable(casino_simulation
        programs/cpp_version/craps/oop_version/Dice.cc
        programs/cpp_version/craps/oop_version/Dice.h
        programs/cpp_version/craps/oop_version/Game.h programs/cpp_version/craps/oop_version/Game.cc programs/cpp_version/craps/oop_version/Player.h programs/cpp_version/craps/oop_version/Player.cc programs/cpp_version/craps/oop_version/Datapool.h programs/cpp_version/craps/oop_version/Datapool.cc programs/cpp_version/craps/oop_version/main.cc)
