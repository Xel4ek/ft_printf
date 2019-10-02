#include "ft_printf.h"

int nbr_length(intmax_t nbr, int base)
{
	int len;

	len = 1;
	while (nbr /= base)
		len++;
	return len;
}

int ft_strlen(char *str)
{
	int count;

	count =0;
	while (*str++)
		count++;
	return count;
}

int	ft_itoa_x(uintmax_t nbr, char *_base)
{
	void *adr;
	int i;
	int base = 16;
	int flag;
	char put;
	size_t size;
	flag = 0;
	adr = (void*)(&nbr);
	size = sizeof(nbr);
	int count;

	count = 0;
//	printf("%p\n",&nbr);
//	void *tmp;
//	tmp=(void*)(&nbr);
//	adr = (void*)(&tmp);
//	size = sizeof(&tmp);
//	ft_putstr("0x");
	if (nbr)
		while (size--)
		{
			if ((put = _base[((unsigned char*)adr)[size] / base])!='0' || flag)
			{
				ft_putchar(put);
				flag = 1;
				count++;
			}
			if ((put = _base[((unsigned char*)adr)[size] % base])!='0' || flag)
			{
				ft_putchar(put);
				flag = 1;
				count++;
			}
		}
	else
		return ft_putchar('0');
	return (count);
}

int	ft_itoa_o(uintmax_t nbr, char *_base)
{
	char str[64];
	int len;
	int len_s;
	int base;

	base = ft_strlen(_base);
	len = nbr_length(nbr, base);
	len_s = len;
	str[len] = 0;
	while (len--)
	{
		str[len] = _base[nbr % base];
		nbr /= base;
	}
	ft_putstr(str);
	return (len_s);
}

int	ft_itoa(intmax_t nbr)
{
	char str[64];
	int len;
	int len_s;
	int sign;

	sign = 1;
		len = nbr_length(nbr, 10) + 1;
	if (nbr > 0){
		len--;
		sign = 0;
		nbr = -nbr;
	}
	len_s = len;
	str[len] = 0;
	while (len--)
	{
		str[len] = -nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign)
		*str = '-';
	ft_putstr(str);
	return (len_s);
}
