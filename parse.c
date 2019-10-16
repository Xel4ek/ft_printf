#include "ft_printf.h"
//# include <stdio.h>

void init_flag(t_flag *flag) {
    flag->minus = 0;
    flag->plus = 0;
    flag->zero = 0;
    flag->space = 0;
    flag->hash = 0;
}

void init_param(t_param *param)
{
    param->type = 0;
    param->length= 0;
    param->width = 0;
    param->precision = -1;
    param->str = NULL;
    param->sign = 0;
    param->line_size = 0;
    init_flag(&(param->flag));

}

t_param *get_param(t_param *new_param, char **str) {
    (*str)++;
    init_param(new_param);
    while (get_flag((*str), &(new_param->flag)))
        (*str)++;
    (*str) += get_width(*str, new_param);
    new_param->precision = get_precision(str, new_param);
    if ((new_param->length = get_length((*str)))) {
        if (new_param->length > 'z')
            (*str)++;
        (*str)++;
    }
    while (**str && !(new_param->type = get_type(*str)))
        (*str)++;
    if (!(new_param->type))
        return (NULL);
    if (!(new_param->str = (char *) malloc(2)))
        return (NULL);
    *(new_param->str) = 0;
    (*str)++;
    return (new_param);
}

int get_flag(const  char *str, t_flag *flag)
{

    if (*str == '-' )
        flag->minus = 1;
    else if (*str == '+' )
        flag->plus = 1;
    else if (*str == '0' )
        flag->zero = 1;
    else if (*str == ' ' )
        flag->space = 1;
    else if (*str == '#' )
        flag->hash = 1;
    else
        return (0);
    return (1);
}

int get_width(char *str, t_param *param)
{
    int width;
    int next;

    next =0;
    if (*str == '*') {
        str++;
        width = va_arg(param->ap, int);
        if (width < 0)
        {
            param->flag.minus = 1;
            param->width = -width;
        }
        else
            param->width = width;
        next = 1;
    }
    if ((width = ft_atoi(str))) {
        param->width = width;
        next = param->width ? ft_nbrlen(param->width) : 0;
    }
    return (next);
}

int  get_precision(char **str, t_param *param)
{
    int tmp;

    if (**str == '.')
    {
        (*str)++;
        if (**str == '*'){
            (*str)++;
            tmp  =(int)va_arg(param->ap, int);
            return (tmp < 0 ? -1 : tmp);
        }
        tmp = (ft_atoi(*str));
        while (**str >= '0' && **str <= '9')
            (*str)++;
        return tmp;
    }
    return (-1);
}

unsigned char	get_length(const char *str)
{
    if (*str == 'h')
    {
        if (*(str + 1) == 'h')
            return ('h' + 'h');
        return('h');
    }
    if (*str == 'l')
    {
        if (*(str + 1) == 'l')
            return ('l' + 'l');
        return('l');
    }
    if (*str == 'L')
        return ('L');
    if (*str == 'z')
        return ('z');
    if (*str == 't')
        return ('t');
    return (0);
}

unsigned char get_type(const char *str)
{
    if (*str == '%' || *str== 'd' || *str== 'i' || *str== 'u' ||
        *str == 'c' || *str== 's' || *str== 'p' || *str== 'x' ||
        *str== 'X' || *str == 'f' || *str == 'o' || *str == 'b' ||
        *str =='e')
        return (*(unsigned char*)str);
    return(0);
}

void print_param(const t_param param) {
    printf("%d < flag<zero\n", param.flag.zero);
    printf("%d < flag<hash\n", param.flag.hash);
    printf("%d < flag<minus\n", param.flag.minus);
    printf("%d < flag<plus\n", param.flag.plus);
    printf("%d < flag<space\n", param.flag.space);
    printf("%d < width\n", param.width);
    printf("%d < precision\n", param.precision);
    printf("%d < length\n", param.length);
    printf("%c < type\n", param.type);
    printf("%s < str\n", param.str);
}
