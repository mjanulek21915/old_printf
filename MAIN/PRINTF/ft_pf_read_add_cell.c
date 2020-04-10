#include "ft_printf.h"

t_cell				*ft_pf_read_add_cell(t_cell **list, char *str)
{
	t_cell *temp;

	if (!*list)
		return (ft_pf_read_mk_cell(list, NULL, str));
	temp = *list;
	while (temp->next)
		temp = temp->next;
	return (ft_pf_read_mk_cell(&(temp->next), temp, str));
}