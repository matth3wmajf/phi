#include <stdint.h>
#include <stddef.h>

#include <phi/physmem.h>
#include <phi/string.h>
#include <phi/platform/i386-pc/multiboot.h>

/* ... */
const uint32_t g_phi_physmem_page_size = 4096;

/* ... */
uint8_t **ppg_phi_physmem_bitmap_buffer_buffer;

/* ... */
uint32_t *pg_phi_physmem_bitmap_buffer_size_buffer;

/* ... */
uint32_t *pg_phi_physmem_bitmap_count;

/* ... */
uint32_t g_phi_physmem_bitmap_buffer_size_buffer_size;

/* ... */
uintptr_t *pg_phi_physmem_bitmap_address_buffer;

/* ... */
uint32_t g_phi_physmem_bitmap_address_buffer_size;

/* ... */
uintptr_t *pg_phi_physmem_next_bitmap_address_buffer;

/* ... */
uint32_t g_phi_physmem_next_bitmap_address_buffer_size;

/* ... */
extern uint32_t g_phi_kernel_bottom;

/* ... */
extern uint32_t g_phi_kernel_top;

/* ... */
extern uint32_t g_phi_stack_bottom;

/* ... */
extern uint32_t g_phi_stack_top;

/* ... */
int phi_physmem_enable()
{
/* ... */
	if((pg_phi_multiboot_information->t_flag_bitmask & (1 << 6)) == 0) return -1;

/* ... */
	uint32_t l_region_count = 0;

/* ... */
	uint32_t l_total_bitmap_byte_count = 0;

/* ... */
	uintptr_t l_mmap_bottom_address = (uintptr_t)pg_phi_multiboot_information->t_field11;

/* ... */
	uintptr_t l_mmap_top_address = l_mmap_bottom_address + pg_phi_multiboot_information->t_field10;

/* ... */
	uintptr_t l_current_address = l_mmap_bottom_address;

/* ... */
	while(l_current_address < l_mmap_top_address)
	{
/* ... */
		phi_multiboot_memory_map_t *pl_mmap_entry = (phi_multiboot_memory_map_t *)l_current_address;

/* ... */
		if(pl_mmap_entry->t_field3 == 1)
		{
/* ... */
			l_region_count++;

/* ... */
			uint32_t l_page_count = (uint32_t)pl_mmap_entry->t_field2 / g_phi_physmem_page_size;

/* ... */
			l_total_bitmap_byte_count += (l_page_count + 7) / 8;
		}

/* ... */
		l_current_address += pl_mmap_entry->t_field0 + sizeof(uint32_t);
	}

/* ... */
	if(l_region_count == 0) return -1;

/* ... */
	uint32_t l_management_array_size = (l_region_count * sizeof(uint32_t)) + (l_region_count * sizeof(uint32_t)) + (l_region_count * sizeof(uintptr_t)) + (l_region_count * sizeof(uintptr_t)) + (l_region_count * sizeof(uint8_t *));

/* ... */
	uint32_t l_total_required_space = l_management_array_size + l_total_bitmap_byte_count;
	
/* ... */
	l_total_required_space = (l_total_required_space + (g_phi_physmem_page_size - 1)) & ~(g_phi_physmem_page_size - 1);

/* ... */
	uintptr_t l_placement_address = 0;

/* ... */
	uintptr_t l_kernel_top_aligned = ((uintptr_t)&g_phi_kernel_top + (g_phi_physmem_page_size - 1)) & ~(g_phi_physmem_page_size - 1);

/* ... */
	l_current_address = l_mmap_bottom_address;

/* ... */
	while(l_current_address < l_mmap_top_address)
	{
/* ... */
		phi_multiboot_memory_map_t *pl_mmap_entry = (phi_multiboot_memory_map_t *)l_current_address;

/* ... */
		if(pl_mmap_entry->t_field3 == 1)
		{
/* ... */
			uintptr_t l_region_base = (uintptr_t)pl_mmap_entry->t_field1;

/* ... */
			uint32_t l_region_length = (uint32_t)pl_mmap_entry->t_field2;

/* ... */
			uintptr_t l_region_bitmap_address_top = l_region_base + l_region_length;

/* ... */
			uintptr_t l_usable_base = (l_region_base > l_kernel_top_aligned) ? l_region_base : l_kernel_top_aligned;

/* ... */
			l_usable_base = (l_usable_base + (g_phi_physmem_page_size - 1)) & ~(g_phi_physmem_page_size - 1);

/* ... */
			if(l_usable_base < l_region_bitmap_address_top)
			{
/* ... */
				uint32_t l_usable_length = l_region_bitmap_address_top - l_usable_base;

/* ... */
				if(l_usable_length >= l_total_required_space)
				{
/* ... */
					l_placement_address = l_usable_base;

/* ... */
					break;
				}
			}
		}

/* ... */
		l_current_address += pl_mmap_entry->t_field0 + sizeof(uint32_t);
	}

/* ... */
	if(l_placement_address == 0) return -1;

/* ... */
	uint8_t *pl_current_pointer = (uint8_t *)l_placement_address;
	
/* ... */
	pg_phi_physmem_bitmap_buffer_size_buffer = (uint32_t *)pl_current_pointer;

/* ... */
	pl_current_pointer += l_region_count * sizeof(uint32_t);

/* ... */
	pg_phi_physmem_bitmap_count = (uint32_t *)pl_current_pointer;

/* ... */
	pl_current_pointer += l_region_count * sizeof(uint32_t);

/* ... */
	pg_phi_physmem_bitmap_address_buffer = (uintptr_t *)pl_current_pointer;

/* ... */
	pl_current_pointer += l_region_count * sizeof(uintptr_t);

/* ... */
	pg_phi_physmem_next_bitmap_address_buffer = (uintptr_t *)pl_current_pointer;

/* ... */
	pl_current_pointer += l_region_count * sizeof(uintptr_t);

/* ... */
	ppg_phi_physmem_bitmap_buffer_buffer = (uint8_t **)pl_current_pointer;

/* ... */
	pl_current_pointer += l_region_count * sizeof(uint8_t *);

/* ... */
	uint8_t *pl_bitmap_data_pointer = pl_current_pointer;

/* ... */
	uint32_t l_region_index = 0;

/* ... */
	l_current_address = l_mmap_bottom_address;

/* ... */
	while(l_current_address < l_mmap_top_address)
	{
/* ... */
		phi_multiboot_memory_map_t *pl_mmap_entry = (phi_multiboot_memory_map_t *)l_current_address;

/* ... */
		if(pl_mmap_entry->t_field3 == 1)
		{
/* ... */
			uint32_t l_page_count = (uint32_t)pl_mmap_entry->t_field2 / g_phi_physmem_page_size;

/* ... */
			uint32_t l_bitmap_size = (l_page_count + 7) / 8;
			
/* ... */
			pg_phi_physmem_bitmap_address_buffer[l_region_index] = (uintptr_t)pl_mmap_entry->t_field1;

/* ... */
			pg_phi_physmem_bitmap_buffer_size_buffer[l_region_index] = l_bitmap_size;

/* ... */
			pg_phi_physmem_bitmap_count[l_region_index] = l_page_count;

/* ... */
			pg_phi_physmem_next_bitmap_address_buffer[l_region_index] = 0;

/* ... */
			ppg_phi_physmem_bitmap_buffer_buffer[l_region_index] = pl_bitmap_data_pointer;
			
/* ... */
			memset(pl_bitmap_data_pointer, 0, l_bitmap_size);

/* ... */
			pl_bitmap_data_pointer += l_bitmap_size;

/* ... */
			l_region_index++;
		}

/* ... */
		l_current_address += pl_mmap_entry->t_field0 + sizeof(uint32_t);
	}

/* ... */
	g_phi_physmem_bitmap_buffer_size_buffer_size = l_region_count;

/* ... */
	g_phi_physmem_bitmap_address_buffer_size = l_region_count;

/* ... */
	g_phi_physmem_next_bitmap_address_buffer_size = l_region_count;

/* ... */
	uintptr_t l_address;

/* ... */
	for(l_address = (uintptr_t)&g_phi_kernel_bottom; l_address < (uintptr_t)&g_phi_kernel_top; l_address += g_phi_physmem_page_size)
	{
/* ... */
		uintptr_t l_page_address = l_address;

/* ... */
		l_page_address &= ~(g_phi_physmem_page_size - 1);

/* ... */
		for(uint32_t l_i = 0; l_i < g_phi_physmem_bitmap_buffer_size_buffer_size; l_i++)
		{
/* ... */
			uintptr_t l_region_bitmap_address_bottom = pg_phi_physmem_bitmap_address_buffer[l_i];

/* ... */
			uint32_t l_region_bitmap_count = pg_phi_physmem_bitmap_count[l_i];

/* ... */
			uintptr_t l_region_bitmap_address_top = l_region_bitmap_address_bottom + ((uintptr_t)l_region_bitmap_count * g_phi_physmem_page_size);

/* ... */
			if(l_page_address >= l_region_bitmap_address_bottom && l_page_address < l_region_bitmap_address_top)
			{
/* ... */
				uint32_t l_page_index = (l_page_address - l_region_bitmap_address_bottom) / g_phi_physmem_page_size;

/* ... */
				uint32_t l_byte_index = l_page_index / 8;

/* ... */
				uint8_t l_bit_index = l_page_index % 8;

/* ... */
				if(l_byte_index < pg_phi_physmem_bitmap_buffer_size_buffer[l_i])
				{
/* ... */
					ppg_phi_physmem_bitmap_buffer_buffer[l_i][l_byte_index] |= (1 << l_bit_index);

/* ... */
					break;
				}
			}
		}
	}
	
/* ... */
	for(l_address = (uintptr_t)&g_phi_stack_bottom; l_address < (uintptr_t)&g_phi_stack_top; l_address += g_phi_physmem_page_size)
	{
/* ... */
		uintptr_t l_page_address = l_address;

/* ... */
		l_page_address &= ~(g_phi_physmem_page_size - 1);

/* ... */
		for(uint32_t l_i = 0; l_i < g_phi_physmem_bitmap_buffer_size_buffer_size; l_i++)
		{
/* ... */
			uintptr_t l_region_bitmap_address_bottom = pg_phi_physmem_bitmap_address_buffer[l_i];

/* ... */
			uint32_t l_region_bitmap_count = pg_phi_physmem_bitmap_count[l_i];

/* ... */
			uintptr_t l_region_bitmap_address_top = l_region_bitmap_address_bottom + ((uintptr_t)l_region_bitmap_count * g_phi_physmem_page_size);

/* ... */
			if(l_page_address >= l_region_bitmap_address_bottom && l_page_address < l_region_bitmap_address_top)
			{
/* ... */
				uint32_t l_page_index = (l_page_address - l_region_bitmap_address_bottom) / g_phi_physmem_page_size;

/* ... */
				uint32_t l_byte_index = l_page_index / 8;

/* ... */
				uint8_t l_bit_index = l_page_index % 8;

/* ... */
				if(l_byte_index < pg_phi_physmem_bitmap_buffer_size_buffer[l_i])
				{
/* ... */
					ppg_phi_physmem_bitmap_buffer_buffer[l_i][l_byte_index] |= (1 << l_bit_index);

/* ... */
					break;
				}
			}
		}
	}

/* ... */
	for(l_address = l_mmap_bottom_address; l_address < l_mmap_top_address; l_address += g_phi_physmem_page_size)
	{
/* ... */
		uintptr_t l_page_address = l_address;

/* ... */
		l_page_address &= ~(g_phi_physmem_page_size - 1);

/* ... */
		for(uint32_t l_i = 0; l_i < g_phi_physmem_bitmap_buffer_size_buffer_size; l_i++)
		{
/* ... */
			uintptr_t l_region_bitmap_address_bottom = pg_phi_physmem_bitmap_address_buffer[l_i];

/* ... */
			uint32_t l_region_bitmap_count = pg_phi_physmem_bitmap_count[l_i];

/* ... */
			uintptr_t l_region_bitmap_address_top = l_region_bitmap_address_bottom + ((uintptr_t)l_region_bitmap_count * g_phi_physmem_page_size);

/* ... */
			if(l_page_address >= l_region_bitmap_address_bottom && l_page_address < l_region_bitmap_address_top)
			{
/* ... */
				uint32_t l_page_index = (l_page_address - l_region_bitmap_address_bottom) / g_phi_physmem_page_size;

/* ... */
				uint32_t l_byte_index = l_page_index / 8;

/* ... */
				uint8_t l_bit_index = l_page_index % 8;

/* ... */
				if(l_byte_index < pg_phi_physmem_bitmap_buffer_size_buffer[l_i])
				{
/* ... */
					ppg_phi_physmem_bitmap_buffer_buffer[l_i][l_byte_index] |= (1 << l_bit_index);

/* ... */
					break;
				}
			}
		}
	}

/* ... */
	for(l_address = l_placement_address; l_address < (uintptr_t)pl_bitmap_data_pointer; l_address += g_phi_physmem_page_size)
	{
/* ... */
		uintptr_t l_page_address = l_address;

/* ... */
		l_page_address &= ~(g_phi_physmem_page_size - 1);

/* ... */
		for(uint32_t l_i = 0; l_i < g_phi_physmem_bitmap_buffer_size_buffer_size; l_i++)
		{
/* ... */
			uintptr_t l_region_bitmap_address_bottom = pg_phi_physmem_bitmap_address_buffer[l_i];

/* ... */
			uint32_t l_region_bitmap_count = pg_phi_physmem_bitmap_count[l_i];

/* ... */
			uintptr_t l_region_bitmap_address_top = l_region_bitmap_address_bottom + ((uintptr_t)l_region_bitmap_count * g_phi_physmem_page_size);

/* ... */
			if(l_page_address >= l_region_bitmap_address_bottom && l_page_address < l_region_bitmap_address_top)
			{
/* ... */
				uint32_t l_page_index = (l_page_address - l_region_bitmap_address_bottom) / g_phi_physmem_page_size;

/* ... */
				uint32_t l_byte_index = l_page_index / 8;

/* ... */
				uint8_t l_bit_index = l_page_index % 8;

/* ... */
				if(l_byte_index < pg_phi_physmem_bitmap_buffer_size_buffer[l_i])
				{
/* ... */
					ppg_phi_physmem_bitmap_buffer_buffer[l_i][l_byte_index] |= (1 << l_bit_index);

/* ... */
					break;
				}
			}
		}
	}

/* ... */
	return 0;
}

