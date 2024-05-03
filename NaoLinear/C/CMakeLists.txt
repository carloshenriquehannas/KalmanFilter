cmake_minimum_required(VERSION 3.22)
project(NaoLinear C)

set(CMAKE_C_STANDARD 99)

add_executable(NaoLinear main.c initialize.c initialize.h FKE.c FKE.h)
