#include "ft_printf.h"
# include <string.h>

int	main()
{

//	t_param param;
//	ft_printf("%d", 255);
//	ft_printf("%s", "test string");
	char *str;
    long double i;
	i=.001l;

	int j =7;
//	str = ft_strdup("%+0 #-123.56lld hwbuwadbujab wu !<was");
	str = ft_strdup("%+test string");
//	printf("%s\n",str)
//	get_param(&param, &str);
//	print_param(&param);
//	ft_printf("moulitest: %.x %.0X\n",i,i);

    printf("(   %d) \n",ft_printf("%.12Lf",i));
    printf("(   %d) \n",printf("%.1200Lf",i));
	// printf("(   %d) \n",ft_printf("%o\n",16));
	//printf("(   %d) \n",printf("%f",i));
	// print_param(param);
//	ft_printf("\\n");
//	printf("\\n");
//	ft_printf("%% %d was\n",-i);
//	printf("%lx\n",i);
	//printf*()
//	printf("%s< after\n", str);
	return (0);
}
