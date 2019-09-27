#include "ft_printf.h"
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int ft_nbrlen(int nbr)
{
	int len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}
