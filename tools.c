#include "ft_printf.h"

#include <stdlib.h>


//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	char	*str;
//	int		len;
//
//	len = ft_strlen(s1) + ft_strlen(s2);
//	str = (char *)malloc(sizeof(*str) * (len + 1));
//	if (str == NULL)
//		return (NULL);
//	strcpy(str, s1);
//	strcat(str, s2);
//	return (str);
//}

//char is_digit(char c)
//{
//	if (c >= '0' && c <= '9')
//		return (c);
//	return (0);
//}

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
	if (*str == '*')
		return -1;
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
	  *str== 'X' || *str == 'f' || *str == 'o' || *str == 'b')
		return (*(unsigned char*)str);
	 return(0);
}

int	conversion(t_param *param)
{
	//print_param(param);
	if (param->type == 'c')
		return ft_getchar(va_arg(param->ap, int),param);
	if (param->type == 'd' || param->type == 'i')//iouxX')
	{
		if (param->length == 'h'+'h')
			return (ft_itoa_p(va_arg(param->ap, int), param));//va_arg(param->ap,char)
		if (param->length == 'h')
			return (ft_itoa_p(va_arg(param->ap, int), param));//va_arg(param->ap,short int)
		if (param->length == 0)
			return (ft_itoa_p(va_arg(param->ap, int), param));
		if (param->length == 'l')
			return (ft_itoa_p(va_arg(param->ap, long int), param));;//va_arg(param->ap,long int)
		if (param->length == 'l'+'l')
			return (ft_itoa_p(va_arg(param->ap, long long int), param));//va_arg(param->ap,long long int)
		if (param->length == 'z' || param->length =='t')
			return (ft_itoa_p(va_arg(param->ap, size_t), param));//va_arg(param->ap,size_t)
	}
	if (param->type == 'f')
	{
		if (param->length == 0)
			return ft_ftoa(va_arg(param->ap, double), param);//va_arg(param->ap,float)
		if (param->length == 'L' || param->length == 'l')
			return 1;//va_arg(param->ap,long double)
	}
	if (param->type == 's' )
	{
		return (ft_getstr(va_arg(param->ap,char*), param));
	}
	if (param->type == 'p')
	{
		param->str = ft_strjoin("0x", param->str);
		return (ft_itoa_b(va_arg(param->ap, long long int), BASE_16l, param));
	}
	if (param->type == 'X')
	{
		return (ft_itoa_b(va_arg(param->ap, long long int), BASE_16u, param));
	}
	if (param->type == 'x')
	{
		return (ft_itoa_b(va_arg(param->ap, long long int), BASE_16l, param));
	}
	if (param->type == 'o')
	{
		return (ft_itoa_b(va_arg(param->ap, long long int), BASE_8, param));
	}
    if (param->type == 'b')
    {
       // param->str = ft_strjoin("0b", param->str);
        return (ft_itoa_b(va_arg(param->ap, long long int), "01", param));
    }

	return 0;
	//return	ft_itoa_x(va_arg(param->ap,int));
}
