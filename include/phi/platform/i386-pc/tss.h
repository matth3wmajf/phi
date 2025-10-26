#pragma once

#include <stdint.h>
#include <stddef.h>

/* ... */
typedef struct __attribute__((packed))
{
/* ... */
	uint32_t t_prev_tss;
/* ... */
	uint32_t t_esp0;
/* ... */
	uint32_t t_ss0;
/* ... */
	uint32_t t_esp1;
/* ... */
	uint32_t t_ss1;
/* ... */
	uint32_t t_esp2;
/* ... */
	uint32_t t_ss2;
/* ... */
	uint32_t t_cr3;
/* ... */
	uint32_t t_eip;
/* ... */
	uint32_t t_eflags;
/* ... */
	uint32_t t_eax;
/* ... */
	uint32_t t_ecx;
/* ... */
	uint32_t t_edx;
/* ... */
	uint32_t t_ebx;
/* ... */
	uint32_t t_esp;
/* ... */
	uint32_t t_ebp;
/* ... */
	uint32_t t_esi;
/* ... */
	uint32_t t_edi;
/* ... */
	uint32_t t_es;
/* ... */
	uint32_t t_cs;
/* ... */
	uint32_t t_ss;
/* ... */
	uint32_t t_ds;
/* ... */
	uint32_t t_fs;
/* ... */
	uint32_t t_gs;
/* ... */
	uint32_t t_ldt;
/* ... */
	uint16_t t_trap;
/* ... */
	uint16_t t_iomap_base;
} phi_tss_entry_t;