#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

/* ... */
typedef struct
{
/* ... */
	int (*pt_input_function)(uint8_t *pt_data);

/* ... */
	int (*pt_output_function)(uint8_t t_data);

/* ... */
	int (*pt_flush_function)();
} phi_console_t;

extern phi_console_t g_console;

/* ... */
int phi_console_puts(phi_console_t *pt_console, const char *pt_string);

/* ... */
int phi_console_printf(phi_console_t *pt_console, const char *pt_format, ...);

/* ... */
int phi_console_dummy_input(uint8_t *pt_data);

/* ... */
int phi_console_dummy_output(uint8_t t_data);

/* ... */
int phi_console_dummy_flush();