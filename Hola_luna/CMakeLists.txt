cmake_minimum_required(VERSION 3.26)
project(Hola_luna)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hola_luna main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(Hola_luna PRIVATE box2d::box2d)