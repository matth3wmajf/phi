#include <stdint.h>
#include <stddef.h>

#include <phi/console.h>

int phi_console_puts(phi_console_t *pt_console, const char *pt_string)
{
/* ... */
	if(pt_console == NULL || pt_console->pt_output_function == NULL || pt_string == NULL) return -1;

/* ... */
	while(*pt_string != '\0')
	{
/* ... */
		if(*pt_string == '\n') pt_console->pt_output_function('\r');

/* ... */
		pt_console->pt_output_function((uint8_t)*pt_string);

/* ... */
		pt_string++;
	}

/* ... */
	return 0;
}