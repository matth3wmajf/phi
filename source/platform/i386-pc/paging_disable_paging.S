.section .text

.global phi_paging_disable_paging
/* ... */
phi_paging_disable_paging:
/* ... */
    push %ebp
    mov %esp, %ebp
    
/* ... */
    mov %cr0, %eax
    and $0x7FFFFFFF, %eax 
    mov %eax, %cr0
    
/* ... */
    leave
    ret

.section .note.GNU-stack,"",@progbits