#include "ft_printf.h"
#include <unistd.h>

int ft_getstr(char *str, t_param *param) {
    param->str = ft_strjoin(param->str, str);
    return (1);
}

int ft_getchar(char c, t_param *param) {
    free(param->str);
    if (!(param->str = malloc(sizeof(c) * 2)))
        return 0;
    param->str[0] = c;
    param->str[1] = 0;

    return (1);
}


int ft_nbrlen(int nbr) {
    int len;

    len = 1;
    while (nbr /= 10)
        len++;
    return (len);
}

int print_item(t_param *param) {
    if (param->type == '%')
        return ft_getchar('%', param);
    if (param->type == 'd' || param->type == 'i')
        return conversion(param);//(ft_itoa_x(va_arg(ap,int)));
    if (param->type == 'u')
        return conversion(param);//(ft_putstr(ft_uitoa(va_arg(ap,unsigned int))));
    if (param->type == 'x')
        return conversion(param);
    if (param->type == 'b')
        return conversion(param);
    if (param->type == 'X')
        return conversion(param);
    if (param->type == 'f')
        return conversion(param);
    if (param->type == 'c')
        return conversion(param);
    if (param->type == 's')
        return conversion(param);
    if (param->type == 'p')
        return conversion(param);
    if (param->type == 'o')
        return conversion(param);
//	int i = va_arg(ap, int);
//	printf("!_!_%d_!__!",i);
    //print_param(param);
//	printf("OK");
    return 0;
}

int apply_flags(t_param *param) {
    char space;
    int len;
    char *ptr;
    int i;

    i = -1;
    space = ' ';
    if (param->width > 0 && param->flag.zero && !param->flag.minus)
        space = '0';
    if (param->flag.hash) {
        if (param->type == 'x')
            param->str = ft_strjoin("0x", param->str);
        else if (param->type == 'X')
            param->str = ft_strjoin("0X", param->str);
        else if (param->type == 'o')
            param->str = ft_strjoin("0", param->str);

    }
    if (param->type == 'd' || param->type == 'i')
        if (param->flag.plus && param->str[0] != '-')
            param->str = ft_strjoin("+", param->str);
        else if (param->flag.space)
            param->str = ft_strjoin(" ", param->str);
    len = ft_strlen(param->str);
    if (param->width == -1 || param->width < len)
        param->width = len;
    if (len < param->width) {
        ptr = (char *) (malloc((param->width - len) * sizeof(char)));
        while (i++ < param->width - len - 1)
            ptr[i] = space;
        ptr[i] = 0;

        if (param->flag.minus)
            param->str = ft_strjoin(param->str, ptr);
        else
            param->str = ft_strjoin(ptr, param->str);
    }
    return 1;
}
