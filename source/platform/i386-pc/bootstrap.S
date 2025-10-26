.set ALIGN, 1<<0
.set MEMINFO, 1<<1
.set FLAGS, ALIGN | MEMINFO
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
/* ... */
phi_stack_bottom:
.skip 16384
.global phi_stack_top
/* ... */
phi_stack_top:

.section .text
.global _start
.type _start, @function
/* ... */
_start:
/* ... */
	mov $phi_stack_top, %esp

/* ... */
	call main

/* ... */
	mov %eax, %ebx

/* ... */
	cli
.L_halt_loop:
	hlt
	jmp .L_halt_loop

.size _start, . - _start
