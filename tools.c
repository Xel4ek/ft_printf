#include "ft_printf.h"

char is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

unsigned char get_flag(char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ' || \
		*str == '0' || *str == '#')
		return (*str);
	return (0);
}

int get_width(char *str)
{
	return atoi(str);
}

int get_precision(char *str)
{
	if (*str == '.')
		return (atoi(str + 1));
	return (0);
}

unsigned char	get_length(char *str)
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

unsigned char get_type(char *str)
{
 	if (*str == '%' || *str== 'd' || *str== 'i' || *str== 'u' ||
	 *str == 'c' || *str== 's' || *str== 'p' || *str== 'x' ||
	  *str== 'X' || *str == 'f')
		return (*(unsigned char*)str);
	 return(0);
}
