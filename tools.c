#include "ft_printf.h"

char is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int get_flag(char *str,t_flag *flag)
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

int get_width(char *str)
{
	return atoi(str);
}

int get_precision(char **str)
{
	int tmp;

	if (**str == '.')
	{
		(*str)++;
		//printf("!was-->%c<--was!/n",**str);
		tmp = (atoi(*str));
		//printf("!was-->%c<--was!/n",**str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	//	printf("\n!-->%s<--!/n",*str);
		return tmp;
	}return (0);
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
	  *str== 'X' || *str == 'f' || *str == 'o')
		return (*(unsigned char*)str);
	 return(0);
}

int	conversion(t_param *param)
{
	//print_param(param);
	if (param->type == 'c')
		return ft_putchar(va_arg(param->ap, int));
	if (param->type == 'd')//iouxX')
	{
		if (param->length == 'h'+'h')
			return (ft_itoa(va_arg(param->ap, int)));//va_arg(param->ap,char)
		if (param->length == 'h')
			return (ft_itoa(va_arg(param->ap, int)));//va_arg(param->ap,short int)
		if (param->length == 0)
			return (ft_itoa(va_arg(param->ap, int)));
		if (param->length == 'l')
			return (ft_itoa(va_arg(param->ap, long int)));;//va_arg(param->ap,long int)
		if (param->length == 'l'+'l')
			return (ft_itoa(va_arg(param->ap, long long int)));//va_arg(param->ap,long long int)
		if (param->length == 'z' || param->length =='t')
			return (ft_itoa(va_arg(param->ap, size_t)));//va_arg(param->ap,size_t)
	}
	if (param->type == 'f')
	{
		if (param->length == 0)
			return 1;//va_arg(param->ap,float)
		if (param->length == 'L' || param->length == 'l')
			return 1;//va_arg(param->ap,long double)
	}
	if (param->type == 's' )
	{
			return (ft_putstr(va_arg(param->ap,char*)));
	}
	if (param->type == 'p')
	{
			ft_putstr("0x");
			param->printed += 2;
			return (ft_itoa_x(va_arg(param->ap, size_t), "0123456789abcdef"));
	}
	if (param->type == 'X')
	{
		if (param->flag.hash == 1){
			ft_putstr("0X");
			param->printed += 2;}
		return (ft_itoa_x(va_arg(param->ap, long long int), "0123456789ABCDEF"));
	}
	if (param->type == 'x')
	{
		if (param->flag.hash == 1){
			ft_putstr("0x");
			param->printed += 2;}
			return (ft_itoa_x(va_arg(param->ap, long long int), "0123456789abcdef"));
	}
	if (param->type == 'o')
	{
		if (param->flag.hash == 1){
			ft_putstr("0");
			param->printed++;}
		return (ft_itoa_o(va_arg(param->ap, long long int), "01234567"));
	}

	return 0;
	//return	ft_itoa_x(va_arg(param->ap,int));
}
