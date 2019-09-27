#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# include <stdlib.h>



# include <stdio.h>

typedef struct			s_param
{
		unsigned char	flag;
		unsigned char	type;
		unsigned char	length;
		int				width;
		int				precision;

}						t_param;

int 					ft_nbrlen(int nbr);
int						ft_printf(const char *format, ...);
void					ft_putchar(char c);
unsigned char			get_flag(char *str);
int						get_precision(char *str);
unsigned char			get_length(char *str);
unsigned char			get_type(char *str);
int						get_width(char *str);
t_param					*get_param(t_param *new_param, char **str);
void					print_param(t_param *param);
#endif
