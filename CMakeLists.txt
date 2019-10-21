cmake_minimum_required(VERSION 3.14)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)
set(SRC
        src/apply_flags.c
        src/data.c
        src/e_double_tool.c
        src/e_double.c
        src/f_double.c
        src/ft_printf.c
        src/int_funcions.c
        main.c
        src/parse.c
        src/parse_tool.c
        src/print_tool.c
        src/string_tool.c
        src/tools.c)
include_directories(
        includes)

include_directories(lib/libft/includes)
add_executable(ft_printf ${SRC})
add_subdirectory(lib/libft)
target_link_libraries(ft_printf libft)
