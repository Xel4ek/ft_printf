#include "ft_printf.h"
# include <string.h>
#include <limits.h>
#include <stdio.h>

int	main()
{

//	t_param param;
//	ft_printf("%d", 255);
//	ft_printf("%s", "test string");
	char *str;
    long double i;
	i=-0.0000009999999999999999998099990e-1121l;

    int m;
    m = 112323;
	int j =7;
//	str = ft_strdup("%+0 #-123.56lld hwbuwadbujab wu !<was");
//	str = ft_strdup("%+test string");
//	printf("%s\n",str)
//	get_param(&param, &str);
//	print_param(&param);
//	ft_printf("moulitest: %.x %.0X\n",i,i);
//    ft_printf("%d\n", ft_ceil(0.0000001));
//    printf("(   %d) \n",ft_printf("{%.*Lf}", 17, i));
//    printf("(   %d) \n",printf("{%.*Lf}", 17, i));
//    printf("(   %d) \n",ft_printf("{%s}", "jasdasdasdasdasdasdasdasdasdaasdddddddddddddddddddddddddddddddddddddddddddddddddddddasdkajksndka\0as123123da"));
//    printf("(   %d) \n",printf("{%s}", "jasdkajksndka\0asda"));
//    printf("(   %d) \n",ft_printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l));
    printf("(   %d) \n",ft_printf("{%.5Le}", i));
    printf("(   %d) \n",printf("{%.5Le}", i));
//    printf("(   %d) \n",ft_printf("{%.1900Lf}", i));
//    printf("(   %d) \n",printf("{%.1900Lf}", i));
    printf("(   %d) \n",ft_printf("{%0+*.*d}",35, 15, 1));
    printf("(   %d) \n",printf("{%0+*.*d}",35, 15, 1));

	printf("(   %d) \n",ft_printf("{%#0+*.*x}",35, 15, 1));
	printf("(   %d) \n",printf("{%#0+*.*x}",35, 15, 1));
	printf("(   %d) \n",ft_printf("{%#0+*.*x}",35, 15, 1));
	printf("(   %d) \n",printf("{%#0+*.*x}",35, 15, 1));
    printf("(   %d) \n",ft_printf("{%#-123k}", "1232-11-21"));

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
