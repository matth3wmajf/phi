#pragma once

#include <stdint.h>
#include <stddef.h>

/* ... */
typedef struct
{
/* ... */
	int (*pt_input_function)(uint8_t *pt_data);

/* ... */
	int (*pt_output_function)(uint8_t t_data);
} phi_console_t;

int phi_console_puts(phi_console_t *pt_console, const char *pt_string);