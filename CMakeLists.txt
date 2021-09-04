cmake_minimum_required(VERSION 3.15)
project(RecursiveTTT)

set(CMAKE_CXX_STANDARD 14)

add_executable(RecursiveTTT main.cpp Board.hpp Board.cpp RecursiveBoard.hpp RecursiveBoard.cpp)