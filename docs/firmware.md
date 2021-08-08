# Firmware notes

Before installing the Caterina firmware, check that the device works.

## Checking basic hardware functionality

Requirements:

* Arduino UI
* ICSP programmer (I use an Arduino Uno + a breakout for the ICSP pins)
* Your "kbmount" board (before mating it to a keyboard layout)

1. Get https://github.com/nickgammon/arduino_sketches/tree/master/Atmega_Board_Detector
2. Plug the ICSP in 
3. Run Atmega_Board_Detector.ino in Arduino matching your ICSP setup
4. Open the Serial monitor

You should see something like this:

```
18:37:00.891 -> Atmega chip detector.
18:37:00.891 -> Written by Nick Gammon.
18:37:00.924 -> Version 1.20
18:37:00.924 -> Compiled on Jul 31 2021 at 18:36:49 with Arduino IDE 10813.
18:37:00.924 -> Attempting to enter ICSP programming mode ...
18:37:01.024 -> Entered programming mode OK.
18:37:01.057 -> Signature = 0x1E 0x95 0x87 
18:37:01.057 -> Processor = ATmega32U4
18:37:01.057 -> Flash memory size = 32768 bytes.
18:37:01.057 -> LFuse = 0xFF 
18:37:01.057 -> HFuse = 0xD8 
18:37:01.057 -> EFuse = 0xFD 
18:37:01.057 -> Lock byte = 0xFF 
18:37:01.057 -> Clock calibration = 0x6D 
18:37:01.057 -> Bootloader in use: Yes
18:37:01.057 -> EEPROM preserved through erase: No
18:37:01.057 -> Watchdog timer always on: No
18:37:01.057 -> Bootloader is 4096 bytes starting at 7000
18:37:01.057 -> 
18:37:01.057 -> Bootloader:
18:37:01.057 -> 
18:37:01.057 -> 7000: 0x55 0xC0 0x00 0x00 0x6E 0xC0 0x00 0x00 0x6C 0xC0 0x (...)
```

The thing to watch out for is that it recognizes the processor = ATmega32U4. 
The fuses & the bootloader's tons of hex is irrelevant for us.
If this works, your device is at least partially working.

## Plug-in test

Are you feeling lucky? Open a terminal window with `tail -f /var/log/syslog` and plug the device in.
With the default firmware it should still be recognized as a keyboard.

```
Jul 31 19:43:14 johannes-GXU kernel: [826254.945675] usb 1-8: new full-speed USB device number 63 using xhci_hcd
Jul 31 19:43:14 johannes-GXU kernel: [826255.096955] usb 1-8: New USB device found, idVendor=2341, idProduct=8036, bcdDevice= 1.00
Jul 31 19:43:14 johannes-GXU kernel: [826255.096960] usb 1-8: New USB device strings: Mfr=1, Product=2, SerialNumber=0
Jul 31 19:43:14 johannes-GXU kernel: [826255.096963] usb 1-8: Product: Arduino Leonardo
Jul 31 19:43:14 johannes-GXU kernel: [826255.096966] usb 1-8: Manufacturer: Arduino LLC
Jul 31 19:43:14 johannes-GXU kernel: [826255.102399] cdc_acm 1-8:1.0: ttyACM0: USB ACM device
Jul 31 19:43:14 johannes-GXU kernel: [826255.104512] input: Arduino LLC Arduino Leonardo Mouse as /devices/pci0000:00/0000:00:14.0/usb1/1-8/1-8:1.2/0003:2341:8036.0048/input/input279
Jul 31 19:43:14 johannes-GXU kernel: [826255.104965] input: Arduino LLC Arduino Leonardo Keyboard as /devices/pci0000:00/0000:00:14.0/usb1/1-8/1-8:1.2/0003:2341:8036.0048/input/input280
Jul 31 19:43:14 johannes-GXU kernel: [826255.161883] hid-generic 0003:2341:8036.0048: input,hidraw5: USB HID v1.01 Mouse [Arduino LLC Arduino Leonardo] on usb-0000:00:14.0-8/input2
```

## Installing Caterina bootloader (optional)

The [Caterina](https://github.com/adafruit/Caterina-Bootloader) bootloader makes it a bit easier to test & program the ATmega32U4. 
Technically you don't need it. 
However, having it makes it easy to use the Arduino UI for testing.

1. Pull the [Caterina repo](https://github.com/adafruit/Caterina-Bootloader). (Alternate download [here](https://learn.adafruit.com/introducting-itsy-bitsy-32u4/downloads).)
2. Find avrdude or install it
3. Setup fuse for programming with : 
   `avrdude -c avrisp -P /dev/ttyACM0 -b 19200 -p m32u4 -U lfuse:r:low_fuse_val.hex:h -U hfuse:r:high_fuse_val.hex:h`
4. Upload bootloader with
   `avrdude -c avrisp -P /dev/ttyACM0  -b 19200 -p m32u4 -U flash:w:Caterina-Micro.hex`

With Arduino as ISP programmer, you should use "avrisp" with avrdude AND baudrate of 19200

(This wasn't actually tested, but afaik it's like this)
