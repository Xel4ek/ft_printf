#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# define INT int

# include <stdio.h>

typedef struct			s_flag
{
	unsigned char		minus;
	unsigned char		plus;
	unsigned char		space;
	unsigned char		zero;
	unsigned char		hash;
}						t_flag;

typedef struct			s_param
{
	unsigned char		type;
	unsigned char		length;
	int					width;
	int					precision;
	int					printed;
	t_flag				flag;
	va_list				ap;

}						t_param;


int 					ft_nbrlen(int nbr);
int						ft_printf(const char *format, ...);
int						ft_putchar(char c);
int						get_flag(char *str, t_flag *flag);
int						get_precision(char **str);
unsigned char			get_length(char *str);
unsigned char			get_type(char *str);
int						get_width(char *str);
t_param					*get_param(t_param *new_param, char **str);
void					print_param(t_param param);
int						print_item(t_param *param);
int						ft_printf(const char *format, ...);
int						ft_putstr(char *str);
int						ft_itoa_x(uintmax_t nbr, char *_base);
int						conversion(t_param *param);
int						ft_itoa(intmax_t nbr);
int						ft_itoa_o(uintmax_t nbr, char *_base);
int						nbr_length(intmax_t nbr, int base);
int						ft_strlen(char *str);


#endif
