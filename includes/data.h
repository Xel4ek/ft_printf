/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abooster <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:37:53 by abooster          #+#    #+#             */
/*   Updated: 2019/10/17 12:33:12 by abooster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_H
# define DATE_H

#include "ft_printf.h"

typedef struct		s_date
{
	int				day;
	int				month;
	int				year;
	int             error;
}					t_date;



#endif
