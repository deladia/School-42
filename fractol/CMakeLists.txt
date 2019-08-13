#cmake_minimum_required(VERSION 3.14)
#project(fractol C)
#
#set(CMAKE_C_STANDARD 99)
##set(MLX_INCLUDE_DIR /usr/local/include)
##set(MLX_LIBRARY /usr/local/lib)
##find_package(LIBMLX REQUIRED)
##find_package(OpenGL REQUIRED)
#find_library(AppKit AppKit)
#find_library(OpenGL OpenGL)
#find_library(MLX MLX)
#target_link_libraries(${AppKit}
#        ${OpenGL})
#find_library(AppKit AppKit)
#add_executable(fractol main.c fractol.h /usr/local/include/mlx.h /usr/local/lib/libmlx.a -framework OpenGL -framework AppKit)
#target_include_directories(fractol PUBLIC /usr/local/include/)
#TARGET_LINK_LIBRARIES(fractol /usr/local/lib/)

cmake_minimum_required(VERSION 3.14)
project(fractol C)

set(CMAKE_C_STANDARD 99)

include_directories(./libft/includes)
FILE(GLOB LIBFT_SRCS ./libft/*.c)

find_library(OPEN_GL OpenGl)
find_library(OPEN_CL OpenCl)
find_library(APP_KIT AppKit)
link_libraries(mlx)


add_executable(fractol main.c fractol.h ${LIBFT_SRCS} create_cl.c)

target_link_libraries(fractol ${OPEN_GL} ${APP_KIT} ${OPEN_CL})