#include "ft_printf.h"
# include <string.h>
#include <limits.h>

//TODO
/*
 * manage %r %k
 * manage skip wrong letters in flag
 * make self ceil function
 *
 * */

int	main()
{

//	t_param param;
//	ft_printf("%d", 255);
//	ft_printf("%s", "test string");
	char *str;
    long double i;
	i=-5.9312312312312312e-12;
    int m;
    m = 112323;
	int j =7;
//	str = ft_strdup("%+0 #-123.56lld hwbuwadbujab wu !<was");
	str = ft_strdup("%+test string");
//	printf("%s\n",str)
//	get_param(&param, &str);
//	print_param(&param);
//	ft_printf("moulitest: %.x %.0X\n",i,i);

    printf("(   %d) \n",ft_printf("{%*c}", -15, 'e'));
    printf("(   %d) \n",printf("{%*s}", -15, ""));
//
//    printf("(   %d) \n",ft_printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l));
//
//
//    str = NULL;
//    printf("(   %d) \n",printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l));
//    printf("(   %d) \n",ft_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l));
//
//
//    str = NULL;
//    printf("(   %d) \n",printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l));
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
