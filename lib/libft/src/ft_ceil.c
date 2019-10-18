#include "libft.h"

int ft_ceil(long double nbr) {
    int inbr;
    if (nbr - (inbr = (int) nbr) > .0)
        return inbr + 1;
    return inbr;
}