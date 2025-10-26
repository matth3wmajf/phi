#pragma once

#include <stdint.h>
#include <stddef.h>

#include <phi/platform/i386-pc/idt.h>

/* ... */
int phi_interrupt_enable();

/* ... */
int phi_interrupt_disable();