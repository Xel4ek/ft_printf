#include "ft_printf.h"
//#include <stdio.h>
#include <string.h>

int		ft_printf(const char *format, ...)
{
	char *ptr;
	t_param param;
	ptr = (char*)format;
	va_start(param.ap, format);
	int printed = 0;
	while (*ptr)
	{
		while (*ptr != '%' && *ptr){
			ft_putchar(*ptr++);
			printed++;
		}
		if (*ptr)
		{
			if (get_param(&param, &ptr))
                get_item(&param);
			apply_flags(&param);
			printed += param.line_size;
			ft_putstring(1, param.str, param.line_size);
			ft_memdel((void**)&param.str);
		}
	}
	va_end (param.ap);
	return (printed);
}
