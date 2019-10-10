#include "ft_printf.h"

int nbr_length(intmax_t nbr, int base) {
    int len;

    len = 1;
    while (nbr /= base)
        len++;
    return len;
}

//int ft_strlen(const char *str)
//{
//	int count;
//
//	count =0;
//	while (*str++)
//		count++;
//	return count;
//}

int ft_itoa_x(uintmax_t nbr, char *_base) {
    void *adr;
    int i;
    int base = 16;
    int flag;
    char put;
    size_t size;
    flag = 0;
    adr = (void *) (&nbr);
    size = sizeof(nbr);
    int count;

    count = 0;

//	printf("%p\n",&nbr);
//	void *tmp;
//	tmp=(void*)(&nbr);
//	adr = (void*)(&tmp);
//	size = sizeof(&tmp);
//	ft_putstr("0x");
    if (nbr)
        while (size--) {
            if ((put = _base[((unsigned char *) adr)[size] / base]) != '0' || flag) {
                ft_putchar(put);
                flag = 1;
                count++;
            }
            if ((put = _base[((unsigned char *) adr)[size] % base]) != '0' || flag) {
                ft_putchar(put);
                flag = 1;
                count++;
            }
        }
    else
        return 1;
    return (count);
}

int ft_itoa_b(uintmax_t nbr, char *_base, t_param *param) {
    char str[64];
    int len;
    int len_s;
    int base;

    base = ft_strlen(_base);
    len = nbr_length(nbr, base);
    len_s = len;
    str[len] = 0;
    while (len--) {
        str[len] = _base[nbr % base];
        nbr /= base;
    }
    param->str = ft_strjoin(param->str, str);
    // int i = 0;
    // while (i < 55)
    // 	param->str[i++] = '1';
    // param->str[55]=0;
    return (len_s);
}

int ft_itoa_p(intmax_t nbr, t_param *param) {
    char str[64];
    int len;
    int len_s;
    int sign;

    sign = 1;
    len = nbr_length(nbr, 10) + 1;
    if (nbr >= 0) {
        len--;
        sign = 0;
        nbr = -nbr;
    }
    len_s = len;
    str[len] = 0;
    while (len--) {
        str[len] = -(nbr % 10) + '0';
        nbr /= 10;
    }
    if (sign)
        *str = '-';
    param->str = ft_strjoin(param->str, str);
    return (len_s);
}

