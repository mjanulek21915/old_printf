#include "ft_printf.h"

int					ft_pf_write_hex(va_list vl, t_cell *list)
{
	long long temp;
	int len;
	int p_len;
	int rst;

	rst = 0;
	if (list->is_left)
		list->padding = ' ';
	if (list->type == 'x')
	{
		temp = (unsigned int)va_arg(vl, int);
		len = ft_pf_write_nlen(temp, 16);
		p_len = list->width - len;
		if (list->is_left)
		{
			rst += ft_pf_write_put_base(temp, BASE_16);
			rst += ft_pf_write_padding(p_len, list->padding);
		}
		else
		{
			rst += ft_pf_write_padding(p_len, list->padding);
			rst += ft_pf_write_put_base(temp, BASE_16);
		}
	}
	return (rst);
}