#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include <phi/console.h>

phi_console_t g_console = { .pt_input_function = phi_console_dummy_input, .pt_output_function = phi_console_dummy_output, .pt_flush_function = phi_console_dummy_flush };

/* ... */
int phi_console_puts(phi_console_t *pt_console, const char *pt_string)
{
/* ... */
	if(pt_console == NULL || pt_console->pt_output_function == NULL) return -1;

/* ... */
	if(pt_string == NULL) pt_string = "(null)";

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

/* ... */
int phi_console_printf(phi_console_t *pt_console, const char *pt_format, ...)
{
/* ... */
	va_list args;

/* ... */
	if(pt_console == NULL || pt_console->pt_output_function == NULL || pt_format == NULL) return -1;

/* ... */
	va_start(args, pt_format);

/* ... */
	const char *pl_format = pt_format;

/* ... */
	while(*pl_format != '\0')
	{
/* ... */
		if(*pl_format != '%')
		{
/* ... */
			if(*pl_format == '\n') pt_console->pt_output_function('\r');

/* ... */
			pt_console->pt_output_function((uint8_t)*pl_format);

/* ... */
			pl_format++;

/* ... */
			continue;
		}

/* ... */
		pl_format++;

/* ... */
		switch(*pl_format)
		{
/* ... */
			case 'c':
				{
/* ... */
					char l_character = (char)va_arg(args, int); 

/* ... */
					pt_console->pt_output_function((uint8_t)l_character);

/* ... */
					break;
				}
/* ... */
			case 's':
				{
/* ... */
					const char *pl_string = va_arg(args, const char *);

/* ... */
					phi_console_puts(pt_console, pl_string);

/* ... */
					break;
				}
/* ... */
			case '%':
				{
/* ... */
					pt_console->pt_output_function('%');

/* ... */
					break;
				}
/* ... */
			default:
				{
/* ... */
					pt_console->pt_output_function('%');

/* ... */
					pt_console->pt_output_function((uint8_t)*pl_format);

/* ... */
					break;
				}
		}

/* ... */
		pl_format++;
	}

/* ... */
	va_end(args);

/* ... */
	return 0;
}

/* ... */
int phi_console_dummy_input(uint8_t *pt_data)
{
/* ... */
	(void)pt_data;

/* ... */
	return 0;
}

/* ... */
int phi_console_dummy_output(uint8_t t_data)
{
/* ... */
	(void)t_data;

/* ... */
	return 0;
}

/* ... */
int phi_console_dummy_flush()
{
/* ... */
	return 0;
}