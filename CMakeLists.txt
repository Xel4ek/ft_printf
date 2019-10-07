cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)
set(SRC
        ft_printf.c
        main.c
        numeric.c
        parse.c
        print_tool.c
        tools.c)
set(HEADERS
        ft_printf.h)

include_directories(lib/libft/includes)
add_executable(ft_printf ${SRC})
add_subdirectory(lib/libft)
target_link_libraries(ft_printf libft)
