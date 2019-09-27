#include "ft_printf.h"
# include <string.h>

int	main()
{
	t_param param;
//	ft_printf("%d", 255);
//	ft_printf("%s", "test string");
	char *str;


	str = strdup("%d hwbuwadbujab wu !");
	printf("%s\n",str);
	get_param(&param, &str);
	print_param(&param);
	printf("%s < after", str);
	return (0);
}
