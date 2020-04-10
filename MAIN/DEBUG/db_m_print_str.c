#include "debug.h"

void		db_m_print_str(void *str, int is_verbose)
{
    uc_t *temp;

    temp = (uc_t *) str;
	if (is_verbose == 1)
	{
		db_m_print_str("debug_print_str : ", 0);
	}
	while (*temp)
	{
		write(1, temp++, 1);
	}
}
