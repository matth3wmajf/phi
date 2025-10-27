/* ... */
ENTRY(_start)

/* ... */
SECTIONS
{
/* ... */
	. = 2M;

/* ... */
	g_phi_kernel_bottom = .;

/* ... */
	.text BLOCK(4K) : ALIGN(4K)
	{
/* ... */
		*(.multiboot)

/* ... */
		*(.text)
	}

/* ... */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
/* ... */
		*(.rodata)
	}

/* ... */
	.data BLOCK(4K) : ALIGN(4K)
	{
/* ... */
		*(.data)
	}

/* ... */
	.bss BLOCK(4K) : ALIGN(4K)
	{
/* ... */
		*(COMMON)

/* ... */
		*(.bss)
	}

/* ... */
	g_phi_kernel_top = .;
}