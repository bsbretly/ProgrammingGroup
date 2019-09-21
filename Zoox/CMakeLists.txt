cmake_minimum_required(VERSION 3.12)
project(Zoox)

set(CMAKE_CXX_STANDARD 11)
#add_library(Calculator calculator.hpp)

include_directories ("${PROJECT_SOURCE_DIR}")

add_executable(Zoox main.cpp)
#target_link_libraries (Zoox calculator.hpp)