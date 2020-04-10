#include "ft_printf.h"

int					ft_pf_write_char(va_list vl, t_cell *list)
{
	char temp;
	int len;
	int p_len;
	int rst;

	rst = 0;
	p_len = list->width - 1;
	if (list->type == 'c')
	{
		temp = (char) va_arg(vl, int);
		if (list->is_left)
		{
			rst += write(1, &temp, 1);
			rst += ft_pf_write_padding(p_len, ' ');
		}
		else
		{
			rst += ft_pf_write_padding(p_len, ' ');
			rst += write(1, &temp, 1);
		}
	}
	return (rst);
}