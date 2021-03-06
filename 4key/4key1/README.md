# 4key1 - a 2x2-key, 4-LED keyboard for 3-key-ecosystem

Hardware status: ok

QMK status: working, not cleaned up

![](board.png)

Requires [kbmount](../../kbmount/) C/A rev.2+ base plate

USB VID/PID: (submitted, tbd) 0x1209 / 0x3305

Switch types supported:

* Cherry MX, w/TH LED
* Kailh CPG1350 low-profile, w/SMD LED
* Kailh CPG1425 Butterfly low-profile, w/SMD LED

## Pins

Left/Top:

1. GND
2. GND

Top:

1. LED1 -> PB2 / D16
2. VCC (not used) -> VCC
3. COL1 -> PF4 / D21 / A3
4. ROW1 -> PF6 / D19 / A1
5. ROW2 -> PC6 / D5
6. LED3 -> PB5 / D9
7. COL2 -> PD7 / D6
8. LED2 -> PD3 / D1
9. LED4 -> PD1 / D2

Right/Bottom:

1. GND

## Hardware

* 4x Switches
* 4x Diode 1N4148, size SOD123
* 4x Resistor 0603 for LED, eg 330R

## Links

* [QMK keyboard](https://github.com/softplus/3keyecosystem-qmk/tree/main/4key/4key1)
* [Schematic](schematic.pdf)
* [EasyEDA URL](https://easyeda.com/editor#id=e8a2dfc966d74888a9fb1a99884f2a73)
* [Gerber files](gerber.zip)
* EasyEDA JSON: [schematic](easyeda-schematic.json)
  / [PCB](easyeda-pcb.json)
