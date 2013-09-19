ENTRY(_stage2_main)
SECTIONS
{
	. = 1K;
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.text)
	}
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}
}
