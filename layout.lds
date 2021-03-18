ENTRY(_start);

SECTIONS
{
  . = 0x8048000;
  _start = .;
  .text : { *(.text) }
  . = 0x9000000;
  _execution_start = .;
  .text.execution : {
    *(.text.execution)
  }
  . += 0x1000;
  _execution_end = .;
  . = ALIGN(0x1000);
  .data : { *(.data) }
  . = ALIGN(0x1000);
  .bss : { *(.bss) }
}