.section .text

.global phi_paging_load_directory
/* ... */
phi_paging_load_directory:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	mov 8(%ebp), %eax
	mov %eax, %cr3
	
/* ... */
	xor %eax, %eax
	
/* ... */
	leave
	ret

.section .note.GNU-stack,"",@progbits