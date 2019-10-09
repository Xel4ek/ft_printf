#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"
# define BASE_8 "01234567"
# define BASE_16u "0123456789ABCDEF"
# define BASE_16l "0123456789abcdef"
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
	char				*str;
	unsigned char       sign;
	t_flag				flag;
	va_list				ap;

}						t_param;


int 					ft_nbrlen(int nbr);
int						ft_printf(const char *format, ...);

int						get_flag(char *str, t_flag *flag);
int						get_precision(char **str);
unsigned char			get_length(char *str);
unsigned char			get_type(char *str);
int						get_width(char *str, t_param *param);
t_param					*get_param(t_param *new_param, char **str);
void					print_param(t_param param);
int						print_item(t_param *param);
int						ft_printf(const char *format, ...);

int						ft_itoa_x(uintmax_t nbr, char *_base);
int						conversion(t_param *param);
int						ft_itoa_p(intmax_t nbr, t_param *param);
int						ft_itoa_b(uintmax_t nbr, char *_base, t_param *param);
int						nbr_length(intmax_t nbr, int base);
int						 ft_getstr(char *str, t_param *param);
int						ft_getchar(char c, t_param *param);

char					*ft_strjoin(char const *s1, char const *s2);
int						apply_flags(t_param *param);
int						ft_dtoa(double nbr,t_param *param);


#endif
