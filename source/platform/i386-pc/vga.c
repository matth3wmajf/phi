#include <stdint.h>

#include <phi/platform/i386-pc/vga.h>

/* ... */
const uint16_t *pg_phi_vga_mode3_display_buffer = (uint16_t *)0xB8000;

/* ... */
const uint32_t g_phi_vga_mode3_display_buffer_size = 2000;

/* ... */
const uint32_t g_phi_vga_mode3_display_width = 80, g_phi_vga_mode3_display_height = 25;