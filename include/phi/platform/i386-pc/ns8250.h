#pragma once

#include <stdint.h>

/* ... */
int phi_ns8250_com1_enable();

/* ... */
int phi_ns8250_com1_disable();

/* ... */
int phi_ns8250_com1_input(uint8_t *pt_data);

/* ... */
int phi_ns8250_com1_output(uint8_t t_data);

/* ... */
int phi_ns8250_com1_flush();