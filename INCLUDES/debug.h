#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <fcntl.h>

typedef unsigned long long ull_t;
typedef long long ll_t;
typedef unsigned char uc_t;

// db m print
void		    db_m_print_ull(ull_t n);
size_t			db_m_print_isin_str(uc_t *is, uc_t *in);
void            *db_m_set(void *s, int c, size_t n);
void            db_m_print(void *ptr, uc_t *mode);
void    		db_m_print_str(void *str, int is_verbose);
void    		db_m_print_str_np(void *str, int is_verbose);
ull_t           db_m_print_atoi_10(uc_t *str);
//

void        *db_m_set(void *s, int c, size_t n);


#endif
