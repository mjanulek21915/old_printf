#include "ft_printf.h"

static void			ft_pf_read_hdl(char *str, t_cell **list, int *arg_count)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!(ft_pf_read(&str, list, arg_count)))
				return ;
		}
		str++;
	}
}

static int			ft_pf_write_hdl(char *str, t_cell *list, va_list vl)
{
	t_cell *old_list;
	int n_count;
	int rst;

	rst = 0;
	if (list)
	{
		old_list = list;
		while (list)
		{
			n_count = list->start - 1 - str;
			rst += ft_pf_write_n(str, n_count);
			rst += ft_pf_write(vl, list);
			str = list->end;
			list = list->next;
		}
		rst += ft_pf_write_n(str, -1);
		ft_pf_clear(old_list);
	}
	else
		rst += ft_pf_write_n(str, -1);
	return (rst);
}


int				ft_printf(char *str, ...)
{
	t_cell *list;
	va_list vl;
	int arg_count;

	arg_count = 0;
	list = NULL;
	ft_pf_read_hdl(str, &list, &arg_count);
	va_start(vl, str);
	return (ft_pf_write_hdl(str, list, vl));
}