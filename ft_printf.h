#ifndef FT_PRINTF
# define FT_PRINTF
# include "lib/libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
//# include "libft.h"


# define BASE_8 "01234567"
# define BASE_16u "0123456789ABCDEF"
# define BASE_16l "0123456789abcdef"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[0;32m"
#define GREEN2   "\e[1;32;45m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\e[00m"

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
	char				*str;
	unsigned char       sign;
	int                 line_size;
	t_flag				flag;
	va_list				ap;


}						t_param;


int 					ft_nbrlen(long long int nbr);
int						ft_printf(const char *format, ...);
int                     ft_unbrlen(uintmax_t nbr);
int						get_flag(const char *str, t_flag *flag);
int						get_precision(char **str, t_param *param);
unsigned char			get_length(const char *str);
unsigned char			get_type(const char *str);
int						get_width(char *str, t_param *param);
t_param					*get_param(t_param *new_param, char **str);
void					print_param(const t_param param);
int						get_item(t_param *param);
int						ft_printf(const char *format, ...);
int                     ft_itoa_u(uintmax_t nbr, t_param *param);
int						ft_itoa_x(uintmax_t nbr, char *_base);
int						conversion(t_param *param);
int						ft_itoa_p(intmax_t nbr, t_param *param);
int						ft_itoa_b(uintmax_t nbr, char *_base, t_param *param);
int						nbr_length(intmax_t nbr, int base);
int						ft_getstr(char *str, t_param *param);
int						ft_getchar(char c, t_param *param);
void                    ft_putstring(const int fd, char *string, unsigned int size);
int						apply_flags(t_param *param);
int						ft_dtoa(long double nbr,t_param *param);
int                     nbr_length_u(uintmax_t nbr, int base);
int                     ft_dtoa_e(long double nbr, t_param *param);

#endif
