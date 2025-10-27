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
.global g_phi_stack_bottom
/* ... */
g_phi_stack_bottom:
.skip 16384
.global g_phi_stack_top
/* ... */
g_phi_stack_top:

.section .text

.align 4
/* ... */
g_phi_gdt_structure_bottom:
.quad 0x0000000000000000
.quad 0x00CF9A000000FFFF
.quad 0x00CF92000000FFFF
/* ... */
g_phi_gdt_structure_top:

/* ... */
g_phi_gdt_bottom:
.short g_phi_gdt_structure_top - g_phi_gdt_structure_bottom - 1
.long g_phi_gdt_structure_bottom
/* ... */
g_phi_gdt_top:

.global _start
.type _start, @function
/* ... */
_start:
/* ... */
	cli

/* ... */
	lgdt g_phi_gdt_bottom
	
/* ... */
	ljmp $0x08, $.L_flush_cs_bootstrap
.L_flush_cs_bootstrap:
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss

/* ... */
	mov $g_phi_stack_top, %esp

.global pg_phi_multiboot_information
/* ... */
	mov %ebx, pg_phi_multiboot_information

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

.section .note.GNU-stack,"",@progbits
