#include "ft_printf.h"

static int			ft_pf_write_int_hdl(t_cell *list)
{
	int rst;

	rst = 0;
	if (list->is_left)
	{
		if (list->is_space && !list->is_signed)
			rst += write(1, " ", 1);
		if (list->sign)
			rst += write(1, &(list->sign), 1);
		rst += ft_pf_write_padding(list->prec_len, '0');
		rst += ft_pf_write_put_base(list->temp, BASE_10);
		rst += ft_pf_write_padding(list->pad_len, list->padding);
	}
	else
	{
		if (list->is_space && !list->is_signed)
			rst += write(1, " ", 1);
		rst += ft_pf_write_padding(list->pad_len, list->padding);
		if (list->sign)
			rst += write(1, &(list->sign), 1);
		rst += ft_pf_write_padding(list->prec_len, '0');
		rst += ft_pf_write_put_base(list->temp, BASE_10);
	}
	return (rst);
}


int					ft_pf_write_int(va_list vl, t_cell *list)
{
	if (list->is_left)
		list->padding = ' ';
	if (list->type == 'd' || list->type == 'i')
	{
		list->temp = (int)va_arg(vl, int);
		list->len = ft_pf_write_nlen(list->temp, 10);
		list->prec_len = list->precision - list->len;
		list->prec_len = (list->prec_len > 0) ? list->prec_len : 0;
		list->len = list->len + ft_pf_write_get_sign(&(list->temp), list);
		list->pad_len = list->width - list->len - list->prec_len;
		return (ft_pf_write_int_hdl(list));
	}
	return (0);
}