int ft_dtoa(long double nbr, t_param *param) {
    if (param->precision == 0)
        param->precision = 6;
    void *adr;
    size_t size;
    char *str;
    int max_len;
    int shift;
    int len;
    max_len = 10000 + 14;
    int i;
    size_t j;
    const uintmax_t mask = (long long int) (nbr);
    int in_main;
    if (!(str = (char *) malloc(sizeof(*str) * max_len + 1)))
        return 0;
    i = 0;
    while (i < max_len)
        str[i++] = 0;
    nbr = nbr*2;
    adr = (void *) (&nbr);
    size = sizeof(nbr);
    printf("size: %ld\n",size);
    while (0 < size--) {
        ft_printf("%08b ", ((unsigned char *) adr)[size]);

    }

    size = sizeof(nbr);
    ft_printf("\n");
    while (0 < size--) {
        ft_printf("%02x       ", ((unsigned char *) adr)[size]);
    }
    ft_printf("\n");

    uintmax_t mantissa;
    intmax_t exponent;
    ft_memcpy(&mantissa, &nbr, sizeof(mantissa));
    printf("size exponent: %ld\n",sizeof(mantissa));
    ft_memcpy(&exponent, (void*)(&nbr) + sizeof(exponent), sizeof(exponent));
    printf("size mantissa: %ld\n",sizeof(exponent));


    size = sizeof(mantissa);
    adr = (void *) (&mantissa);
    ft_printf("\nmantissa:\n");
    while (0 < size--) {
        ft_printf("%08b ", ((unsigned char *) adr)[size]);
    }
    size = sizeof(exponent);
    adr = (void *) (&exponent);
    ft_printf("\nexponent\n");
    while (0 < size--) {
        ft_printf("%08b ", ((unsigned char *) adr)[size]);
    }
//    ft_printf("\n%0ld < exponent\n", exponent);
//    printf("%0ld < mantissa\n", mantissa);

//    shift= 17 + ((int)(0.3010299956639813 * (exponent  - 1023 - 52)));
//    printf("%d < you?\n", shift);
//    i = shift;
//    while (i--) {
//        str[i] = mantissa % 10;
//        mantissa /= 10;
//    }
//    i = exponent - 1023 - 52;

//    printf("%d < power(i)\n", i);
//    printf("%d < power\n", ((int) (0.3010299956639813 * i)));


//    shift = 17 + ((int) (0.3010299956639813 * (exponent - 1023 - 52)));
//    printf("%d < you?\n", shift);

//    if ((*(uintmax_t *) (&nbr)) >> 63 == 1)
//        ft_printf("\n-");
//    if (i < 0) {
//          shift = -shift;
//        printf("%d < you?\n", shift);
//        i = shift;
        len = ft_unbrlen(mantissa);
        i = len;
    printf("\nmantisa : %lu\n ", mantissa);
        while (i--) {
            str[i] = mantissa % 10;

            mantissa /= 10;
        }
    printf("\nexponent : %lu\n ", exponent);
        i = exponent - (1<<14) - 63;

        while (i++) {
            j = 0;
            while (j < max_len - 1) {
                str[j + 1] = str[j + 1] + (str[j] % 2) * 10;
                str[j] = str[j] / 2;
                j++;
            }
            str[max_len - 1] /= 2;
        }
        i = shift + 21;


//        if (i >= 20) {
//            j = 20;
//            ft_printf("0.");
//            while (j++ < i)
//                ft_printf("0");
//
//
//        }
//        while (i < max_len - 20)
//            if (20 - i == 0) {
//                ft_printf(".");
//                i++;
//            }
//        else {
//                ft_printf("%d", str[i++]);
//            }

            ft_printf("\n");
            i = 18;
            while(i<max_len)
                ft_printf("%c",str[i++]+ '0');
//        } else {
//
//        i = shift + 2;
//        while (i--) {
//            str[i] = mantissa % 10;
//            mantissa /= 10;
//        }
//        i = exponent - 1023 - 52;
//        while (i--) {
//            j = max_len;
//            in_main = 0;
//            while (j-- > 0) {
//
//                str[j] = 2 * str[j] + in_main;
//                in_main = str[j] / 10;
//                str[j] %= 10;
//            }
//            str[max_len - 1] /= 2;
//        }
//
//    i = 0;

//    while (i < max_len - 12)
//        if (i != shift)
//            ft_printf("%d", str[i++]);
//        else
//        {
//            ft_printf(".");
//            i++;
//        }
//    }

//    i = 0;
//    ft_printf("\n%d\n",16 + ((int) (0.3010299956639813 * (exponent - 1023 - 52))));
//    shift = 16 + ((int) (0.3010299956639813 * (exponent - 1023 - 52)));
//    int flag = 1;
//    i = 0;
//    if ((*(uintmax_t *) (&nbr)) >> 63 == 1) {
//        str[i++] = '-';
//
//    }
//    if (shift > 0) {
//
//        j = 0;
//
//        while (i < max_len && j < max_len){
//            if (flag && (str[j] == 0 || str[j] == '-')) {
//                j++;
//                continue;
//            }
//                flag = 0;
//                str[i++] = str[j++] + '0';
//                if (i == shift+1)
//                    str[i++] = '.';
//
//        }
//        while(i < max_len)
//            str[i++] = '0';
//        str[shift + 2 + param->precision] = 0;
//
//    }
//    else{
//
//        int count = 0;
//        str[i++]='0';
//        str[i++]='.';
//        while (count < - shift)
//        {
//            count++;
//            str[i++] = '0';
//        }
//        j = i;
//        while (i < max_len && j < max_len){
//            if ((str[j] == 0 || str[j] == '-' ) && flag )
//                j++;
//            else
//            {
//                flag = 0;
//                str[i++] = str[j++] + '0';
//
//            }
//        }
//        while(i < max_len)
//            str[i++] = '0';
//        str[2 + param->precision] = 0;
//    }

//    if ((*(uintmax_t *) (&nbr)) >> 63 == 1) {
//        i = max_len;
//        while (i--)
//            str[i + 1] = str[i];
//        str[0] = '-';
//    }
//        param->str = str;

//        ft_printf("!%s", str);


    return 1;
}
