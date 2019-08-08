cmake_minimum_required(VERSION 3.8)
project(Euler236)

set(CMAKE_CXX_STANDARD 11)

#find_package(Eigen3)

set(SOURCE_FILES main.cpp)
add_executable(Euler236 ${SOURCE_FILES})

#target_include_directories(Euler236 PUBLIC ${EIGEN3_INCLUDE_DIR})