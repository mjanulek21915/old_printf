#include "ft_printf.h"

int					ft_pf_read_atoi(char **str, int *count)
{
	long long temp;

	temp = 0;

	while (**str == 0)
		(*str)++;
	if (**str == '*')
	{
		*count = *count + 1;
		(*str)++;
		return (-1);
	}
	while (**str >= '0' && **str <= '9')
	{
		temp = temp * 10;
		temp = temp + **str - '0';
		(*str)++;
	}
	return ((int)temp);
}