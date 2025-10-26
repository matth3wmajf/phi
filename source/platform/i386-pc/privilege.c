#include <stdint.h>
#include <stddef.h>

#include <phi/string.h>
#include <phi/platform/i386-pc/gdt.h>
#include <phi/platform/i386-pc/tss.h>
#include <phi/platform/i386-pc/privilege.h>

/* ... */
extern uint32_t phi_stack_top;

/* ... */
int phi_privilege_enable()
{
/* ... */
	static phi_gdt_entry_t l_gdt_entry_buffer[5];

/* ... */
	static phi_gdt_t l_gdt;

/* ... */
	static phi_tss_entry_t l_tss;

/* ... */
	phi_gdt_set_entry(&l_gdt_entry_buffer[0], 0, 0, 0, 0);

/* ... */
	phi_gdt_set_entry(&l_gdt_entry_buffer[1], 0, 0xFFFFF, 0x9A, 0xCF);

/* ... */
	phi_gdt_set_entry(&l_gdt_entry_buffer[2], 0, 0xFFFFF, 0x92, 0xCF);

/* ... */
	phi_gdt_set_entry(&l_gdt_entry_buffer[3], 0, 0xFFFFF, 0xFA, 0xCF);

/* ... */
	phi_gdt_set_entry(&l_gdt_entry_buffer[4], 0, 0xFFFFF, 0xF2, 0xCF);

/* ... */
	phi_gdt_set_entry(&l_gdt_entry_buffer[5], (uint32_t)(uintptr_t)&l_tss, sizeof(l_tss) - 1, 0x89, 0x40);

/* ... */
	memset(&l_tss, 0, sizeof(l_tss));

/* ... */
	l_tss.t_ss0 = 0x10;

/* ... */
	l_tss.t_esp0 = (uint32_t)(uintptr_t)&phi_stack_top;

/* ... */
	l_gdt.t_base = (uint32_t)(uintptr_t)&l_gdt_entry_buffer;

/* ... */
	l_gdt.t_limit = (sizeof(phi_gdt_entry_t) * (sizeof(l_gdt_entry_buffer) / sizeof(l_gdt_entry_buffer[0]))) - 1;

/* ... */
	phi_gdt_flush(&l_gdt);

/* ... */
	return 0;
}

/* ... */
int phi_privilege_disable()
{
/* ... */
	return 0;
}