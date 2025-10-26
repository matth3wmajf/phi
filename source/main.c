#include <stdint.h>
#include <stddef.h>

#include <phi/console.h>
#include <phi/platform/i386-pc/gdt.h>
#include <phi/platform/i386-pc/i8259.h>
#include <phi/platform/i386-pc/ns8250.h>
#include <phi/platform/i386-pc/interrupt.h>
#include <phi/platform/i386-pc/privilege.h>

/* ... */
struct
{
/* ... */
	int (*pt_enable)();

/* ... */
	int (*pt_disable)();

/* ... */
	int t_status;

/* ... */
	const char *pt_module_string;
} g_module_buffer[] = {
	{ .pt_enable = phi_ns8250_com1_enable, .pt_disable = phi_ns8250_com1_disable, .t_status = 0, .pt_module_string = "ns8250" },
	{ .pt_enable = phi_privilege_enable, .pt_disable = phi_privilege_disable, .t_status = 0, .pt_module_string = "privilege" },
	{ .pt_enable = phi_i8259_enable, .pt_disable = phi_i8259_disable, .t_status = 0, .pt_module_string = "i8259" },
	{ .pt_enable = phi_interrupt_enable, .pt_disable = phi_interrupt_disable, .t_status = 0, .pt_module_string = "interrupt" }
};

/* ... */
uintmax_t g_module_buffer_size = sizeof(g_module_buffer) / sizeof(g_module_buffer[0]);

/* ... */
const char *pg_phi_build_date_string = __DATE__, *pg_phi_build_time_string = __TIME__;

/* ... */
int main()
{
/* ... */
	for(uintmax_t l_i = 0; l_i < g_module_buffer_size; l_i++) g_module_buffer[l_i].t_status = g_module_buffer[l_i].pt_enable();

/* ... */
	g_console.pt_input_function = phi_ns8250_com1_input, g_console.pt_output_function = phi_ns8250_com1_output, g_console.pt_flush_function = phi_ns8250_com1_flush;

/* ... */
	phi_console_printf(&g_console, "Copyright (C) Matthew E. Majfud-Wilinski, All Rights Reserved.\nKernel built on %s at %s.\n", pg_phi_build_date_string, pg_phi_build_time_string);

/* ... */
	for(uintmax_t l_i = 0; l_i < g_module_buffer_size; l_i++) if(g_module_buffer[l_i].t_status == 0) g_module_buffer[l_i].t_status = g_module_buffer[l_i].pt_disable();

/* ... */    
	return 0;
}