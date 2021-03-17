ENTRY(_start);

SECTIONS
{
  . = 0x10000;
  .text : { *(.text) }
  .text.execution : { *(.text.execution) }
  . = 0x8000000;
  .data : { *(.data) }
  .bss : { *(.bss) }
}