#include "ft_printf.h"

int			ft_pf_write_get_sign(long long *temp, t_cell *list)
{
	if (*temp < 0)
	{
		list->sign = '-';
		*temp = -*temp;
		return (1);
	}
	else if (list->is_signed)
	{
		list->sign = '+';
		return (1);
	}
	else if (list->is_space)
	{
		list->sign = 0;
		return (1);
	}
	list->sign = 0;
	return (0);
}