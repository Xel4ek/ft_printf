#include "ft_printf.h"

int get_flag(const char *str, t_flag *flag) {

    if (*str == '-')
        flag->minus = 1;
    else if (*str == '+')
        flag->plus = 1;
    else if (*str == '0')
        flag->zero = 1;
    else if (*str == ' ')
        flag->space = 1;
    else if (*str == '#')
        flag->hash = 1;
    else
        return (0);
    return (1);
}

int get_width(char *str, t_param *param) {
    int width;
    int next;

    next = 0;
    if (*str == '*') {
        str++;
        width = va_arg(param->ap, int);
        if (width < 0) {
            param->flag.minus = 1;
            param->width = -width;
        } else
            param->width = width;
        next = 1;
    }
    if ((width = ft_atoi(str))) {
        param->width = width;
        next = param->width ? ft_nbrlen(param->width) : 0;
    }
    return (next);
}

int get_precision(char **str, t_param *param) {
    int tmp;

    if (**str == '.') {
        (*str)++;
        if (**str == '*') {
            (*str)++;
            tmp = (int) va_arg(param->ap, int);
            return (tmp < 0 ? -1 : tmp);
        }
        tmp = (ft_atoi(*str));
        while (**str >= '0' && **str <= '9')
            (*str)++;
        return tmp;
    }
    return (-1);
}

unsigned char get_length(const char *str) {
    if (*str == 'h') {
        if (*(str + 1) == 'h')
            return ('h' + 'h');
        return ('h');
    }
    if (*str == 'l') {
        if (*(str + 1) == 'l')
            return ('l' + 'l');
        return ('l');
    }
    if (*str == 'L')
        return ('L');
    if (*str == 'z')
        return ('z');
    if (*str == 't')
        return ('t');
    return (0);
}

unsigned char get_type(const char *str) {
    if (*str == '%' || *str == 'd' || *str == 'i' || *str == 'u' ||
        *str == 'c' || *str == 's' || *str == 'p' || *str == 'x' ||
        *str == 'X' || *str == 'f' || *str == 'o' || *str == 'b' ||
        *str == 'e' || *str == 'k' || *str == 'r')
        return (*(unsigned char *) str);
    return (0);
}