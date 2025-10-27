.section .text

.global phi_paging_enable_paging
/* ... */
phi_paging_enable_paging:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	mov %cr0, %eax
	or $0x80000000, %eax
	mov %eax, %cr0
	
/* ... */
	leave
	ret

.section .note.GNU-stack,"",@progbits