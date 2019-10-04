#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int		ft_printf(const char *format, ...)
{
	char *ptr;
	char *keep_ptr;
	t_param param;
	ptr = strdup(format);
	keep_ptr = ptr;
	va_start(param.ap, format);
	param.printed = 0;
	while (*ptr)
	{
		while (*ptr != '%' && *ptr){
			ft_putchar(*ptr++);
			param.printed++;
		}
		if (*ptr)
		{
			get_param(&param,&ptr);
			// print_param(param);
			print_item(&param);
			apply_flags(&param);
			param.printed += ft_strlen(param.str);
			ft_putstr(param.str);
			// print_param(param);
		}
	}
	/*if(!strcmp(format, "%d"))
	{
		int x = va_arg (ap, int);
		printf ("You passed decimal object with value %d\n", x);
	}

	if(!strcmp(format, "%s"))
	{
		char *p = va_arg (ap, char *);
		printf ("You passed c-string \"%s\"\n", p);
	}
*/	va_end (param.ap);
	return (param.printed);
}
