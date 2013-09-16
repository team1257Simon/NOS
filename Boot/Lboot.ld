ENTRY(_bst)
SECTIONS
{
. = 0M
.text BLOCK(512B) : ALIGN(512B)
{
*(.text)
}
}
