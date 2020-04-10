#include "ft_printf.h"

int					ft_pf_write_str(va_list vl, t_cell *list)
{
	char *temp;
	int len;
	int p_len;
	int rst;

	if (list->type == 's')
	{
		temp = va_arg(vl, char *);
		len = ft_pf_strlen(temp);
		p_len = list->width - len;
		rst = len + p_len;
		if (list->is_left)
		{
			ft_pf_write_n(temp, len);
			ft_pf_write_padding(p_len, ' ');
		}
		else
		{
			ft_pf_write_padding(p_len, ' ');
			ft_pf_write_n(temp, len);
		}
		return (rst);
	}
	return (0);
}