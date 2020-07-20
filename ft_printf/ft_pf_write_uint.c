#include "ft_printf.h"

static int			ft_pf_write_uint_hdl(t_cell *list)
{
	int rst;

	rst = 0;
	if (list->is_left)
	{
		rst += ft_pf_write_padding(list->prec_len, '0');
		rst += ft_pf_write_put_base(list->temp, BASE_10);
		rst += ft_pf_write_padding(list->pad_len, list->padding);
	}
	else
	{
		rst += ft_pf_write_padding(list->pad_len, list->padding);
		rst += ft_pf_write_padding(list->prec_len, '0');
		rst += ft_pf_write_put_base(list->temp, BASE_10);
	}
	return rst;
}


int					ft_pf_write_uint(va_list vl, t_cell *list)
{
	if (list->is_left)
		list->padding = ' ';
	if (list->type == 'u')
	{
		list->temp = (unsigned int)va_arg(vl, int);
		list->len = ft_pf_write_nlen(list->temp, 10);
		list->prec_len = list->precision - list->len;
		list->prec_len = (list->prec_len > 0) ? list->prec_len : 0;
		list->pad_len = list->width - list->len - list->prec_len;

		return (ft_pf_write_uint_hdl(list));
	}
	return (0);
}