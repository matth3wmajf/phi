.section .text

.global phi_tss_flush
/* ... */
phi_tss_flush:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov 8(%ebp), %ax

/* ... */
	ltr %ax

/* ... */
	xor %eax, %eax

/* ... */
	leave
	ret