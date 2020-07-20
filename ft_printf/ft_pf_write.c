#include "ft_printf.h"

int					ft_pf_write(va_list vl, t_cell *list)
{
	int rst;

	rst = 0;
	if (list->width == -1)
		list->width = va_arg(vl, int);
	if (list->precision == -1)
		list->precision = va_arg(vl, int);
	rst += ft_pf_write_str(vl, list);
	rst += ft_pf_write_hex(vl, list);
	rst += ft_pf_write_ptr(vl, list);
	rst += ft_pf_write_hex_a(vl, list);
	rst += ft_pf_write_int(vl, list);
	rst += ft_pf_write_uint(vl, list);
	rst += ft_pf_write_percent(list);
	return (rst);
}