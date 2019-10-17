#include "ft_printf.h"
#include <unistd.h>

int ft_getstr(char *str, t_param *param)
{
    int len;
    char *ptr;
    if (param->precision < (len = ft_strlen(str)) && param->precision != -1)
        len = param->precision;
    if (str) {
        ft_memdel((void**)&param->str);
        if (!(param->str = (char*) malloc(sizeof(*str) * (len + 1))))
            return 0;
        param->str[len] = 0;
        param->str = ft_strncpy(param->str, str, len);
    }
    else {
        ptr = ft_strjoin(param->str, "(null)");
        ft_memdel((void**)&param->str);
        param->str = ptr;
    }
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
    if (param->type == 'k')
        return conversion(param);
    return 0;
}

int apply_flags(t_param *param) {
    char space;
    int len;
    char *ptr;
    int i;
    char *temp;
    char *temp2;

    char prefix[] = {0, 0, 0};
    space = ' ';

    if (param->precision == 0 && (param->line_size == 1 && param->str[0] == '0')) {
        param->str[0] = 0;
        param->line_size--;
    }
    if (param->type == 'p'){
        prefix[0] = '0';
        prefix[1] = 'x';
    }
    if (param->flag.hash && ((param->type == 'X' || param->type == 'x' || param->type =='o' ) && !(param->str[0] == '0' && param->line_size == 1))) {

        if (param->type == 'o' ) {
            if (param->precision < 1) {
                prefix[0] = '0';
//                param->line_size++;
            }
        }
        else if (param->line_size > 0) {
            prefix[0] = '0';
            prefix[1] = (char)param->type;
//           param->line_size += 2;
        }

    }
    if (param->width > 0 && param->flag.zero && !param->flag.minus)
        space = '0';
    if (param->sign)
    {
        prefix[0] = '-';
//        param->line_size++;
    }
    if (param->type == 'd' || param->type == 'i') {
        if (param->flag.plus && !param->sign) {
            prefix[0] = '+';
//            param->line_size++;
        }
        else if (param->flag.space && !param->sign) {
            prefix[0] = ' ';
//            param->line_size++;
        }
    }
    len = param->line_size + ft_strlen(prefix);
    if (param->width < len)
        param->width = len;
    if (len < param->width) {
        if (param->precision == -1)
            param->precision = param->width;
        ptr = (char *) (malloc((param->width - len) * sizeof(*ptr)));
        i = -1;
        while (i++ < param->width - len - 1)
        {
            if (i >= param->width - param->precision)
                ptr[i] = space;
            else
                ptr[i] = ' ';
        }
        ptr[i] = 0;

        if (param->flag.minus) {
            temp = ft_memjoin(prefix, param->str, ft_strlen(prefix), param->line_size);
            param->line_size += ft_strlen(prefix);
            ft_memdel((void**)&param->str);
            param->str = ft_memjoin(temp, ptr, param->line_size, ft_strlen(ptr));
            ft_memdel((void**)&temp);
//            param->line_size += ft_strlen(ptr);
        }else if (param->flag.zero) {
              temp =  ft_strjoin(ptr, param->str);
              ft_memdel((void**)&param->str);
              param->str = temp;
              temp =  ft_strjoin(prefix, param->str);
              ft_memdel((void**)&param->str);
              param->str = temp;
//            ft_memdel((void**)&param->str);
//            temp =  ft_strjoin(prefix, ft_strjoin(ptr, param->str));
//            param->str = temp;
//            param->line_size = param->width;
        }else {
            temp = ft_strjoin(ptr, prefix);
            temp2 = ft_strjoin(temp, param->str);
            ft_memdel((void**)&param->str);
            ft_memdel((void**)&temp);
            param->str = temp2;
//            param->line_size = param->width;
        }
        ft_memdel((void**)&ptr);
    }
    else {

        temp = ft_strjoin(prefix, param->str);
        ft_memdel((void**)&param->str);
        param->str = temp;
    }
    param->line_size = param->width;


    return 1;
}
