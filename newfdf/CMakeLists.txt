cmake_minimum_required(VERSION 3.14)
project(newfdf C)

set(CMAKE_C_STANDARD 99)

add_executable(newfdf fdf.h main.c draw_line.c draw_map.c read_map.c)