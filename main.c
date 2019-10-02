#include "ft_printf.h"
# include <string.h>

int	main()
{
	t_param param;
//	ft_printf("%d", 255);
//	ft_printf("%s", "test string");
	char *str;
	int i;
	i=12;
//	str = strdup("%+0 #-123.56lld hwbuwadbujab wu !<was");
	str = strdup("%+test string");
//	printf("%s\n",str)
//	get_param(&param, &str);
//	print_param(&param);
//	ft_printf("moulitest: %.x %.0X\n",i,i);
	printf("(   %d) \n",ft_printf("%#X",i));
	printf("(   %d) \n",printf("%#X",i));
//	ft_printf("\\n");
//	printf("\\n");
//	ft_printf("%% %d was\n",-i);
//	printf("%lx\n",i);
	//printf*()
//	printf("%s< after\n", str);
	return (0);
}
