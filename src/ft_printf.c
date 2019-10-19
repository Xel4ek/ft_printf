#include "ft_printf.h"

int ft_printf(const char *format, ...) {
    char *ptr;
    int printed;
    t_param param;

    printed = 0;
    va_start(param.ap, format);
    ptr = (char *) format;
    while (*ptr) {
        while (*ptr != '%' && *ptr) {
            ft_putchar(*ptr++);
            printed++;
        }
        if (*ptr) {
            if (get_param(&param, &ptr)) {
				get_item(&param);
				apply_flags(&param);
				printed += param.line_size;
				ft_putstring(1, param.str, param.line_size);
				ft_memdel((void **) &param.str);
			}
        }
    }
    va_end (param.ap);
    return (printed);
}

int ft_printf_fd(const int fd, const char *format, ...) {
    char *ptr;
    int printed;
    t_param param;

    printed = 0;
    va_start(param.ap, format);
    ptr = (char *) format;
    while (*ptr) {
        while (*ptr != '%' && *ptr) {
            ft_putchar_fd(*ptr++, fd);
            printed++;
        }
        if (*ptr) {
            if (get_param(&param, &ptr)) {
				get_item(&param);
				apply_flags(&param);
				printed += param.line_size;
				ft_putstring(fd, param.str, param.line_size);
				ft_memdel((void **) &param.str);
			}
        }
    }
    va_end (param.ap);
    return (printed);
}

