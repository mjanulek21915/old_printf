#include "ft_printf.h"

int					ft_pf_write_percent(t_cell *list)
{
	if (list->type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}