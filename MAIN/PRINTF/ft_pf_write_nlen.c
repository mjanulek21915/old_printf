#include "ft_printf.h"

int					ft_pf_write_nlen(long long n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n/base;
		i++;
	}
	return (i);
}