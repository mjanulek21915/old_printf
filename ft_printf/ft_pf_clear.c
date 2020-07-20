#include "ft_printf.h"

void			ft_pf_clear(t_cell *list)
{
	t_cell *temp;

	temp = list;
	while (temp)
	{
		list = temp;
		temp = list->next;
		free(list);
	}
}