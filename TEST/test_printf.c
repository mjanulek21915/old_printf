#include "../MAIN/PRINTF/ft_printf.h"

int pf_test_recursive(unsigned char *str)
{
	if (*str)
	{
		if (pf_test_recursive(str + 1))
		{
			if (*str < 126)
			{
				*str = *str + 1;
				if (*str == '*' || *str == '%' || *str == '"')
					*str = *str + 1;
				return (0);
			}
			else
			{
				*str = 32;
				return (1);
			}
		}
	}
	if(!*str)
		return (1);
	return(0);
}

void pf_test(int depth)
{
	char *str;
	char c;
	int i;
	int rst;
	char str0[40] = "cesi est un stringue";
	char str1[40] = "cesi est un stringue";
	char str2[40] = "cesi est un autre stringue";

	str = malloc(sizeof(char) * (depth + 1));
	str[depth] = 0;
	i = 0;
	rst = 0;

	while (i < depth)
		str[i++] = 32;
	*str = '%';
	while (rst == 0)
	{
		printf("|%s|\n", str);
		// fprintf(stderr, "%s\n", str);
		// ft_printf(str, str0, str2);
		// ft_printf("\n");
		// rst = pf_test_recursive(str + 1);
	}
	// i = 0;
	// rst = 0;
	// while (i < depth)
	// 	str[i++] = 32;
	// while (rst == 0)
	// {
	// 	ft_printf("[%s]\n", str);
	// 	ft_printf(" |");
	// 	// fprintf(stderr, "%s\n", str);
	// 	ft_printf(str, str0, str2);
	// 	ft_printf("|\n");
	// 	rst = pf_test_recursive(str);
	// }
	// i = 0;
	// rst = 0;
	// while (i < depth)
	// 	str[i++] = 32;
	// while (rst == 0)
	// {
	// 	ft_printf("|");
	// 	// fprintf(stderr, "%s\n", str);
	// 	ft_printf(str, str0, str2);
	// 	ft_printf("|\n");
	// 	rst = pf_test_recursive(str);
	// }

}

int main ()
{
	pf_test(4);
	// printf("%4"y");
}