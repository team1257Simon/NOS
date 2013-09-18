ENTRY(_stage2_main)
SECTIONS
{
  . = 1K
  .text BLOCK(10K) : ALIGN(10K)
  {
  	*(.text)
  }
  .rodata BLOCK(10K) : ALIGN(10K)
  {
  	*(.rodata)
  }
  .data BLOCK(10K) : ALIGN(10K)
  {
  	*(.data)
  }
}
