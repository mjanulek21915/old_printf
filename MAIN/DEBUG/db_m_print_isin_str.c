#include "debug.h"

size_t			db_m_print_isin_str(uc_t *is, uc_t *in)
{
	size_t i;
    size_t offset;

    offset = 0;
    i = 0;

	while (in[offset])
	{
		if (in[offset] == is[i])
		{
			while (in[offset + i] && is[i] && is[i] == in[offset + i])
				i++;
			if (!is[i])
				return (offset + i);
            i = 0;
		}
		offset++;
	}
	return (-1);
}