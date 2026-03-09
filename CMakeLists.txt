cmake_minimum_required(VERSION 3.20)
project(ekf LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(ekf STATIC 
    src/ekf.cpp 
    src/ekf.hpp
)

find_package(Eigen3 REQUIRED)

target_include_directories(ekf PUBLIC src)
target_link_libraries(ekf PUBLIC Eigen3::Eigen)