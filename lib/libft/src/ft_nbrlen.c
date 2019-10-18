#include "libft.h"

int ft_unbrlen(uintmax_t nbr, int base) {
    int len;

    len = 1;
    while (nbr /= base)
        len++;
    return len;
}

int ft_nbrlen(intmax_t nbr) {
	int len;

	len = 1;
	while (nbr /= 10)
		len++;
	return len;
}
