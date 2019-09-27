#include "ft_printf.h"

# include <stdio.h>


t_param 	*get_param(t_param *new_param, char **str)
{
	if (**str != '%')
		return (NULL);
	(*str)++;
	if ((new_param->flag = get_flag((*str))))
		(*str)++;
	if ((new_param->width = get_width((*str))))
		(*str) += ft_nbrlen(new_param->width);
	if ((new_param->precision = get_precision((*str))))
		(*str) += ft_nbrlen(new_param->precision) + 1;
	if((new_param->length = get_length((*str))))
	{
		if (new_param->length > 'z')
			(*str)++;
		(*str)++;
	}
	if (!(new_param->type = get_type((*str))))
		return (NULL);
	(*str)++;
	return (new_param);
}

void print_param(t_param *param)
{
	printf("%d < flag\n",param->flag);
	printf("%d < width\n",param->width);
	printf("%d < precision\n",param->precision);
	printf("%d < length\n",param->length);
	printf("%c < type\n",param->type);
}
