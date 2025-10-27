#pragma once

#include <stdint.h>
#include <stddef.h>

/* ... */
enum
{
	PHI_PAGING_FLAG_PRESENT = (1 << 0),
	PHI_PAGING_FLAG_RW = (1 << 1),
	PHI_PAGING_FLAG_USER = (1 << 2),
	PHI_PAGING_FLAG_WRITETHRU = (1 << 3),
	PHI_PAGING_FLAG_CACHEDISABLE = (1 << 4),
	PHI_PAGING_FLAG_ACCESSED = (1 << 5),
	PHI_PAGING_FLAG_DIRTY = (1 << 6),
	PHI_PAGING_FLAG_4MB = (1 << 7)
};

/* ... */
typedef uint32_t phi_page_table_entry_t;

/* ... */
typedef uint32_t phi_page_directory_entry_t;

/* ... */
extern phi_page_directory_entry_t *pg_phi_paging_kernel_page_directory;

/* ... */
extern phi_page_table_entry_t *pg_phi_kernel_initial_page_table;

/* ... */
int phi_paging_enable();

/* ... */
int phi_paging_disable();

/* ... */
int phi_paging_enable_paging();

/* ... */
int phi_paging_disable_paging();

/* ... */
int phi_paging_load_directory(phi_page_directory_entry_t *pt_directory);

/* ... */
int phi_paging_invalidate_tlb(uintptr_t t_virtual_address);

/* ... */
int phi_paging_map(uintptr_t t_virtual_address, uintptr_t t_physical_address, uint32_t t_flag_bitmask);

/* ... */
int phi_paging_unmap(uintptr_t t_virtual_address);