/* ... */
int phi_physmem_page_find(uintptr_t *pt_memory_address)
{
/* ... */
	if(!ppg_phi_physmem_bitmap_buffer_buffer) return -1;

/* ... */
	for(uint32_t l_i = 0; l_i < g_phi_physmem_bitmap_buffer_size_buffer_size; l_i++)
	{
/* ... */
		uint8_t *pl_bitmap_buffer = ppg_phi_physmem_bitmap_buffer_buffer[l_i];

/* ... */
		uint32_t l_bitmap_buffer_size = pg_phi_physmem_bitmap_buffer_size_buffer[l_i];

/* ... */
		uint32_t l_region_bitmap_count = pg_phi_physmem_bitmap_count[l_i];

/* ... */
		uintptr_t l_region_bitmap_address_bottom = pg_phi_physmem_bitmap_address_buffer[l_i];

/* ... */
		uint32_t l_start_byte = pg_phi_physmem_next_bitmap_address_buffer[l_i];

/* ... */
		for(uint32_t l_byte_index = l_start_byte; l_byte_index < l_bitmap_buffer_size; l_byte_index++)
		{
/* ... */
			if(pl_bitmap_buffer[l_byte_index] != 0xFF)
			{
/* ... */
				for(uint8_t l_bit_index = 0; l_bit_index < 8; l_bit_index++)
				{
/* ... */
					if((pl_bitmap_buffer[l_byte_index] & (1 << l_bit_index)) == 0)
					{
/* ... */
						uint32_t l_page_index = (l_byte_index * 8) + l_bit_index;

/* ... */
						if(l_page_index >= l_region_bitmap_count) break;

/* ... */
						pl_bitmap_buffer[l_byte_index] |= (1 << l_bit_index);

/* ... */
						*pt_memory_address = l_region_bitmap_address_bottom + ((uintptr_t)l_page_index * g_phi_physmem_page_size);

/* ... */
						pg_phi_physmem_next_bitmap_address_buffer[l_i] = l_byte_index;

/* ... */
						return 0;
					}
				}
			}
		}

/* ... */
		for(uint32_t l_byte_index = 0; l_byte_index < l_start_byte; l_byte_index++)
		{
/* ... */
			if(pl_bitmap_buffer[l_byte_index] != 0xFF)
			{
/* ... */
				for(uint8_t l_bit_index = 0; l_bit_index < 8; l_bit_index++)
				{
/* ... */
					if((pl_bitmap_buffer[l_byte_index] & (1 << l_bit_index)) == 0)
					{
/* ... */
						uint32_t l_page_index = (l_byte_index * 8) + l_bit_index;

/* ... */
						if(l_page_index >= l_region_bitmap_count) break;

/* ... */
						pl_bitmap_buffer[l_byte_index] |= (1 << l_bit_index);

/* ... */
						*pt_memory_address = l_region_bitmap_address_bottom + ((uintptr_t)l_page_index * g_phi_physmem_page_size);

/* ... */
						pg_phi_physmem_next_bitmap_address_buffer[l_i] = l_byte_index;

/* ... */
						return 0;
					}
				}
			}
		}
	}

/* ... */
	return -1;
}

