#pragma once

#include <stdint.h>

/* ... */
extern const uint16_t *pg_phi_vga_mode3_display_buffer;

/* ... */
extern const uintmax_t g_phi_vga_mode3_display_buffer_size;

/* ... */
extern const uintmax_t g_phi_vga_mode3_display_width, g_phi_vga_mode3_display_height;

/* ... */
enum
{
	PHI_VGA_MODE3_COLOR_BLACK = 0b0000,
	PHI_VGA_MODE3_COLOR_WHITE = 0b1111
};