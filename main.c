#include "ft_printf.h"

int         main(int ac, char **av)
{

    char str[100]="|%    cess|\n";
    char *ptr = str;
    int width = 50;
	int precision = 12;
    long long n = 5;
	int ft;
	int o;
    ft = ft_printf(str, width, precision, 1525);
    o = printf(str, width, precision, 1525);
	printf("fait maison\t:|%d|\n", ft);
	printf("l originel\t:|%d|\n", o);
} 