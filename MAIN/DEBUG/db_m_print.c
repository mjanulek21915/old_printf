#include "debug.h"

void        db_m_print(void *ptr, uc_t *mode);

void        db_m_print_verbose(void *ptr)
{
    db_m_print_ull((ull_t)ptr);
    db_m_print_str(" - ", 0);
}


void        db_m_print_int(void *ptr)
{
    int temp;

    temp = *((int *)ptr);
    if (temp < 0)
    {
        write(1, "-", 1);
        temp = -(temp);
    }
    db_m_print_ull((ull_t)temp);
}


void        db_m_print_char(void *ptr)
{
    char *temp;

    temp = (char *)ptr;
    write(1, temp, 1);
}

void        db_m_print_byte_dec(void *ptr)
{
    char *temp;

    temp = (char *)ptr;
    db_m_print_ull((ull_t)*temp);
}

void        db_m_print_label(void *ptr, uc_t *mode)
{
    ull_t offset;

    offset = db_m_print_isin_str("$", mode);
    if (offset == -1)
        return ;
    mode = mode + offset;
    while(*mode && *mode != '$')
        write(1, mode++, 1);
}

void        db_m_print_dis_ull(void *ptr)
{
    ull_t *temp;

    temp = ptr;
    db_m_print_ull(*temp);
}

void        db_m_print(void *ptr, uc_t *mode)
{
    ull_t count;
    ull_t i;
    ull_t is_quotes;
    uc_t quote_in[10] = "|";
    uc_t quote_out[10] = "|";

    count = db_m_print_atoi_10(mode);
    i = 0;
    is_quotes = 1;


    while (i < count)
    {
        if (db_m_print_isin_str("-l", mode) != -1)
            db_m_print_label(ptr + i, mode);
        if (db_m_print_isin_str("-v", mode) != -1)
            db_m_print_verbose(ptr + i);
        if (db_m_print_isin_str("-q", mode) != -1)
            is_quotes = 0;
        if (db_m_print_isin_str("-str", mode) != -1)
        {
            if (is_quotes == 1)
                db_m_print_str(quote_in, 0);
            db_m_print_str(ptr + i, 0);
            if (is_quotes == 1)
                db_m_print_str(quote_out, 0);
        }
        else if (db_m_print_isin_str("-int", mode) != -1)
            db_m_print_int(ptr + i);
        else if (db_m_print_isin_str("-char", mode) != -1)
            db_m_print_char(ptr + i);
        else if (db_m_print_isin_str("-np", mode) != -1)
        {
            if (is_quotes == 1)
                db_m_print_str(quote_in, 0);
            db_m_print_str_np(ptr + i, 0);
            if (is_quotes == 1)
                db_m_print_str(quote_out, 0);
        }
        else if (db_m_print_isin_str("-ull", mode) != -1)
            db_m_print_dis_ull(ptr + i);
        else if (((db_m_print_isin_str("-byte", mode) != -1) 
                && (db_m_print_isin_str("-dec", mode) != -1))
            || (db_m_print_isin_str("-DB", mode) != -1))
            db_m_print_byte_dec(ptr + i);
        db_m_print_str("\n", 0);
        i++;
    }
}

// int main ()
// {
//     uc_t mode[100] = "-l -v -str $cesi est un string$";
//     uc_t test[100] = "cesi en est un autre";
//     int n;

//     n = -2;

//     db_m_print(test, mode);
//     db_m_print(&n, "-int");

// }