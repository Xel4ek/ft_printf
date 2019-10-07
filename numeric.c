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
        str[len] = -nbr % 10 + '0';
        nbr /= 10;
    }
    if (sign)
        *str = '-';
    param->str = ft_strjoin(param->str, str);
    return (len_s);
}

int ft_ftoa(double nbr, t_param *param) {
    void *adr;
    size_t size;
    char *str;
    int max_len;
    max_len = 169;
    int i;
    size_t j;
    const uintmax_t mask = 0xFFFFFFFFFFFF;

    if(!(str = (char*)malloc(sizeof(*str) * max_len)))
        return 0;
    i = 0;
    while (i < max_len)
        str[i++] = 0;
    adr = (void *) (&nbr);
    size = sizeof(nbr);

    while (0 < size--) {
        ft_printf("%08b ", ((unsigned char *) adr)[size]);

    }
    size = sizeof(nbr);
    ft_printf("\n");
    while (0 < size--) {
        ft_printf("%02x       ", ((unsigned char *) adr)[size]);
    }


    uintmax_t mantissa = *(uintmax_t*)(&nbr) & 0x000fffffffffffff;
    uintmax_t exponent = (*(uintmax_t*)(&nbr) & 0x3ff0000000000000) >> 52;//(uintmax_t)(void*)(&nbr);
    size = sizeof(mantissa);
    adr = (void*)(&mantissa);
    ft_printf("\nmantissa:\n");
    while (0 < size--) {
        ft_printf("%08b ", ((unsigned char *) adr)[size]);
    }
    size = sizeof(exponent);
    adr = (void*)(&exponent);
    ft_printf("\nexponent\n");
    while (0 < size--) {
        ft_printf("%08b ", ((unsigned char *) adr)[size]);
    }
    ft_printf("\n%0ld\n", mantissa);
    printf("%0ld < here\n",mantissa);

    i= 16;
    while (i--) {
        str[i] = mantissa % 10;
        mantissa /= 10;
    }
    i = 1;
    while (i--)
    {
        j = 0;
        while(j < max_len - 1){
            str[j + 1] = str[j + 1] + (str[j] % 2) * 10;
            str[j] = str[j] / 2;
            j++;
        }
        str[max_len - 1] /= 2;
    }

    i = 0;
    ft_printf("\n");
    while (i < max_len)
        ft_printf("%d",str[i++]);
    return 1;
}
