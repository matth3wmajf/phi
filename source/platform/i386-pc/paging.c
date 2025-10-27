#include <stdint.h>
#include <stddef.h>

#include <phi/physmem.h>
#include <phi/string.h>
#include <phi/platform/i386-pc/paging.h>

/* ... */
phi_page_directory_entry_t *pg_phi_paging_kernel_page_directory = NULL;

/* ... */
phi_page_table_entry_t *pg_phi_kernel_initial_page_table = NULL;

/* ... */
const uintptr_t g_phi_page_directory_virtual_address = 0xFFFFF000;

/* ... */
const uintptr_t g_phi_page_table_virtual_address = 0xFFC00000;

/* ... */
int phi_paging_enable()
{
/* ... */
	uintptr_t l_directory_physical_address;

/* ... */
	uintptr_t l_table_physical_address;
	
/* ... */
	if(phi_physmem_page_find(&l_directory_physical_address) != 0) return -1;

/* ... */
	pg_phi_paging_kernel_page_directory = (phi_page_directory_entry_t *)l_directory_physical_address;

/* ... */
	memset(pg_phi_paging_kernel_page_directory, 0, 4096);

/* ... */
	if(phi_physmem_page_find(&l_table_physical_address) != 0) return -1;

/* ... */
	pg_phi_kernel_initial_page_table = (phi_page_table_entry_t *)l_table_physical_address;

/* ... */
	memset(pg_phi_kernel_initial_page_table, 0, 4096);

/* ... */
	for(uint32_t l_i = 0; l_i < 1024; l_i++)
	{
/* ... */
		uintptr_t l_identity_address = l_i * 4096;

/* ... */
		pg_phi_kernel_initial_page_table[l_i] = l_identity_address | PHI_PAGING_FLAG_PRESENT | PHI_PAGING_FLAG_RW;
	}

/* ... */
	pg_phi_paging_kernel_page_directory[0] = l_table_physical_address | PHI_PAGING_FLAG_PRESENT | PHI_PAGING_FLAG_RW;

/* ... */
	pg_phi_paging_kernel_page_directory[1023] = l_directory_physical_address | PHI_PAGING_FLAG_PRESENT | PHI_PAGING_FLAG_RW;

/* ... */
	phi_paging_load_directory(pg_phi_paging_kernel_page_directory);

/* ... */
	phi_paging_enable_paging();

/* ... */
	return 0;
}

/* ... */
int phi_paging_disable()
{
/* ... */
	return 0;
}

/* ... */
int phi_paging_map(uintptr_t t_virtual_address, uintptr_t t_physical_address, uint32_t t_flag_bitmask)
{
/* ... */
	uint32_t l_page_directory_index = t_virtual_address >> 22;

/* ... */
	uint32_t l_page_table_index = (t_virtual_address >> 12) & 0x3FF;

/* ... */
	phi_page_directory_entry_t *pl_page_directory_entry = (phi_page_directory_entry_t *)g_phi_page_directory_virtual_address;

/* ... */
	if((pl_page_directory_entry[l_page_directory_index] & PHI_PAGING_FLAG_PRESENT) == 0)
	{
/* ... */
		uintptr_t l_new_page_table_physical_address;

/* ... */
		if(phi_physmem_page_find(&l_new_page_table_physical_address) != 0) return -1;

/* ... */
		pl_page_directory_entry[l_page_directory_index] = l_new_page_table_physical_address | PHI_PAGING_FLAG_PRESENT | PHI_PAGING_FLAG_RW | PHI_PAGING_FLAG_USER;
		
/* ... */
		phi_paging_invalidate_tlb((uintptr_t)pl_page_directory_entry);

/* ... */
		phi_page_table_entry_t *pl_page_table_entry = (phi_page_table_entry_t *)(g_phi_page_table_virtual_address + (l_page_directory_index * 4096));

/* ... */
		memset(pl_page_table_entry, 0, 4096);
	}

/* ... */
	phi_page_table_entry_t *pl_page_table_entry = (phi_page_table_entry_t *)(g_phi_page_table_virtual_address + (l_page_directory_index * 4096));

/* ... */
	pl_page_table_entry[l_page_table_index] = (t_physical_address & ~0xFFF) | (t_flag_bitmask & 0xFFF) | PHI_PAGING_FLAG_PRESENT;

/* ... */
	phi_paging_invalidate_tlb(t_virtual_address);

/* ... */
	return 0;
}

/* ... */
int phi_paging_unmap(uintptr_t t_virtual_address)
{
/* ... */
	uint32_t l_page_directory_index = t_virtual_address >> 22;

/* ... */
	uint32_t l_page_table_index = (t_virtual_address >> 12) & 0x3FF;

/* ... */
	phi_page_directory_entry_t *pl_page_directory_entry = (phi_page_directory_entry_t *)g_phi_page_directory_virtual_address;

/* ... */
	if((pl_page_directory_entry[l_page_table_index] & PHI_PAGING_FLAG_PRESENT) == 0) return -1;

/* ... */
	phi_page_table_entry_t *pl_page_table_entry = (phi_page_table_entry_t *)(g_phi_page_table_virtual_address + (l_page_directory_index * 4096));

/* ... */
	pl_page_table_entry[l_page_table_index] = 0;

/* ... */
	phi_paging_invalidate_tlb(t_virtual_address);

/* ... */
	return 0;
}