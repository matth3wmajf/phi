.section .text

.global phi_idt_flush
/* ... */
phi_idt_flush:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov 8(%ebp), %eax

/* ... */
	lidt (%eax)

/* ... */
	leave
	ret

/* ... */
.L_isr_stub_common:
/* ... */
	push %eax
	push %ecx
	push %edx
	push %ebx
	push %ebp
	push %esi
	push %edi
	
/* ... */
	push %esp
	push %ds
	
/* ... */
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	
/* ... */
	call phi_exception_handle
	
/* ... */
	add $8, %esp
	
/* ... */
	pop %edi
	pop %esi
	pop %ebp
	pop %ebx
	pop %edx
	pop %ecx
	pop %eax
	
/* ... */
	add $8, %esp
	
/* ... */
	iret

.global phi_idt_set_entry
/* ... */
phi_idt_set_entry:
/* ... */
	push %ebp
	mov %esp, %ebp

/* ... */
	mov 8(%ebp), %edi
	mov 12(%ebp), %eax
	mov 16(%ebp), %dx
	
/* ... */
	mov %ax, 0(%edi)

/* ... */
	mov %dx, 2(%edi)

/* ... */
	movb $0, 4(%edi)

/* ... */
	mov 20(%ebp), %ecx
	mov %cl, 5(%edi)

/* ... */
	shr $16, %eax
	mov %ax, 6(%edi)

/* ... */
	xor %eax, %eax
	
/* ... */
	leave
	ret

.global phi_isr_stub0
/* ... */
phi_isr_stub0:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $0

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub1
/* ... */
phi_isr_stub1:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $1

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub2
/* ... */
phi_isr_stub2:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $2

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub3
/* ... */
phi_isr_stub3:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $3

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub4
/* ... */
phi_isr_stub4:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $4

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub5
/* ... */
phi_isr_stub5:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $5

/* ... */
	jmp .L_isr_stub_common

/* ... */
.global phi_isr_stub6
/* ... */
phi_isr_stub6:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $6

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub7
/* ... */
phi_isr_stub7:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $7

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub8
/* ... */
phi_isr_stub8:
/* ... */
	cli

/* ... */
	push $8

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub9
/* ... */
phi_isr_stub9:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $9

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub10
/* ... */
phi_isr_stub10:
/* ... */
	cli

/* ... */
	push $10

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub11
/* ... */
phi_isr_stub11:
/* ... */
	cli

/* ... */
	push $11

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub12
/* ... */
phi_isr_stub12:
/* ... */
	cli
	
/* ... */
	push $12
	
/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub13
/* ... */
phi_isr_stub13:
/* ... */
	cli

/* ... */
	push $13

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub14
/* ... */
phi_isr_stub14:
/* ... */
	cli

/* ... */
	push $14

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub15
/* ... */
phi_isr_stub15:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $15

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub16
/* ... */
phi_isr_stub16:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $16

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub17
/* ... */
phi_isr_stub17:
/* ... */
	cli

/* ... */
	push $17

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub18
/* ... */
phi_isr_stub18:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $18

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub19
/* ... */
phi_isr_stub19:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $19

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub20
/* ... */
phi_isr_stub20:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $20

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub21
/* ... */
phi_isr_stub21:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $21

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub22
/* ... */
phi_isr_stub22:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $22

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub23
/* ... */
phi_isr_stub23:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $23

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub24
/* ... */
phi_isr_stub24:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $24

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub25
/* ... */
phi_isr_stub25:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $25

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub26
/* ... */
phi_isr_stub26:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $26

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub27
/* ... */
phi_isr_stub27:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $27

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub28
/* ... */
phi_isr_stub28:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $28

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub29
/* ... */
phi_isr_stub29:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $29

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub30
/* ... */
phi_isr_stub30:
/* ... */
	cli

/* ... */
	push $30

/* ... */
	jmp .L_isr_stub_common

.global phi_isr_stub31
/* ... */
phi_isr_stub31:
/* ... */
	cli

/* ... */
	push $0

/* ... */
	push $31

/* ... */
	jmp .L_isr_stub_common

.section .note.GNU-stack,"",@progbits
