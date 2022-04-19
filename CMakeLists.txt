cmake_minimum_required(VERSION 3.17)
project(MIPROYECTOMP C)

set(CMAKE_C_STANDARD 99)

add_executable(MIPROYECTOMP main.c lib/core.h lib/core.c  lib/administrador.c lib/administrador.h)
