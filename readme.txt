You have to set the correct memory layout for your device in the linker script.
Please check the FLASH and SRAM length.

e.g.


MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 0x08000   /* 32k */
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 0x01000   /*  4k */
}