#include <stdint.h>
#include <stddef.h>

#include <phi/console.h>
#include <phi/platform/i386-pc/ns8250.h>

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
} g_module_buffer[] = { { .pt_enable = phi_ns8250_com1_enable, .pt_disable = phi_ns8250_com1_disable, .t_status = 0, .pt_module_string = "ns8250" } };

/* ... */
uintmax_t g_module_buffer_size = sizeof(g_module_buffer) / sizeof(g_module_buffer[0]);

/* ... */
const char *pg_phi_build_date_string = __DATE__, *pg_phi_build_time_string = __TIME__;

/* ... */
int main() 
{
/* ... */
	phi_console_t l_console = { .pt_input_function = phi_console_dummy_input, .pt_output_function = phi_console_dummy_output, .pt_flush_function = phi_console_dummy_flush };

/* ... */
	for(uintmax_t l_i = 0; l_i < g_module_buffer_size; l_i++) g_module_buffer[l_i].t_status = g_module_buffer[l_i].pt_enable();

/* ... */
	l_console.pt_input_function = phi_ns8250_com1_input, l_console.pt_output_function = phi_ns8250_com1_output, l_console.pt_flush_function = phi_ns8250_com1_flush;

/* ... */
	phi_console_printf(&l_console, "Copyright (C) Matthew E. Majfud-Wilinski, All Rights Reserved.\nKernel built on %s at %s.\n", pg_phi_build_date_string, pg_phi_build_time_string);

/* ... */
	for(uintmax_t l_i = 0; l_i < g_module_buffer_size; l_i++) if(g_module_buffer[l_i].t_status == 0) g_module_buffer[l_i].t_status = g_module_buffer[l_i].pt_disable();

/* ... */    
	return 0;
}