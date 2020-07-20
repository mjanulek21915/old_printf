#include "ft_printf.h"

int					ft_pf_read_is_in(char c, char *hay_s)
{
	while (*hay_s)
	{
		if (*hay_s == c)
			return (1);
		hay_s++;
	}
	return (0);
}