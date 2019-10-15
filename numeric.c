#include "ft_printf.h"


int ft_ceil(double nbr)
{
    int inbr;
    if (nbr - (inbr = (int)nbr) > .0)
        return inbr + 1;
    return inbr;
}

int nbr_length(intmax_t nbr, int base) {
    int len;

    len = 1;
    while (nbr /= base)
        len++;
    return len;
}

int nbr_length_u(uintmax_t nbr, int base) {
    int len;

    len = 1;
    while (nbr /= base)
        len++;
    return len;
}

int precision_zeroes(t_param *param, int len)
{
    char precition[param->precision - len + 1];
    int i;

    i = 0;
    if (param->precision > len) {
        param->line_size += param->precision - len;
        while (i < param->precision - len)
            precition[i++] = '0';
        precition[i] = 0;
        param->str = ft_strjoin(param->str, precition);
    }
    param->line_size += len;
    return 1;
}

int ft_itoa_b(uintmax_t nbr, char *_base, t_param *param) {
    char str[64];
    int len;
    int len_s;
    int base;

    base = ft_strlen(_base);
    len = nbr_length_u(nbr, base);
    precision_zeroes(param, len);
    len_s = len;
    str[len] = 0;
    while (len--) {
        str[len] = _base[nbr % base];
        nbr /= base;
    }
    param->str = ft_strjoin(param->str, str);
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

int ft_dtoa(long double nbr, t_param *param) {
    if (param->precision < 0)
        param->precision = 6;
    int max_len;
    int len;
    int i;
    int j;
    int in_main;
    uintmax_t mantissa;
    intmax_t exponent;
    ft_memcpy(&mantissa, &nbr, sizeof(mantissa));
    ft_memcpy(&exponent, (void *) (&nbr) + sizeof(mantissa), sizeof(exponent));
    param->sign = (exponent & 0x8000) >> 15;
    exponent &= 0x7fff;
    len = 20;// ft_unbrlen(mantissa);
    i =  (int)(exponent) - (int)(1 << 14) - 62;
    int delta;
    delta  = ceil(len + ((double)i) * LOG2);
    int power = delta - 2;
    max_len = param->precision + (power > 0 ? power : 0) + len + 1;
    char str[max_len + 1];
    i = 0;
    while (i < max_len)
        str[i++] = 0;
    i = len + (power > 0 ? power: 0);
    while (i--) {
        str[i] = mantissa % 10;
        mantissa /= 10;
    }
    i =  (int)(exponent) - (int)(1 << 14) - 62;
   if (i <= 0) {
        while (i++) {
            j = max_len;
            while (j--) {
                str[j + 1] += (str[j] % 2) * 5;
                str[j] /= 2;
                if (str[j + 1] > 9) {
                    str[j + 1] %= 10;
                    str[j] += 1;
                }
            }
          }
        if (str[max_len- 1] > 4)
            str[max_len - 2]++;
    } else {
        while (i--) {
            j = max_len;
            in_main = 0;
            while (j-- > 0) {
                str[j] = 2 * str[j] + in_main;
                in_main = str[j] / 10;
                str[j] %= 10;
            }
        }
    }
    i = len - 1;// - (delta < 0.0 ? 1:0);
    if ((int)nbr != 0 && str[i] == 0) {
        i++;
        delta--;
    }
    if (delta < 2)
        delta = 2;
    int k = 0;
    char ptr[max_len - i + 1];
    while (i < max_len  - 1){//  (power > 0 ? 2 : 0)){ //- power == 1 ? 1 : 0) {
        ptr[k++] = str[i++] + '0';
        if (--delta == 1)
            ptr[k++] = '.';
    }
    ptr[k] = 0;

    param->str = ft_strjoin(param->str, ptr);
    param->line_size = ft_strlen(ptr);
    return 1;
}

int ft_dtoa_save(long double nbr, t_param *param) {
    if (param->precision < 0)
        param->precision = 6;
    int max_len;
    int len;
    int i;
    int j;
    int in_main;
    uintmax_t mantissa;
    intmax_t exponent;
    ft_memcpy(&mantissa, &nbr, sizeof(mantissa));
    ft_memcpy(&exponent, (void *) (&nbr) + sizeof(mantissa), sizeof(exponent));
    param->sign = (exponent & 0x8000) >> 15;
    exponent &= 0x7fff;
    len = 20;// ft_unbrlen(mantissa);
    i =  (int)(exponent) - (int)(1 << 14) - 62;
    int delta;
    delta  = ceil(len + ((double)i) * LOG2);
    int power = delta - 2;
    max_len = param->precision + (power > 0 ? power : 0) + len + 1;
    char str[max_len + 1];
    i = 0;
    while (i < max_len)
        str[i++] = 0;
    i = len + (power > 0 ? power: 0);
    while (i--) {
        str[i] = mantissa % 10;
        mantissa /= 10;
    }
    i =  (int)(exponent) - (int)(1 << 14) - 62;
    if (i <= 0) {
        while (i++) {
            j = max_len;
            while (j--) {
                str[j + 1] += (str[j] % 2) * 5;
                str[j] /= 2;
                if (str[j + 1] > 9) {
                    str[j + 1] %= 10;
                    str[j] += 1;
                }
            }
        }
        if (str[max_len- 1] > 4)
            str[max_len - 2]++;
    } else {
        while (i--) {
            j = max_len;
            in_main = 0;
            while (j-- > 0) {
                str[j] = 2 * str[j] + in_main;
                in_main = str[j] / 10;
                str[j] %= 10;
            }
        }
    }
    i = len - 1;// - (delta < 0.0 ? 1:0);
    if ((int)nbr != 0 && str[i] == 0) {
        i++;
        delta--;
    }
    if (delta < 2)
        delta = 2;
    int k = 0;
    char ptr[max_len - i + 1];
    while (i < max_len  - 1){//  (power > 0 ? 2 : 0)){ //- power == 1 ? 1 : 0) {
        ptr[k++] = str[i++] + '0';
        if (--delta == 1)
            ptr[k++] = '.';
    }
    ptr[k] = 0;

    param->str = ft_strjoin(param->str, ptr);
    param->line_size = ft_strlen(ptr);
    return 1;
}
int ft_dtoa_e(long double nbr, t_param *param) {
    if (param->precision < 0)
        param->precision = 6;

    int max_len;
    int len;
    int i;
    int j;
    int in_main;
    uintmax_t mantissa;
    intmax_t exponent;
    ft_memcpy(&mantissa, &nbr, sizeof(mantissa));
    ft_memcpy(&exponent, (void *) (&nbr) + sizeof(mantissa), sizeof(exponent));
    param->sign = (exponent & 0x8000) >> 15;
    exponent &= 0x7fff;
    len = 20;//ft_unbrlen(mantissa);
    i =  (int)(exponent) - (int)(1 << 14) - 62;
    int delta;
    delta  = ft_ceil((long double)len + ((long double)i) * LOG2);
    int power = delta - 2;
//    printf("\npower: %d\n",power);
    max_len = param->precision + abs(power) + len;// - (power < 0 ? power : 0);
    char str[max_len + 1];
    i = 0;
    while (i < max_len)
        str[i++] = 0;
    i = len + (power > 0 ? power: 0);
    while (i--) {
        str[i] = mantissa % 10;
        mantissa /= 10;
    }
    i =  (int)(exponent) - (int)(1 << 14) - 62;
    if (i <= 0) {
        while (i++) {
            j = max_len;
            while (j--) {
                str[j + 1] += (str[j] % 2) * 5;
                str[j] /= 2;
                if (str[j + 1] > 9) {
                    str[j + 1] %= 10;
                    str[j] += 1;
                }
            }
        }
    } else {
        while (i--) {
            j = max_len;
            in_main = 0;
            while (j-- > 0) {
                str[j] = 2 * str[j] + in_main;
                if (i == 0 && j == param->precision + len - 1)// (power >= 0 ? 2 : 0) - 1)
                    if (str[j + 1] > 5)
                        str[j]++;
                in_main = str[j] / 10;
                str[j] %= 10;
            }
        }
    }
    i = len - 1;// - (delta < 1.0 ? 1:0);
    if ((int)nbr != 0 && str[i] == 0) {
        i++;
    }
        delta = 1;
    int k = 0;
    char ptr[max_len - i + 7];
    while (i < param->precision + len){//  (power > 0 ? 2 : 0)){ //- power == 1 ? 1 : 0) {
        ptr[k++] = str[i++ - (power < 0 ? power : 0)] + '0';
        if (--delta == 0)
            ptr[k++] = '.';
    }
    ptr[k] = 0;
    param->str = ft_strjoin(param->str, ptr);
    if (power >= 0)
        param->str = ft_strjoin(param->str, "e+");
    else
        param->str = ft_strjoin(param->str, "e-");
    if (ft_nbrlen(power) == 1)
        param->str = ft_strjoin(param->str, "0");
    param->str = ft_strjoin(param->str, ft_itoa(abs(power)));
    param->line_size = ft_strlen( param->str);
    return 1;
}
