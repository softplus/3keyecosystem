# 6key2 - a 3x2 & 2x3-key, 6-WS2812B keyboard for 3-key-ecosystem

Hardware status: ok

QMK status: working, not cleaned up

![](board.png)

Requires [kbmount](../kbmount/) base plate

Switch types supported:

* Cherry MX, without LED
* Kailh CPG1350 low-profile, w/WS2812B 2020
* Kailh CPG1425 Butterfly low-profile, w/WS2812B 2020

## Pins

Left/Top:

1. GND
2. GND

Top and side:

1. WS2812B DI -> PB2 / D16
2. VCC -> VCC
3. COL1 -> PF4 / D21 / A3
4. ROW1 -> PF6 / D19 / A1
5. ROW2 -> PC6 / D5
6. COL2 -> PB5 / D9
7. COL3 -> PD7 / D6
8. GND
9. GND

Right/Bottom:

1. GND

## Hardware

* 6x Switches
* 6x Diode 1N4148, size SOD123 (or jump with 0R resistor 0805)
* 6x WS2812B 2020
* 6x Capacitor 100nF (0.1uF), size 0603

## Links

* [QMK keyboard](https://github.com/softplus/3keyecosystem-qmk/tree/main/6key2)
* [Schematic](schematic.pdf)
* [EasyEDA](https://easyeda.com/account/project/setting/basic?project=eee831f5fb224de28f7dd55678126e91)
* [Gerber files](gerber.zip)
