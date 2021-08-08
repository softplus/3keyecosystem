# Random infos for clickers

## Links


## Command lines

### Fuses

Calculator: http://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega32u4

Default fuses for device:

LFUSE: 0xFF
  (no)  Clock output on PORTC7; [CKOUT=0]
  (no)  Divide clock by 8 internally; [CKDIV8=0]
  Ext. Crystal Osc.; Frequency 8.0- MHz; Start-up time: 16K CK + 65 ms; [CKSEL=1111 SUT=11]

HFUSE: 0xD8
  Boot Flash size=2048 words start address=$3800; [BOOTSZ=00] ; default value
  (yes) Boot Reset vector Enabled (default address=$0000); [BOOTRST=0]
  (no)  JTAG Interface Enabled; [JTAGEN=0]
  (no)  On-Chip Debug Enabled; [OCDEN=0]
  (no)  Preserve EEPROM memory through the Chip Erase cycle; [EESAVE=0]
  (yes) Serial program downloading (SPI) enabled; [SPIEN=0] *
  (no)  Watchdog timer always on; [WDTON=0]

EFUSE: 0xCB
  Brown-out detection level at VCC=2.6 V; [BODLEVEL=011]
  (no)  Hardware Boot Enable; [HWBE=0]

LOCK:  0x3F - 
  Application Protection Mode 1: No lock on SPM and LPM in Application Section
  Boot Loader Protection Mode 1: No lock on SPM and LPM in Boot Loader Section
  Mode 1: No memory lock features enabled

'''
/home/johannes/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/bin/avrdude -C/home/johannes/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf -v -patmega32u4 -cstk500v1 -P/dev/ttyACM0 -b19200 -e -Ulock:w:0x3F:m -Uefuse:w:0xCB:m -Uhfuse:w:0xD8:m -Ulfuse:w:0xFF:m 
'''


Alternately: Set fuses for outputing CLCK0 on PD7 -> LFUSE = 0xBF

'''
/home/johannes/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/bin/avrdude -C/home/johannes/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf -v -patmega32u4 -cstk500v1 -P/dev/ttyACM0 -b19200 -e -Ulock:w:0x3F:m -Uefuse:w:0xCB:m -Uhfuse:w:0xD8:m -Ulfuse:w:0xBF:m 
'''