/* ... */
int phi_physmem_page_free(uintptr_t t_memory_address)
{
/* ... */
	if(!ppg_phi_physmem_bitmap_buffer_buffer) return -1;

/* ... */
	t_memory_address &= ~(g_phi_physmem_page_size - 1);

/* ... */
	for(uint32_t l_i = 0; l_i < g_phi_physmem_bitmap_buffer_size_buffer_size; l_i++)
	{
/* ... */
		uintptr_t l_region_bitmap_address_bottom = pg_phi_physmem_bitmap_address_buffer[l_i];

/* ... */
		uint32_t l_region_bitmap_count = pg_phi_physmem_bitmap_count[l_i];

/* ... */
		uintptr_t l_region_bitmap_address_top = l_region_bitmap_address_bottom + ((uintptr_t)l_region_bitmap_count * g_phi_physmem_page_size);

/* ... */
		if(t_memory_address >= l_region_bitmap_address_bottom && t_memory_address < l_region_bitmap_address_top)
		{
/* ... */
			uint32_t l_page_index = (t_memory_address - l_region_bitmap_address_bottom) / g_phi_physmem_page_size;

/* ... */
			uint32_t l_byte_index = l_page_index / 8;

/* ... */
			uint8_t l_bit_index = l_page_index % 8;

/* ... */
			if(l_byte_index < pg_phi_physmem_bitmap_buffer_size_buffer[l_i])
			{
/* ... */
				uint8_t l_mask = (1 << l_bit_index);
				
/* ... */
				if((ppg_phi_physmem_bitmap_buffer_buffer[l_i][l_byte_index] & l_mask) == 0) return -1;
				
/* ... */
				ppg_phi_physmem_bitmap_buffer_buffer[l_i][l_byte_index] &= ~l_mask;

/* ... */
				if(l_byte_index < pg_phi_physmem_next_bitmap_address_buffer[l_i]) pg_phi_physmem_next_bitmap_address_buffer[l_i] = l_byte_index;

/* ... */
				return 0;
			}
		}
	}

/* ... */
	return -1;
}

/* ... */
int phi_physmem_disable()
{
/* ... */
	ppg_phi_physmem_bitmap_buffer_buffer = NULL;

/* ... */
	pg_phi_physmem_bitmap_buffer_size_buffer = NULL;

/* ... */
	pg_phi_physmem_bitmap_count = NULL;

/* ... */
	g_phi_physmem_bitmap_buffer_size_buffer_size = 0;

/* ... */
	pg_phi_physmem_bitmap_address_buffer = NULL;

/* ... */
	g_phi_physmem_bitmap_address_buffer_size = 0;

/* ... */
	pg_phi_physmem_next_bitmap_address_buffer = NULL;

/* ... */
	g_phi_physmem_next_bitmap_address_buffer_size = 0;

/* ... */
	return 0;
}