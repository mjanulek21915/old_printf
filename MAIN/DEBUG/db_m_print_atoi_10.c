#include "debug.h"

ull_t           db_m_print_atoi_10(uc_t *str)
{
    ull_t temp;

    temp = 0;
    while (*str && *str != '$')
    {
        if (*str >= '0' && *str <= '9')
        {
            temp = temp * 10;
            temp = temp + *str - '0';
        }
        str++;
    }
    if (temp == 0)
        temp = 1;
    return temp;
}