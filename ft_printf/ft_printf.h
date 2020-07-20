#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdarg.h>

#define CONV "cspdiuxX%"
#define BASE_10 "0123456789"
#define BASE_16 "0123456789abcdef"
#define BASE_16A "0123456789ABCDEF"

typedef struct s_cell
{
	int is_percent;
	int	is_left;
	int is_signed;
	int is_space;
	char padding;
	int width;
	int precision;
	char type;
	char *start;
	char *end;
	char sign;
	int len;
	int prec_len;
	int pad_len;
	long long temp;
	struct s_cell *next;
	struct s_cell *previous;

}               t_cell;



int					ft_pf_read_format(char **str, t_cell **list, int *count);
int					ft_pf_read_is_in(char c, char *hay_s);
int					ft_pf_read_atoi(char **str, int *count);
t_cell				*ft_pf_read_add_cell(t_cell **list, char *str);
t_cell				*ft_pf_read_mk_cell(t_cell **target, t_cell *previous, char *str);
void				ft_pf_read_free_cell(t_cell **list, t_cell **target);
void				ft_pf_read_is_signed(t_cell *target, char c);
void				ft_pf_read_is_left(t_cell *target, char c);
void				ft_pf_read_is_padding(t_cell *target, char c);
void				ft_pf_read_is_space(t_cell *target, char c);
int					ft_pf_write_n(char *str, int n);
int					ft_printf(char *str, ...);
int					ft_pf_write(va_list vl, t_cell *list);
int					ft_pf_strlen(char *str);
int					ft_pf_write_padding(int n, char c);
int					ft_pf_write_str(va_list vl, t_cell *list);
int					ft_pf_write_hex(va_list vl, t_cell *list);
int					ft_pf_write_put_base(long long n, char *base);
int					ft_pf_write_nlen(long long n, int base);
int					ft_pf_write_ptr(va_list vl, t_cell *list);
int					ft_pf_write_hex_a(va_list vl, t_cell *list);
int					ft_pf_write_get_sign(long long *temp, t_cell *list);
int					ft_pf_write_uint(va_list vl, t_cell *list);
int					ft_pf_write_int(va_list vl, t_cell *list);
int					ft_pf_write_percent(t_cell *list);
int					ft_pf_read(char **str, t_cell **list, int *count);
void				ft_pf_clear(t_cell *list);




#endif

