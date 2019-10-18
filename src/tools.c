#include "ft_printf.h"
#include <stdlib.h>

int string_convertation(t_param *param){
    if (param->type == '%')
        return ft_getchar('%', param);
    if (param->type == 'c')
        return ft_getchar((char) va_arg(param->ap, int), param);
    if (param->type == 's')
        return (ft_getstr(va_arg(param->ap, char*), param));
    if (param->type == 'r')
        return (raw_string(va_arg(param->ap, char*), param));
    if (param->type == 'k')
        return (data_print(va_arg(param->ap, char*), param));
    return -1;
}

int double_convertation(t_param *param){
    if (param->type == 'f') {
        if (param->length == 'l' || param->length == 0)
            return ft_dtoa((long double) va_arg(param->ap, double), param);
        if (param->length == 'L')
            return ft_dtoa((long double) va_arg(param->ap, long double), param);
    }
    if (param->type == 'e') {
        if (param->length == 'l' || param->length == 0)
            return ft_dtoa_e((long double) va_arg(param->ap, double), param);
        if (param->length == 'L')
            return ft_dtoa_e((long double) va_arg(param->ap, long double), param);
    }
    return -1;
}

int ten_base_int(t_param *param)
{
    if (param->type == 'd' || param->type == 'i') {
        if (param->length == 'h' + 'h')
            return (ft_itoa_p((char) va_arg(param->ap, int), param));
        if (param->length == 'h')
            return (ft_itoa_p((short int) va_arg(param->ap, int), param));
        if (param->length == 0)
            return (ft_itoa_p((int) va_arg(param->ap, int), param));
        if (param->length == 'l')
            return (ft_itoa_p((long int) va_arg(param->ap, long int), param));
        if (param->length == 'l' + 'l')
            return (ft_itoa_p((long long int) va_arg(param->ap, long long int), param));
        if (param->length == 'z' || param->length == 't')
            return (ft_itoa_p((size_t) va_arg(param->ap, size_t), param));
    }
    if (param->type == 'u') {
        if (param->length == 'h' + 'h')
            return (ft_itoa_u((unsigned char) va_arg(param->ap, unsigned int), param));
        if (param->length == 'h')
            return (ft_itoa_u((unsigned short int) va_arg(param->ap, unsigned int), param));
        if (param->length == 0)
            return (ft_itoa_u((unsigned int) va_arg(param->ap, unsigned int), param));
        if (param->length == 'l')
            return (ft_itoa_u((unsigned long) va_arg(param->ap, uintmax_t), param));
        if (param->length == 'l' + 'l')
            return (ft_itoa_u((uintmax_t) va_arg(param->ap, uintmax_t), param));
        if (param->length == 'z' || param->length == 't')
            return (ft_itoa_u((size_t) va_arg(param->ap, size_t), param));
    }
    return -1;
}
int hex_base_int(t_param *param)
{
    if (param->type == 'X') {
        if (param->length == 'h' + 'h')
            return (ft_itoa_b((unsigned char) va_arg(param->ap, unsigned int), BASE_16u, param));
        if (param->length == 'h')
            return (ft_itoa_b((unsigned short int) va_arg(param->ap, unsigned int), BASE_16u, param));
        if (param->length == 'l')
            return (ft_itoa_b((uintmax_t) va_arg(param->ap, unsigned long int), BASE_16u, param));
        if (param->length == 'l' + 'l')
            return (ft_itoa_b((uintmax_t) va_arg(param->ap, uintmax_t), BASE_16u, param));
        return (ft_itoa_b((uintmax_t) va_arg(param->ap, unsigned int), BASE_16u, param));
    }
    if (param->type == 'x') {
        if (param->length == 'h' + 'h')
            return (ft_itoa_b((unsigned char) va_arg(param->ap, unsigned int), BASE_16l, param));
        if (param->length == 'h')
            return (ft_itoa_b((unsigned short int) va_arg(param->ap, unsigned int), BASE_16l, param));
        if (param->length == 'l')
            return (ft_itoa_b((uintmax_t) va_arg(param->ap, unsigned long int), BASE_16l, param));
        if (param->length == 'l' + 'l')
            return (ft_itoa_b((uintmax_t) va_arg(param->ap, uintmax_t), BASE_16l, param));
        return (ft_itoa_b((uintmax_t) va_arg(param->ap, unsigned int), BASE_16l, param));
    }
    return -1;
}

int other_base_int(t_param *param)
{
    if (param->type == 'p') {
        return (ft_itoa_b((size_t) va_arg(param->ap, size_t), BASE_16l, param));
    }
    if (param->type == 'o') {
        if (param->length == 'h' + 'h')
            return (ft_itoa_b((unsigned char) va_arg(param->ap, int), BASE_8, param));
        if (param->length == 'h')
            return (ft_itoa_b((unsigned short int) va_arg(param->ap, int), BASE_8, param));
        if (param->length == 0)
            return (ft_itoa_b((unsigned int) va_arg(param->ap, int), BASE_8, param));
        return (ft_itoa_b((uintmax_t) va_arg(param->ap, uintmax_t), BASE_8, param));
    }
    if (param->type == 'b') {
        return (ft_itoa_b((uintmax_t) va_arg(param->ap, intmax_t), "01", param));
    }
}
