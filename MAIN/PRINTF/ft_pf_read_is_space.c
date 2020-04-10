#include "ft_printf.h"

void				ft_pf_read_is_space(t_cell *target, char c)
{
	if (c == ' ')
		target->is_space = 1;
}