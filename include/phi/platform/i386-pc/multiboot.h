#pragma once

#include <stdint.h>
#include <stddef.h>

/* ... */
typedef struct
{
/* ... */
	uint32_t t_flag_bitmask;
/* ... */
	uint32_t t_field0;
/* ... */
	uint32_t t_field1;
/* ... */
	uint32_t t_field2;
/* ... */
	uint32_t t_field3;
/* ... */
	uint32_t t_field4;
/* ... */
	uint32_t t_field5;
/* ... */
	uint32_t t_field6;
/* ... */
	uint32_t t_field7;
/* ... */
	uint32_t t_field8;
/* ... */
	uint32_t t_field9;
/* ... */
	uint32_t t_field10;
/* ... */
	uint32_t t_field11;
/* ... */
	uint32_t t_field12;
/* ... */
	uint32_t t_field13;
/* ... */
	uint32_t t_field14;
/* ... */
	uint32_t t_field15;
/* ... */
	uint32_t t_field16;
/* ... */
	uint32_t t_field17;
/* ... */
	uint32_t t_field18;
/* ... */
	uint16_t t_field19;
/* ... */
	uint16_t t_field20;
/* ... */
	uint16_t t_field21;
/* ... */
	uint16_t t_field22;
} phi_multiboot_information_t;

typedef struct
{
/* ... */
	uint32_t t_field0;

/* ... */
	uint64_t t_field1;

/* ... */
	uint64_t t_field2;

/* ... */
	uint32_t t_field3;
} phi_multiboot_memory_map_t;

/* ... */
extern phi_multiboot_information_t *pg_phi_multiboot_information;