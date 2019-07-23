# de0-storm-sdram
This is the Storm SoC from opencores.org.  I added the wb_sdram_ctrl to access the DE0-Nano 32MB sdram.

The bootloader_sdram was mofified to upload the "storm_program.bin" via serial to the 0x200.0000 address of the SDRAM.
When the SDRAM Address is loaded into the Program Counter, the Storm ARM Core performs a burst read and the SDRAM 
controller does not handle correctly.

The Storm Core Wishbone Bus Burst lenght can be modified in MC_SYS.vhd (line 507), but anything but 256 and the bootloader
  no longer works.
  
The Stor Core processor has a co-processor interface that allow the modification of the WB Burst length "get_syscpreg(SYS_CTRL_0)"
  changing the SYS_CTRL_l register before loading the Program counter causes the SDRAM controller to read back all 0x0 or 0x0 between
  valid data.
  
Equivalent to ARM700 processor with instruction set armv3 (no recent linux available).

