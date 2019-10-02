#include "ft_printf.h"
#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		ft_putchar(*str++);
		len++;
	}
	return (len);
}

int ft_nbrlen(int nbr)
{
	int len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}
int print_item(t_param *param)
{
	if (param->type == '%')
		return ft_putchar('%');
	if (param->type == 'd' || param->type == 'i')
		return	conversion(param);//(ft_itoa_x(va_arg(ap,int)));
	if (param->type == 'u')
		return	conversion(param);//(ft_putstr(ft_uitoa(va_arg(ap,unsigned int))));
	if (param->type == 'x')
		return	conversion(param);
	if (param->type == 'X')
		return	conversion(param);
	if (param->type == 'f')
		return	conversion(param);
	if (param->type == 'c')
		return	conversion(param);
	if (param->type == 's')
		return	conversion(param);
	if (param->type == 'p')
		return	conversion(param);
	if (param->type == 'o')
		return	conversion(param);
//	int i = va_arg(ap, int);
//	printf("!_!_%d_!__!",i);
	//print_param(param);
//	printf("OK");
	return 0;
}
