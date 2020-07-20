#include "ft_printf.h"

int					ft_pf_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}