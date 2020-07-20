#include "ft_printf.h"

t_cell				*ft_pf_read_mk_cell(t_cell **target, t_cell *previous, char *str)
{
	
	if (!(*target = malloc(sizeof(t_cell))))
		return (NULL);

	(*target)->is_percent = 0;
	(*target)->is_left = 0;
	(*target)->is_signed= 0;
	(*target)->width = 0;
	(*target)->precision = 0;
	(*target)->padding = ' ';
	(*target)->next = NULL;
	(*target)->previous = previous;
	(*target)->start = str;
	(*target)->end = NULL;
	(*target)->type = '0';

	return (*target);
}