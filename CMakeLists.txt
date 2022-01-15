cmake_minimum_required(VERSION 2.8.12)
project(headtable)

add_definitions("-std=c++11 -O3 -mtune=native -march=native -Wall")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(headtable headtable.cpp)
target_link_libraries(headtable ${CONAN_LIBS})
