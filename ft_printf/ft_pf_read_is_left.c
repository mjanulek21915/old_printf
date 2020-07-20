#include "ft_printf.h"

void				ft_pf_read_is_left(t_cell *target, char c)
{
	if (c == '-')
		target->is_left = 1;
}