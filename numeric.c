#include "ft_printf.h"

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
    return ft_itoa_b(nbr, "0123456789", param);
}

int ft_itoa_p(intmax_t nbr, t_param *param) {

    if (nbr < 0) {
        param->sign = 1;
        nbr = -nbr;
    }
    return ft_itoa_b(nbr, "0123456789", param);
}

int ft_ceil(double nbr)
{
    int inbr;
    inbr= (int)nbr;
    if (nbr == (double)inbr)
        return inbr;
    return inbr + 1;
}

int ft_dtoa(long double nbr, t_param *param) {
    if (param->precision <= 0)
        param->precision = 6;

//    char *str;
    int max_len;

    int len;

    int i;
    int j;
 //   const uintmax_t mask = (long long int) (nbr);
    int in_main;

//    adr = (void*)(&nbr);
//    size = sizeof(nbr);
//    printf("size: %ld\n", size);
//    while (0 < size--) {
//        ft_printf("%08b ", ((unsigned char *) adr)[size]);
//
//    }
//    size = sizeof(nbr);
//    ft_printf("\n");
//    while (0 < size--) {
//        ft_printf("%02x       ", ((unsigned char *) adr)[size]);
//    }
//    ft_printf("\n");

    uintmax_t mantissa;
    intmax_t exponent;
    ft_memcpy(&mantissa, &nbr, sizeof(mantissa));
//    printf("cast long: %lu\n",(long)(nbr));
    ft_memcpy(&exponent, (void *) (&nbr) + sizeof(exponent), sizeof(exponent));
    param->sign = (exponent & 0x8000) >> 15;
//    printf("sign %d",param->sign);
    exponent &= 0x7fff;
//    printf("size mantissa: %ld\n", sizeof(exponent));

//    size = sizeof(mantissa);
//    adr = (void *) (&mantissa);
//    ft_printf("\nmantissa:\n");
//    while (0 < size--) {
//        ft_printf("%08b ", ((unsigned char *) adr)[size]);
//    }
//    size = sizeof(exponent);
//    adr = (void *) (&exponent);
//    ft_printf("\nexponent\n");
//    while (0 < size--) {
//        ft_printf("%08b ", ((unsigned char *) adr)[size]);
//    }

    len = ft_unbrlen(mantissa);
    i =  (int)(exponent) - (int)(1 << 14) - 62;
    int delta;
    delta  = len + ft_ceil(((double)i)*0.3010299956639812);
//    printf("\ndelta : %d",delta);
    max_len = param->precision + (delta > 0 ? delta: 0) + len + 1;
    char str[max_len + 1];
//    if (!(str = (char *) malloc(sizeof(*str) * max_len + 1)))
//        return 0;
    i = 0;
    while (i < max_len)
        str[i++] = 0;
    i = len + (delta > 0 ? delta: 0);
//    printf("\nmantisa : %lu\n ", mantissa);
    while (i--) {
        str[i] = mantissa % 10;
        mantissa /= 10;
    }
//    printf("\nexponent : %lu\n ", exponent);
    i =  (int)(exponent) - (int)(1 << 14) - 62;

//    printf("\ndelta : %f",delta);
//    printf("\ni: %d\n",i);
    if (i <= 0) {
        while (i++) {
            j = max_len - 1;
            if (str[j] % 2)
                str[j]++;
            str[j] /= 2;
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
                in_main = str[j] / 10;
                str[j] %= 10;
            }
            str[max_len - 1] /= 2;
        }
    }
    i = len - (delta < 0.0 ? 1:0);
    if (delta < 0)
        delta = 1;
    if ((int)nbr != 0 && str[i] == 0) {
        i++;
        delta--;
    }

    int k = 0;
    char ptr[max_len - i];

//    ptr = (char*)malloc(sizeof(*ptr)* max_len - i);

    i++;
    while (i < max_len - 1) {
       ptr[k++] = str[i++] + '0';
        if (--delta == 1)
            ptr[k++] = '.';
    }
    ptr[k] = 0;

    param->str = ft_strjoin(param->str, ptr);
    param->line_size = ft_strlen(ptr);
    return 1;
}
