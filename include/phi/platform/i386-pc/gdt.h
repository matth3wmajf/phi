#pragma once

#include <stdint.h>
#include <stddef.h>

/* ... */
typedef struct __attribute__((packed))
{
/* ... */
	uint16_t t_limit_low;
/* ... */
	uint16_t t_base_low;
/* ... */
	uint8_t t_base_middle;
/* ... */
	uint8_t t_access;
/* ... */
	uint8_t t_granularity;
/* ... */
	uint8_t t_base_high;
} phi_gdt_entry_t;

/* ... */
typedef struct __attribute__((packed))
{
/* ... */
	uint16_t t_limit;
/* ... */
	uint32_t t_base;
} phi_gdt_t;

/* ... */
int phi_gdt_flush(phi_gdt_t *pt_structure);

/* ... */
int phi_gdt_set_entry(phi_gdt_entry_t *pt_entry, uint32_t t_base, uint32_t t_limit, uint8_t t_access, uint8_t t_granularity);