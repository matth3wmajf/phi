#pragma once

#include <stdint.h>
#include <stddef.h>

/* ... */
int phi_i8259_slave_map(uint8_t t_offset);

/* ... */
int phi_i8259_master_map(uint8_t t_offset);

/* ... */
int phi_i8259_irq_set_mask(uint8_t t_irq_line);

/* ... */
int phi_i8259_irq_clear_mask(uint8_t t_irq_line);

/* ... */
int phi_i8259_send_eoi(uint8_t t_irq);

/* ... */
int phi_i8259_enable();

/* ... */
int phi_i8259_disable();