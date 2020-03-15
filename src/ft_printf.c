/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:00:36 by hwolf             #+#    #+#             */
/*   Updated: 2019/10/19 18:09:16 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ftprintf_core(const int fd, char *ptr, t_param *param)
{
	int printed;
	char *next;

	printed = 0;
	while (*ptr)
	{
		next = ft_strch(ptr, '%');
		if (next != ptr)
		{
			ft_putstring(fd, ptr, next - ptr);
			printed += (int)(next - ptr);
			ptr = next;
		}
		if (*ptr && get_param(param, &ptr))
		{
				get_item(param);
				apply_flags(param);
				printed += param->line_size;
				ft_putstring(fd, param->str, param->line_size);
				ft_memdel((void **)&param->str);
		}
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		printed;
	t_param	param;

	va_start(param.ap, format);
	printed = ftprintf_core(STDOUT_FILENO, (char*)format, &param);
	va_end(param.ap);
	return (printed);
}

int	ft_printf_fd(const int fd, const char *format, ...)
{
	int		printed;
	t_param	param;

	va_start(param.ap, format);
	printed = ftprintf_core(fd, (char*)format, &param);
	va_end(param.ap);
	return (printed);
}
