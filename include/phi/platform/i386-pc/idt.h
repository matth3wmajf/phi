#pragma once

#include <stdint.h>
#include <stddef.h>

/* ... */
typedef struct __attribute__((packed))
{
/* ... */
	uint16_t t_base_low;
/* ... */
	uint16_t t_selector;
/* ... */
	uint8_t t_zero;
/* ... */
	uint8_t t_flags;
/* ... */
	uint16_t t_base_high;
} phi_idt_entry_t;

/* ... */
typedef struct __attribute__((packed))
{
/* ... */
	uint16_t t_limit;
/* ... */
	uint32_t t_base;
} phi_idt_t;

/* ... */
int phi_idt_flush(phi_idt_t *pt_structure);

/* ... */
extern void phi_isr_stub0();

/* ... */
extern void phi_isr_stub1();

/* ... */
extern void phi_isr_stub2();

/* ... */
extern void phi_isr_stub3();

/* ... */
extern void phi_isr_stub4();

/* ... */
extern void phi_isr_stub5();

/* ... */
extern void phi_isr_stub6();

/* ... */
extern void phi_isr_stub7();

/* ... */
extern void phi_isr_stub8();

/* ... */
extern void phi_isr_stub9();

/* ... */
extern void phi_isr_stub10();

/* ... */
extern void phi_isr_stub11();

/* ... */
extern void phi_isr_stub12();

/* ... */
extern void phi_isr_stub13();

/* ... */
extern void phi_isr_stub14();

/* ... */
extern void phi_isr_stub15();

/* ... */
extern void phi_isr_stub16();

/* ... */
extern void phi_isr_stub17();

/* ... */
extern void phi_isr_stub18();

/* ... */
extern void phi_isr_stub19();

/* ... */
extern void phi_isr_stub20();

/* ... */
extern void phi_isr_stub21();

/* ... */
extern void phi_isr_stub22();

/* ... */
extern void phi_isr_stub23();

/* ... */
extern void phi_isr_stub24();

/* ... */
extern void phi_isr_stub25();

/* ... */
extern void phi_isr_stub26();

/* ... */
extern void phi_isr_stub27();

/* ... */
extern void phi_isr_stub28();

/* ... */
extern void phi_isr_stub29();

/* ... */
extern void phi_isr_stub30();

/* ... */
extern void phi_isr_stub31();

/* ... */
int phi_idt_set_entry(phi_idt_entry_t *pt_entry, uint32_t t_base, uint16_t t_selector, uint8_t t_flags);

/* ... */
int phi_exception_handler(uint32_t t_interrupt_number, uint32_t t_error_code, uint32_t t_kernel_ds, uint32_t t_kernel_esp, uint32_t t_user_edi, uint32_t t_user_esi, uint32_t t_user_ebp, uint32_t t_user_ebx, uint32_t t_user_edx, uint32_t t_user_ecx, uint32_t t_user_eax, uint32_t t_user_eip, uint32_t t_user_cs, uint32_t t_user_eflags, uint32_t t_user_esp, uint32_t t_user_ss);