cmake_minimum_required(VERSION 3.0)

project(Poker-Game VERSION 1.0)

# C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Code includes
add_subdirectory("Source")

# Add exe
add_executable(Example "Source/Main.cpp")