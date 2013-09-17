ENTRY(_bst)
OUTPUT_FORMAT(binary)
SECTIONS
{
  . = 0M
  .text BLOCK(512B) : ALIGN(512B)
  {
    St1(.text)
  }
  . = 1K
  .text BLOCK(10K) : ALIGN(10K)
  {
  	St2.Text
  	Ncio(.text)
  	KbGdtIdt(.text)
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
