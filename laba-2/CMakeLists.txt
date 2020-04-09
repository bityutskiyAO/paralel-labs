cmake_minimum_required(VERSION 3.15)
project(laba_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(laba_2 main.cpp vector/operations/ParallelVectorOperations.h vector/operations/ParallelVectorOperations.cpp matrix/operations/ParallelMatrixOperations.h matrix/operations/ParallelMatrixOperations.cpp)