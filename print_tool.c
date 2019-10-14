#include "ft_printf.h"
#include <unistd.h>

int ft_getstr(char *str, t_param *param) {

    int len;
    if (param->precision < (len = ft_strlen(str)) && param->precision != -1)
        len = param->precision;
    if (str) {
        param->str = (char *) malloc(sizeof(*str) * (len + 1));
        param->str[len] = 0;
        param->str = ft_strncpy(param->str, str, len);
    }
    else
        param->str = ft_strjoin(param->str, "(null)");
    param->line_size = ft_strlen(param->str);
    return (1);
}

int ft_getchar(char c, t_param *param) {
    param->str[0] = c;
    param->str[1] = 0;
    param->line_size++;
    return (1);
}

void ft_putstring(const int fd, char *string, unsigned int size)
{
    write(fd, string, size);
}

int ft_nbrlen(long long int nbr) {
    int len;

    len = 1;
    while (nbr /= 10)
        len++;
    return (len);
}
int ft_unbrlen(uintmax_t nbr) {
    int len;

    len = 1;
    while (nbr /= 10)
        len++;
    return (len);
}

int get_item(t_param *param) {
    if (param->type == '%')
        return conversion(param);
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
    if (param->type == 'e')
        return conversion(param);
    return 0;
}

int apply_flags(t_param *param) {
    char space;
    int len;
    char *ptr;
    int i;
    char prefix[] = {0, 0, 0};
    i = -1;
    space = ' ';
    if (param->precision == 0 && (param->line_size == 1 && param->str[0] == '0')) {
        param->str[0] = 0;
        param->line_size--;
    }
    if (param->type == 'p'){
        param->str = ft_strjoin("0x", param->str);
        param->line_size += 2;
    }
    if (param->flag.hash && ((param->type == 'X' || param->type == 'x' || param->type =='o' ) && !(param->str[0] == '0' && param->line_size == 1))) {

        if (param->type == 'o' ) {
            if (param->precision < 1) {
                prefix[0] = '0';
                param->line_size++;
            }
        }
        else if (param->line_size > 0) {
            prefix[0] = '0';
            prefix[1] = param->type;
           param->line_size += 2;
        }

    }
    if (param->width > 0 && param->flag.zero && !param->flag.minus)
        space = '0';
    if (param->sign)
    {
        prefix[0] = '-';
        param->line_size++;
    }
    if (param->type == 'd' || param->type == 'i') {
        if (param->flag.plus && !param->sign) {
            prefix[0] = '+';
            param->line_size++;
        }
        else if (param->flag.space && !param->sign) {
            prefix[0] = ' ';
            param->line_size++;
        }
    }
    len = param->line_size;
    if (param->width < len)
        param->width = len;
    if (len < param->width) {
        if (param->precision == -1)
            param->precision = param->width;
        ptr = (char *) (malloc((param->width - len) * sizeof(char)));
        while (i++ < param->width - len - 1)
        {
            if (i >= param->width - param->precision)
                ptr[i] = space;
            else
                ptr[i] = ' ';
        }
        ptr[i] = 0;
        if (param->flag.minus)
            param->str = ft_strjoin(ft_strjoin(prefix, param->str), ptr);
        else if (param->flag.zero)
            param->str = ft_strjoin(prefix, ft_strjoin(ptr, param->str));
        else
            param->str = ft_strjoin(ft_strjoin(ptr, prefix), param->str);
    }
    else
        param->str = ft_strjoin(prefix,param->str);
    param->line_size = param->width;


    return 1;
}
