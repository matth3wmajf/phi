#include <stdint.h>
#include <stddef.h>

#include <phi/string.h>

/* ... */
void *memset(void *pt_pointer, int t_value, uint32_t t_size)
{
/* ... */
	unsigned char *pl_pointer = (unsigned char *)pt_pointer;

/* ... */
	for(uint32_t l_i = 0; l_i < t_size; l_i++) pl_pointer[l_i] = (unsigned char)t_value;

/* ... */
	return pt_pointer;
}