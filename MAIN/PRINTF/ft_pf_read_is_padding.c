#include "ft_printf.h"

void				ft_pf_read_is_padding(t_cell *target, char c)
{
	if (c == '0')
		target->padding = '0';
}