
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abooster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:40:26 by abooster          #+#    #+#             */
/*   Updated: 2019/10/17 12:32:18 by abooster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int str2date(char* str, int start, int len)
{
	int tmp, ten, i;
	char c;

	tmp = 0;
	ten = 1;
	i = 0;
	while(i < len)
	{
		c = str[start + len - i - 1];
		if ((c < '0') || (c > '9'))
			return -1;
		tmp += (c-'0') * ten;
		ten *= 10;
		i++;
	}
	return tmp;
}

int get_date(char *text, t_date *date)
{
//	int	l;

//    date->error = 0;
//    date->year = ft_atoi(text);
//    date->month = ft_atoi(text + 5);
//    date->day = ft_atoi(text + 8);
//	l = strlen(text);
	if((text[4] != '-') || (text[7] != '-'))
        return  (date->error = 1);
	if((date->year = str2date(text, 0, 4)) == -1)
        return  (date->error = 1);
	if((date->month = str2date(text, 5, 2)) == -1)
        return  (date->error = 1);
	if((date->day = str2date(text, 8, 2)) == -1)
        return  (date->error = 1);
	if (date->month > 12 || date->day > 31)
	  return  (date->error = 1);

	if ((date->day == 31) && ((date->month == 4) || (date->month == 9) || \
	(date->month == 11)))
        return  (date->error = 1);
	if (((date->day == 29) && (date->month == 2)) && \
	(((date->year % 4) != 0) || (((date->year % 100) == 0) && \
	((date->year % 400) != 0))))
        return  (date->error = 1);
	if ((date->day > 29) && (date->month) == 2)
        return  (date->error = 1);
	return 0;
}

int	date_to_str(t_date *date,t_param *param)
{
//	if((val_date(text, date)) == -1)
//		return -1;
    char string[11]= "valid data";

    param->str = ft_strjoin(param->str, string);
    param->line_size = ft_strlen(param->str);
//	printf("%d-%d-%d\n", date->year,date->month,date->day);
     return 0;
}


int data_print(char *string, t_param *param)
{
    t_date data;
    get_date(string, &data);
    if (data.error) {
        param->str = ft_strjoin(param->str, "Error data");
        param->line_size = ft_strlen(param->str);
        return 1;
    }
    date_to_str(&data, param);
    return 0;
}


