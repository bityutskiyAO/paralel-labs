cmake_minimum_required(VERSION 3.15)
project(laba_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(laba_3 main.cpp SLAU.cpp SLAU.h SlauGenerator.cpp SlauGenerator.h)