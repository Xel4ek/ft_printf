/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:20:20 by hwolf             #+#    #+#             */
/*   Updated: 2019/10/19 19:10:52 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_convertation(t_param *param)
{
	if (param->type == '%')
		return (ft_getchar('%', param));
	if (param->type == 'c')
		return (ft_getchar((char)va_arg(param->ap, int), param));
	if (param->type == 's')
		return (ft_getstr(va_arg(param->ap, char*), param));
	if (param->type == 'r')
		return (raw_string(va_arg(param->ap, char*), param));
	if (param->type == 'k')
		return (date_to_string(string_to_date(
				va_arg(param->ap, char*)), param));
		return (-1);
}

int	double_convertation(t_param *param)
{
	if (param->type == 'f')
	{
		if (param->length == 'l' || param->length == 0)
			return (ft_dtoa((long double)va_arg(param->ap, double), param));
		if (param->length == 'L')
			return (ft_dtoa((long double)va_arg(param->ap,
					long double), param));
	}
	if (param->type == 'e')
	{
		if (param->length == 'l' || param->length == 0)
			return (ft_dtoa_e((long double)va_arg(param->ap, double), param));
		if (param->length == 'L')
			return (ft_dtoa_e((long double)va_arg(param->ap, long double),
							param));
	}
	return (-1);
}

int	ten_base_int(t_param *param)
{
	if (param->type == 'd' || param->type == 'i')
	{
		if (param->length == 'h' + 'h')
			return (ft_itoa_p((char)va_arg(param->ap, int), param));
		if (param->length == 'h')
			return (ft_itoa_p((short int)va_arg(param->ap, int), param));
		if (param->length == 0)
			return (ft_itoa_p((int)va_arg(param->ap, int), param));
		if (param->length == 'l')
			return (ft_itoa_p((long int)va_arg(param->ap, long int), param));
		if (param->length == 'l' + 'l')
			return (ft_itoa_p((LLI)va_arg(param->ap, LLI), param));
		if (param->length == 'z' || param->length == 't')
			return (ft_itoa_p((size_t)va_arg(param->ap, size_t), param));
	}
	return (-1);
}

int	hex_base_int(t_param *p)
{
	char *base;

	if (p->type == 'X')
		base = BASE_16U;
	else if (p->type == 'x')
		base = BASE_16L;
	else
		return (-1);
	if (p->length == 'h' + 'h')
		return (ft_itoa_b((unsigned char)va_arg(p->ap, unsigned int), base, p));
	if (p->length == 'h')
		return (ft_itoa_b((USI)va_arg(p->ap, unsigned int), base, p));
	if (p->length == 'l')
		return (ft_itoa_b((uintmax_t)va_arg(p->ap, ULI), base, p));
	if (p->length == 'l' + 'l')
		return (ft_itoa_b((uintmax_t)va_arg(p->ap, uintmax_t), base, p));
	return (ft_itoa_b((uintmax_t)va_arg(p->ap, unsigned int), base, p));
}

int	other_base_int(t_param *p)
{
	if (p->type == 'p')
		return (ft_itoa_b((size_t)va_arg(p->ap, size_t), BASE_16L, p));
	if (p->type == 'o')
	{
		if (p->length == 'h' + 'h')
			return (ft_itoa_b((unsigned char)va_arg(p->ap, int), BASE_8, p));
		if (p->length == 'h')
			return (ft_itoa_b((USI)va_arg(p->ap, int), BASE_8, p));
		if (p->length == 0)
			return (ft_itoa_b((unsigned int)va_arg(p->ap, int), BASE_8, p));
		return (ft_itoa_b((uintmax_t)va_arg(p->ap, uintmax_t), BASE_8, p));
	}
	if (p->type == 'b')
		return (ft_itoa_b((uintmax_t)va_arg(p->ap, intmax_t), "01", p));
	return (-1);
}
