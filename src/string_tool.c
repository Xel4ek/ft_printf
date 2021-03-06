/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:17:52 by hwolf             #+#    #+#             */
/*   Updated: 2019/10/19 18:19:56 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstring(const int fd, char *string, size_t size)
{
	write(fd, string, size);
}

int		ft_getchar(char c, t_param *param)
{
	(param->str)[0] = c;
	(param->str)[1] = 0;
	param->line_size++;
	return (1);
}

int		ft_getstr(char *str, t_param *param)
{
	int		len;
	char	*ptr;

	if (param->precision < (len = ft_strlen(str)) && param->precision != -1)
		len = param->precision;
	if (str)
	{
		ft_memdel((void **)&param->str);
		if (!(param->str = (char *)malloc(sizeof(*str) * (len + 1))))
			return (0);
		(param->str)[len] = 0;
		param->str = ft_strncpy(param->str, str, len);
	}
	else
	{
		ptr = ft_strjoin(param->str, "(null)");
		ft_memdel((void **)&param->str);
		param->str = ptr;
	}
	param->line_size = ft_strlen(param->str);
	return (1);
}

int		raw_string(char *string, t_param *param)
{
	char	ptr[(ft_strlen(string) + 1) * 3];
	char	*temp;
	int		i;

	i = 0;
	if (string)
		while (*string)
		{
			if (ft_isprint(*string))
				ptr[i++] = *string++;
			else
			{
				ptr[i++] = 0x5c;
				ptr[i++] = BASE_16L[*string / 16];
				ptr[i++] = BASE_16L[*string % 16];
				string++;
			}
		}
	ptr[i] = 0;
	temp = ft_strjoin(param->str, ptr);
	ft_memdel((void **)&param->str);
	param->str = temp;
	param->line_size = ft_strlen(param->str);
	return (1);
}
