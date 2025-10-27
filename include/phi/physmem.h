#pragma once

#include <stdint.h>
#include <stddef.h>

/* ... */
int phi_physmem_enable();

/* ... */
int phi_physmem_page_find(uintptr_t *pt_memory_address);

/* ... */
int phi_physmem_page_free(uintptr_t t_memory_address);

/* ... */
int phi_physmem_disable();