#include <stdint.h>
#include <stddef.h>

#include <phi/console.h>
#include <phi/platform/i386-pc/ns8250.h>

/* ... */
int main() 
{
/* ... */
	phi_ns8250_com1_enable();

/* ... */
	phi_console_t l_console = { .pt_input_function = phi_ns8250_com1_input, .pt_output_function = phi_ns8250_com1_output };

/* ... */
	phi_console_puts(&l_console, "Copyright (C) Matthew E. Majfud-Wilinski.\nKernel initialized successfully!\n");

/* ... */
	phi_ns8250_com1_flush();

/* ... */
	phi_ns8250_com1_disable();

/* ... */    
	return 0;
}