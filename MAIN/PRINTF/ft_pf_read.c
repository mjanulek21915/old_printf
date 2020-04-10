#include "ft_printf.h"

int					ft_pf_read(char **str, t_cell **list, int *count)
{
	t_cell *target;

	if (!(target = ft_pf_read_add_cell(list, *str)))
		return (0);
	while (**str == '+' || **str == '-' || **str == '0' || **str == ' ')
	{
		ft_pf_read_is_signed(target, **str);
		ft_pf_read_is_left(target, **str);
		ft_pf_read_is_padding(target, **str);
		ft_pf_read_is_space(target, **str);
		(*str)++;
	}
	target->width = ft_pf_read_atoi(str, count);
	if (**str == '.')
	{
		(*str)++;
		target->precision = ft_pf_read_atoi(str, count);
	}
	if (ft_pf_read_is_in(**str, CONV))
	{

		target->type = **str;
		target->end = (*str) + 1;
		if (**str != '%')
			*count = (*count) + 1;

		return (1);
	}
	*count -= 1;
	ft_pf_read_free_cell(list, &target);
	return (-1);
}