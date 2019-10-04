#include "ft_printf.h"
# include <string.h>

int	main()
{
//	t_param param;
//	ft_printf("%d", 255);
//	ft_printf("%s", "test string");
	char *str;
	double i;
	i=1/3.;
//	str = strdup("%+0 #-123.56lld hwbuwadbujab wu !<was");
	str = strdup("%+test string");
//	printf("%s\n",str)
//	get_param(&param, &str);
//	print_param(&param);
//	ft_printf("moulitest: %.x %.0X\n",i,i);
	printf("(   %d) \n",ft_printf("%f",i));
	printf("(   %d) \n",ft_printf("%f",i*2.));
	printf("(   %d) \n",ft_printf("%f",i*4.));
	printf("(   %d) \n",ft_printf("%f",i*8.));
	printf("(   %d) \n",ft_printf("%f",i*16.));
	// printf("(   %d) \n",ft_printf("%o\n",16));
	printf("(   %d) \n",printf("%f",i));
	// print_param(param);
//	ft_printf("\\n");
//	printf("\\n");
//	ft_printf("%% %d was\n",-i);
//	printf("%lx\n",i);
	//printf*()
//	printf("%s< after\n", str);
	return (0);
}
