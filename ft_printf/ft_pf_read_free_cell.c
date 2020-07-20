#include "ft_printf.h"

void				ft_pf_read_free_cell(t_cell **list, t_cell **target)
{
// fprintf(stderr, "ft_pf_read_free_cell\n");

	if (*target == *list)
		*list = NULL;
	if ((*target)->previous)
		(*target)->previous->next = NULL;
	free(*target);
	*target = NULL;
}