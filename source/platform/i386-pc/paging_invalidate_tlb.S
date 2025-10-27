.section .text

.global phi_paging_invalidate_tlb
/* ... */
phi_paging_invalidate_tlb:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov 8(%ebp), %eax
	invlpg (%eax)

/* ... */
	xor %eax, %eax

/* ... */
	leave
	ret

.section .note.GNU-stack,"",@progbits