#include "ft_printf.h"

void init_flag(t_flag *flag) {
    flag->minus = 0;
    flag->plus = 0;
    flag->zero = 0;
    flag->space = 0;
    flag->hash = 0;
}

void init_param(t_param *param) {
    param->type = 0;
    param->length = 0;
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


//
//void print_param(const t_param param) {
//    printf("%d < flag<zero\n", param.flag.zero);
//    printf("%d < flag<hash\n", param.flag.hash);
//    printf("%d < flag<minus\n", param.flag.minus);
//    printf("%d < flag<plus\n", param.flag.plus);
//    printf("%d < flag<space\n", param.flag.space);
//    printf("%d < width\n", param.width);
//    printf("%d < precision\n", param.precision);
//    printf("%d < length\n", param.length);
//    printf("%c < type\n", param.type);
//    printf("%s < str\n", param.str);
//}