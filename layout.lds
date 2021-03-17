ENTRY(_start);

SECTIONS
{
  . = 0x10000;
  _start = .;
  .text : { 
    *(.text.init)
    . = ALIGN(0x1000);
    *(.text) 
  }
  . = ALIGN(0x1000);
  . = 0x80000;
  .data : { *(.data) }
  . = ALIGN(0x1000);
  .bss : { *(.bss) }
}