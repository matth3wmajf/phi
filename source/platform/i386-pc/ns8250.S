.equ COM1_BASE, 0x3F8
.equ COM1_DATA, COM1_BASE + 0
.equ COM1_IER, COM1_BASE + 1
.equ COM1_FCR, COM1_BASE + 2
.equ COM1_LCR, COM1_BASE + 3
.equ COM1_MCR, COM1_BASE + 4
.equ COM1_LSR, COM1_BASE + 5

.section .text

.global phi_ns8250_com1_enable
/* ... */
phi_ns8250_com1_enable:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov $COM1_IER, %dx
	xor %al, %al
	out %al, %dx

/* ... */
	mov $COM1_LCR, %dx
	mov $0x80, %al
	out %al, %dx

/* ... */
	mov $COM1_DATA, %dx
	mov $0x03, %al
	out %al, %dx
	
/* ... */
	mov $COM1_IER, %dx
	mov $0x00, %al
	out %al, %dx

/* ... */
	mov $COM1_LCR, %dx
	mov $0x03, %al
	out %al, %dx

/* ... */
	mov $COM1_FCR, %dx
	mov $0xC7, %al
	out %al, %dx

/* ... */
	mov $COM1_MCR, %dx
	mov $0x0B, %al
	out %al, %dx

/* ... */
	xor %eax, %eax

/* ... */
	leave
	ret

.global phi_ns8250_com1_disable
/* ... */
phi_ns8250_com1_disable:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov $COM1_IER, %dx
	xor %al, %al
	out %al, %dx

/* ... */
	mov $COM1_MCR, %dx
	xor %al, %al
	out %al, %dx

/* ... */
	xor %eax, %eax

/* ... */
	leave
	ret

.global phi_ns8250_com1_input
/* ... */
phi_ns8250_com1_input:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov $COM1_LSR, %dx
.L_input_wait:
	in %dx, %al
	test $0x01, %al
	jz .L_input_wait

/* ... */
	mov $COM1_DATA, %dx
	in %dx, %al

/* ... */
	mov 8(%ebp), %ecx
	mov %al, (%ecx)

/* ... */
	xor %eax, %eax

/* ... */
	leave
	ret

.global phi_ns8250_com1_output
/* ... */
phi_ns8250_com1_output:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov $COM1_LSR, %dx
.L_output_wait:
	in %dx, %al
	test $0x20, %al
	jz .L_output_wait

/* ... */
	mov 8(%ebp), %eax

/* ... */
	mov $COM1_DATA, %dx
	out %al, %dx

/* ... */
	xor %eax, %eax

/* ... */
	leave
	ret

.global phi_ns8250_com1_flush
/* ... */
phi_ns8250_com1_flush:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	mov $COM1_LSR, %dx
.L_flush_wait:
	in %dx, %al
	test $0x40, %al
	jz .L_flush_wait

/* ... */
	leave
	ret
