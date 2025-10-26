.section .text

.global phi_gdt_flush
/* ... */
phi_gdt_flush:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov 8(%ebp), %eax
	
/* ... */
	lgdt (%eax)

/* ... */
	ljmp $0x08, $.L_flush_cs
.L_flush_cs:
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss

/* ... */
	xor %eax, %eax

/* ... */
	leave
	ret

.global phi_gdt_set_entry
/* ... */
phi_gdt_set_entry:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov 8(%ebp), %edi
	mov 12(%ebp), %eax
	mov 16(%ebp), %ecx
	
/* ... */
	mov %cx, 0(%edi)

/* ... */
	mov %ax, 2(%edi)

/* ... */
	mov %eax, %edx
	shr $16, %edx
	mov %dl, 4(%edi)

/* ... */
	mov %eax, %edx
	shr $24, %edx
	mov %dl, 7(%edi)

/* ... */
	mov 20(%ebp), %edx
	mov %dl, 5(%edi)

/* ... */
	mov %ecx, %edx
	shr $16, %edx
	and $0x0F, %dl
	mov %dl, 6(%edi)

/* ... */
	mov 24(%ebp), %edx
	and $0xF0, %dl
	or %dl, 6(%edi)

/* ... */
	xor %eax, %eax

/* ... */
	leave
	ret

.section .note.GNU-stack,"",@progbits
