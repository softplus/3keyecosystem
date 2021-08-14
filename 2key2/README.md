# 2key2 - a 2-key, 2-WS2812B keyboard for 3-key-ecosystem

Hardware status: in redesign :-/

QMK status: working, not submitted to QMK yet

![](board.png)

![](photo.jpg)

Requires [kbmount](../kbmount/) base plate

Switch types supported:

* Cherry MX, without LED
* Kailh CPG1350 low-profile, w/WS2812B 2020
* Kailh CPG1425 Butterfly low-profile, w/WS2812B 2020

## Pins

Left/Top: 

1. GND
2. GND

Top:

1. VCC (not used) -> VCC
2. WS2812B DI -> PB2 / D16
3. RESET (not used) -> RESET
4. COL1 -> PF4 / D21 / A3
5. ROW1 -> PF6 / D19 / A1
6. (not used) -> PC6 / D5
7. (not used) -> PB5 / D9
8. COL2 -> PD7 / D6
9. (not used) -> PD3 / D1
10. (not used) -> PD1 / D2

Right/Bottom:

1. GND

## Hardware

* 2x Switches
* 2x Diode 1N4148, size SOD123 (or jump with 0R resistor 0805)
* 2x WS2812B 2020
* 2x Capacitor 100nF (0.1uF), size 0603
 
## Links

* [QMK keyboard](https://github.com/softplus/3keyecosystem-qmk/tree/main/2key2)
* [Schematic](schematic.pdf)
* [EasyEDA v1](https://easyeda.com/account/project/setting/basic?project=4153f95447924b798599ed4139021f7e)
* [Gerber files v1](gerber.zip)
