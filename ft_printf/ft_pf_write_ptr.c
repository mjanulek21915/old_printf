#include "ft_printf.h"

static int			ft_pf_write_int_hdl_hdl(t_cell *list)
{
	int rst;

	rst = 0;
	if (list->is_space && !list->is_signed)
	{
		rst += write(1, " ", 1);
		list->pad_len--;
	}
	return (rst);
}

static int			ft_pf_write_ptr_hdl(t_cell *list)
{
	int rst;

	rst = 0;
	if (list->is_left)
	{
		rst += ft_pf_write_int_hdl_hdl(list);
		if (list->sign)
			rst += write(1, &(list->sign), 1);
		rst += write(1, "0x", 2);
		rst += ft_pf_write_put_base(list->temp, BASE_16);
		rst += ft_pf_write_padding(list->pad_len, list->padding);
	}
	else
	{
		rst += ft_pf_write_padding(list->pad_len, list->padding);
		rst += ft_pf_write_int_hdl_hdl(list);
		if (list->sign)
			rst += write(1, &(list->sign), 1);
		rst += write(1, "0x", 2);
		rst += ft_pf_write_put_base(list->temp, BASE_16);
	}
	return (rst);
}
int					ft_pf_write_ptr(va_list vl, t_cell *list)
{
	if (list->is_left)
		list->padding = ' ';
	if (list->type == 'p')
	{
		list->temp = (unsigned long)va_arg(vl, long int);
		list->len = ft_pf_write_nlen(list->temp, 16);
		list->prec_len = list->precision - list->len;
		list->len += ft_pf_write_get_sign(&(list->temp), list);
		list->pad_len = list->width - list->len - 2;
		return (ft_pf_write_ptr_hdl(list));
	}
	return (0);
}