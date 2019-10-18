#include "ft_printf.h"

int calculate_number_e(char *str, int max_len, intmax_t exponent) {
    int i;
    int count = 0;

    i = (int) (exponent) - (int) (1 << 14) - 62;
    if (i < 0) {
        while (i++) {
            count += shift_string(str, max_len + 1);
            division_two_e(str, max_len);
        }
    } else
        while (i--) {
            count += shift_string(str, max_len + 1);
            multiply_two(str, max_len);
        }
    return count;
}

int round_e_nbr(t_param *param, char *string, int max_len, int shift) {
    int j;

    j = max_len;
    shift += shift_string(string, max_len);
    while (j--) {
        if (j == param->precision + 4)
            if (string[j] > 4)
                string[j - 1]++;
        if (string[j] > 9) {
            string[j - 1]++;
            string[j] %= 10;
        }
    }
    return (-shift - shift_string(string, max_len) + param->precision + 16);
}

void write_rezult_e(t_param *param, char *str, int max_len, int shift) {
    int i;
    int delta;
    int k;
    char ptr[max_len - BASE_NBR_LEN + 8];
    char *temp;

    i = 3;
    delta = 1;
    k = 0;
    shift = round_e_nbr(param, str, max_len, shift);
    while (i < param->precision + 4) {
        ptr[k++] = str[i++] + '0';
        if (--delta == 0)
            ptr[k++] = '.';
    }
    ptr[k] = 0;
    temp = ft_strjoin(param->str, ptr);
    ft_memdel((void **) &param->str);
    param->str = temp;
    param->line_size = ft_strlen(param->str);
    add_exponent(param, shift);
}

void ft_dtoa_e_helper(t_param *param, int max_len, uintmax_t mantissa, intmax_t exponent) {
    int i;
    char str[max_len + 1];
    int shift;

    i = max_len;
    while (i--) {
        str[i] = mantissa % 10;
        mantissa /= 10;
    }
    shift = calculate_number_e(str, max_len, exponent);
    write_rezult_e(param, str, max_len, shift);
}

int ft_dtoa_e(long double nbr, t_param *param) {
    int max_len;
    uintmax_t mantissa;
    intmax_t exponent;

    if (param->precision < 0)
        param->precision = DEFAULT_PRECISION;
    ft_memcpy(&mantissa, &nbr, sizeof(mantissa));
    ft_memcpy(&exponent, (void *) (&nbr) + sizeof(mantissa), sizeof(exponent));
    param->sign = (exponent & 0x8000) >> 15;
    exponent &= 0x7fff;
    max_len = param->precision + BASE_NBR_LEN;
    ft_dtoa_e_helper(param, max_len, mantissa, exponent);
    return 1;
}
