#include "includes/ft_printf.h"

int get_item(t_param *param) {
    if (param->type == '%' || param->type == 's' || param->type == 'r' ||
            param->type == 'k' || param->type == 'c')
        return string_convertation(param);
    if (param->type == 'd' || param->type == 'i' || param->type == 'u')
        return ten_base_int(param);
    if (param->type == 'x' || param->type == 'X')
        return hex_base_int(param);
    if (param->type == 'b' || param->type == 'p' || param->type == 'o')
        return other_base_int(param);
    if (param->type == 'f' || param->type == 'e')
        return double_convertation(param);
    return 0;
}

