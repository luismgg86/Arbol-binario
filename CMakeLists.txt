cmake_minimum_required(VERSION 2.8.9)
project(ArbolB)

include_directories(include)

set(SOURCES src/NodoA.cpp src/ArbolB.cpp src/main.cpp)

add_executable(ArbolB ${SOURCES})
