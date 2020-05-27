cmake_minimum_required(VERSION 3.15)
project(laba5)

set(CMAKE_CXX_STANDARD 14)

add_executable(laba5 main.cpp ThreadSaveVector.cpp ThreadSaveVector.h ThreadSaveStack.h ThreadSaveStack.cpp ThreadSaveQueue.cpp ThreadSaveQueue.h)