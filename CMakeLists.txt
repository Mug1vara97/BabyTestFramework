cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(test 
    src/main.cpp 
    src/TestRegistry.cpp)