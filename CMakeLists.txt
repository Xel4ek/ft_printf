project(libftprintf)

set (CMAKE_C_FLAGS_RELEASE "-Wall -O2 ${CMAKE_C_FLAGS_RELEASE}")

set(SRC
        src/apply_flags.c
        src/data.c
        src/e_double.c
        src/e_double_tool.c
        src/f_double.c
        src/ft_printf.c
        src/int_funcions.c
        src/parse.c
        src/parse_tool.c
        src/print_tool.c
        src/string_tool.c
        src/tools.c
)
set(HEADERS
        ../libft/includes/libft.h
        includes/ft_printf.h)

include_directories(../libft)


add_library(libftprintf STATIC ${SRC} ${HEADERS})

target_link_libraries(libftprintf libft)
target_include_directories(libftprintf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})