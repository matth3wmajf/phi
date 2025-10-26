#include <stdint.h>
#include <stddef.h>

#include <phi/string.h>
#include <phi/console.h>
#include <phi/platform/i386-pc/idt.h>
#include <phi/platform/i386-pc/interrupt.h>

/* ... */
int phi_interrupt_enable()
{
/* ... */
	static phi_idt_entry_t l_idt_entry_buffer[256];

/* ... */
	static phi_idt_t l_idt;

/* ... */
	l_idt.t_limit = (sizeof(phi_idt_entry_t) * 256) - 1;

/* ... */
	l_idt.t_base = (uint32_t)(uintptr_t)&l_idt_entry_buffer;

/* ... */
	memset(&l_idt_entry_buffer, 0, sizeof(l_idt_entry_buffer));

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[0], (uint32_t)(uintptr_t)phi_isr_stub0, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[1], (uint32_t)(uintptr_t)phi_isr_stub1, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[2], (uint32_t)(uintptr_t)phi_isr_stub2, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[3], (uint32_t)(uintptr_t)phi_isr_stub3, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[4], (uint32_t)(uintptr_t)phi_isr_stub4, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[5], (uint32_t)(uintptr_t)phi_isr_stub5, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[6], (uint32_t)(uintptr_t)phi_isr_stub6, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[7], (uint32_t)(uintptr_t)phi_isr_stub7, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[8], (uint32_t)(uintptr_t)phi_isr_stub8, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[9], (uint32_t)(uintptr_t)phi_isr_stub9, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[10], (uint32_t)(uintptr_t)phi_isr_stub10, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[11], (uint32_t)(uintptr_t)phi_isr_stub11, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[12], (uint32_t)(uintptr_t)phi_isr_stub12, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[13], (uint32_t)(uintptr_t)phi_isr_stub13, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[14], (uint32_t)(uintptr_t)phi_isr_stub14, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[15], (uint32_t)(uintptr_t)phi_isr_stub15, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[16], (uint32_t)(uintptr_t)phi_isr_stub16, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[17], (uint32_t)(uintptr_t)phi_isr_stub17, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[18], (uint32_t)(uintptr_t)phi_isr_stub18, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[19], (uint32_t)(uintptr_t)phi_isr_stub19, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[20], (uint32_t)(uintptr_t)phi_isr_stub20, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[21], (uint32_t)(uintptr_t)phi_isr_stub21, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[22], (uint32_t)(uintptr_t)phi_isr_stub22, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[23], (uint32_t)(uintptr_t)phi_isr_stub23, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[24], (uint32_t)(uintptr_t)phi_isr_stub24, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[25], (uint32_t)(uintptr_t)phi_isr_stub25, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[26], (uint32_t)(uintptr_t)phi_isr_stub26, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[27], (uint32_t)(uintptr_t)phi_isr_stub27, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[28], (uint32_t)(uintptr_t)phi_isr_stub28, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[29], (uint32_t)(uintptr_t)phi_isr_stub29, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[30], (uint32_t)(uintptr_t)phi_isr_stub30, 0x08, 0x8E);

/* ... */
	phi_idt_set_entry(&l_idt_entry_buffer[31], (uint32_t)(uintptr_t)phi_isr_stub31, 0x08, 0x8E);

/* ... */
	phi_idt_flush(&l_idt);

/* ... */
	return 0;
}

/* ... */
int phi_interrupt_disable()
{
/* ... */
	return 0;
}

/* ... */
int phi_exception_handle(uint32_t t_interrupt_number, uint32_t t_error_code, uint32_t t_kernel_ds, uint32_t t_kernel_esp, uint32_t t_user_edi, uint32_t t_user_esi, uint32_t t_user_ebp, uint32_t t_user_ebx, uint32_t t_user_edx, uint32_t t_user_ecx, uint32_t t_user_eax, uint32_t t_user_eip, uint32_t t_user_cs, uint32_t t_user_eflags, uint32_t t_user_esp, uint32_t t_user_ss)
{
/* ... */
	(void)t_interrupt_number;

/* ... */
	(void)t_error_code;

/* ... */
	(void)t_kernel_ds;

/* ... */
	(void)t_kernel_esp;

/* ... */
	(void)t_user_edi;

/* ... */
	(void)t_user_esi;

/* ... */
	(void)t_user_ebp;

/* ... */
	(void)t_user_ebx;

/* ... */
	(void)t_user_edx;

/* ... */
	(void)t_user_ecx;

/* ... */
	(void)t_user_eax;

/* ... */
	(void)t_user_eip;

/* ... */
	(void)t_user_cs;

/* ... */
	(void)t_user_eflags;

/* ... */
	(void)t_user_esp;

/* ... */
	(void)t_user_ss;

/* ... */
	return 0;
}