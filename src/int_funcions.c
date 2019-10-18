#include "ft_printf.h"

static int precision_zeroes(t_param *param, int len) {
    char precition[param->precision - len + 1];
    char *temp;
    int i;

    i = 0;
    if (param->precision > len) {
        param->line_size += param->precision - len;
        while (i < param->precision - len)
            precition[i++] = '0';
        precition[i] = 0;
        temp = ft_strjoin(param->str, precition);
        ft_memdel((void **) &param->str);
        param->str = temp;
    }
    param->line_size += len;
    return 1;
}

int ft_itoa_b(uintmax_t nbr, char *_base, t_param *param) {
    char str[64];
    char *temp;
    int len;
    int len_s;
    int base;

    base = ft_strlen(_base);
    len = ft_unbrlen(nbr, base);
    precision_zeroes(param, len);
    len_s = len;
    str[len] = 0;
    while (len--) {
        str[len] = _base[nbr % base];
        nbr /= base;
    }
    temp = ft_strjoin(param->str, str);
    ft_memdel((void **) &param->str);
    param->str = temp;
    param->line_size = ft_strlen(param->str);
    return (len_s);
}

int ft_itoa_u(uintmax_t nbr, t_param *param) {
    return ft_itoa_b(nbr, BASE_10, param);
}

int ft_itoa_p(intmax_t nbr, t_param *param) {

    if (nbr < 0) {
        param->sign = 1;
        nbr = -nbr;
    }
    return ft_itoa_b(nbr, BASE_10, param);
}