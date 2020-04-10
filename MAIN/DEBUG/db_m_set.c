#include "debug.h"

void        *db_m_set(void *s, int c, size_t n)
{
    uc_t *temp;
    uc_t temp_c;

    temp = (uc_t *)s;
    temp_c = (uc_t)c;

    while (n-- > 0)
        *temp++ = temp_c;
}