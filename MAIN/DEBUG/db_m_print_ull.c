#include "debug.h"

ull_t			dp_m_print_ull_rec(ull_t n, ull_t i)
{
	char temp;
	ull_t rst;

	temp = n % 10 + '0';
	if (n > 9)
		rst = dp_m_print_ull_rec(n / 10, i + 1);
	else
	{
		rst = i;
	}
	write(1, &temp, 1);
	return rst;
}

void		db_m_print_ull(ull_t n)
{
	dp_m_print_ull_rec(n, 0);
}