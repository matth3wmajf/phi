.equ PIC1_CMD, 0x20
.equ PIC1_DATA, 0x21
.equ PIC2_CMD, 0xA0
.equ PIC2_DATA, 0xA1

.equ PIC_EOI, 0x20

.equ ICW1_INIT, 0x10
.equ ICW1_ICW4, 0x01
.equ ICW4_8086, 0x01

.section .text

.global phi_i8259_master_map
/* ... */
phi_i8259_master_map:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	push %eax
	
/* ... */
	in $PIC1_DATA, %al
	
/* ... */
	push %eax
	
/* ... */
	mov $(ICW1_INIT | ICW1_ICW4), %al
	out %al, $PIC1_CMD
	
/* ... */
	mov 8(%ebp), %eax
	out %al, $PIC1_DATA
	
/* ... */
	mov $0x04, %al
	out %al, $PIC1_DATA
	
/* ... */
	mov $ICW4_8086, %al
	out %al, $PIC1_DATA
	
/* ... */
	pop %eax
	
/* ... */
	out %al, $PIC1_DATA
	
/* ... */
	pop %eax
	
/* ... */
	xor %eax, %eax
	
/* ... */
	leave
	ret

.global phi_i8259_slave_map
/* ... */
phi_i8259_slave_map:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	push %eax
	
/* ... */
	in $PIC2_DATA, %al
	
/* ... */
	push %eax
	
/* ... */
	mov $(ICW1_INIT | ICW1_ICW4), %al
	out %al, $PIC2_CMD
	
/* ... */
	mov 8(%ebp), %eax
	out %al, $PIC2_DATA
	
/* ... */
	mov $0x02, %al
	out %al, $PIC2_DATA
	
/* ... */
	mov $ICW4_8086, %al
	out %al, $PIC2_DATA
	
/* ... */
	pop %eax
	
/* ... */
	out %al, $PIC2_DATA
	
/* ... */
	pop %eax
	
/* ... */
	xor %eax, %eax
	
/* ... */
	leave
	ret

.global phi_i8259_irq_set_mask
/* ... */
phi_i8259_irq_set_mask:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	mov 8(%ebp), %eax
	mov %al, %cl
	
/* ... */
	mov $PIC1_DATA, %dx
	
/* ... */
	cmp $8, %cl
	jb .L_set_mask
	
/* ... */
	mov $PIC2_DATA, %dx
	sub $8, %cl
.L_set_mask:
	in %dx, %al
	
/* ... */
	mov $1, %ah
	shlb %cl, %ah
	
/* ... */
	or %ah, %al
	
/* ... */
	out %al, %dx
	
/* ... */
	xor %eax, %eax
	
/* ... */
	leave
	ret

.global phi_i8259_irq_clear_mask
/* ... */
phi_i8259_irq_clear_mask:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	mov 8(%ebp), %eax
	mov %al, %cl
	
/* ... */
	mov $PIC1_DATA, %dx
	
/* ... */
	cmp $8, %cl
	jb .L_clear_mask
	
/* ... */
	mov $PIC2_DATA, %dx
	sub $8, %cl
.L_clear_mask:
	in %dx, %al
	
/* ... */
	mov $1, %ah
	shlb %cl, %ah
	
/* ... */
	not %ah
	
/* ... */
	and %ah, %al
	
/* ... */
	out %al, %dx
	
/* ... */
	xor %eax, %eax
	
/* ... */
	leave
	ret

.global phi_i8259_send_eoi
/* ... */
phi_i8259_send_eoi:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	mov 8(%ebp), %eax
	
/* ... */
	cmp $8, %al
	jb .L_eoi_master
	
/* ... */
	mov $PIC_EOI, %al
	out %al, $PIC2_CMD
.L_eoi_master:
	mov $PIC_EOI, %al
	out %al, $PIC1_CMD
	
/* ... */
	xor %eax, %eax
	
/* ... */
	leave
	ret

.global phi_i8259_enable
/* ... */
phi_i8259_enable:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	push $32
	call phi_i8259_master_map
	add $4, %esp
	
/* ... */
	push $40
	call phi_i8259_slave_map
	add $4, %esp
	
/* ... */
	push $0
	call phi_i8259_irq_clear_mask
	add $4, %esp
	
/* ... */
	xor %eax, %eax
	
/* ... */
	leave
	ret

.global phi_i8259_disable
/* ... */
phi_i8259_disable:
/* ... */
	push %ebp
	mov %esp, %ebp
	
/* ... */
	push %ecx
	
/* ... */
	xor %ecx, %ecx
.L_disable_loop:
	cmp $16, %ecx
	jge .L_disable_done
	
/* ... */
	push %ecx
	call phi_i8259_irq_set_mask
	add $4, %esp
	
/* ... */
	inc %ecx
	jmp .L_disable_loop
.L_disable_done:
	pop %ecx
	
/* ... */
	xor %eax, %eax
	
/* ... */
	leave
	ret

.section .note.GNU-stack,"",@progbits
