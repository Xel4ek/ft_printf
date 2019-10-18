#ifndef FT_PRINTF
# define FT_PRINTF
# include "../lib/libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
//# include "libft.h"
# include "data.h"

# define BASE_8 "01234567"
# define BASE_10 "0123456789"
# define BASE_16u "0123456789ABCDEF"
# define BASE_16l "0123456789abcdef"
# define LOG2 0.3010299956639812
# define BASE_NBR_LEN 20
# define DEFAULT_PRECISION 6
#define RED     "\x1b[31m"
#define GREEN   "\x1b[0;32m"
#define GREEN2  "\e[1;32;45m"
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
	char				*str;
	unsigned char       sign;
    int					width;
    int					precision;
	int                 line_size;
	va_list				ap;
	t_flag				flag;
}						t_param;

int						ft_printf(const char *format, ...);
int                     ft_printf_fd(const int fd, const char *format, ...);
int						get_item(t_param *param);
int                     ft_itoa_u(uintmax_t nbr, t_param *param);
int						ft_itoa_p(intmax_t nbr, t_param *param);
int						ft_itoa_b(uintmax_t nbr, char *_base, t_param *param);
int						ft_getstr(char *str, t_param *param);
int						ft_getchar(char c, t_param *param);
int                     string_convertation(t_param *param);
int                     ten_base_int(t_param *param);
int                     hex_base_int(t_param *param);
int                     other_base_int(t_param *param);
int                     double_convertation(t_param *param);
int						apply_flags(t_param *param);
int						ft_dtoa(long double nbr,t_param *param);
int                     ft_dtoa_e(long double nbr, t_param *param);
int                     data_print(char *string, t_param *param);
int                     raw_string(char *string, t_param *param);
int                     get_flag(const char *str, t_flag *flag);
int                     get_width(char *str, t_param *param);
int                     get_precision(char **str, t_param *param);
int                     shift_string(char *str, int max_len);
void                    division_two_e(char *str, int max_len);
void                    add_exponent(t_param *param, int power);
void                    multiply_two(char *str, int max_len);
void                    division_two(char *str, int max_len, int i);
void                    ft_putstring(const int fd, char *string, unsigned int size);
unsigned char           get_length(const char *str);
unsigned char           get_type(const char *str);
t_param					*get_param(t_param *new_param, char **str);


#endif
