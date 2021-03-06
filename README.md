# 3-Key-Ecosystem -- a collection of modular macro-keyboards

This is a collection of macro-keyboards.
Most of them are based on a modular base-board (kbmount).
There are also 2 kinds of single-key boards for custom functions:
one for mechanical keys (the-feely-one),
and one for capacative touch connections (the-touchy-one).
As a bonus, some one-off boards too.

QMK code at https://github.com/softplus/3keyecosystem-qmk

License: Apache 2.0

Author/copyright: github.com/softplus (johnmu.com)

Feel free to reuse, tweak, make something cool.

Sample board:

![](/2key2/photo.jpg)

## Devices

* Modular mount
  * [kbmount](kbmount/) - Modular ATmega32u4-based keyboard 2U base-board
* 1-button keyboards
  * [the-feely-one](1key/the-feely-one/) - 1 button, 2 LEDs
  * [the-touchy-one](1key/the-touchy-one/) - capacative touch, 4 RGB LEDs
* 2-button keyboards - built on kbmount
  * [2key1](2key/2key1/) - 2 buttons, simple LEDs
  * [2key2](2key/2key2/) - 2 buttons, RGB LEDs
* 4-button keyboards - built on kbmount
  * [4key1](4key/4key1/) - 2x2 button array, simple LEDs
  * [4key2](4key/4key2/) - 2x2 button array, RGB LEDs
* 6-button keyboards - built on kbmount
  * [6key2](6key/6key2/) - 3x2 button array, RGB LEDs
  * [kai6](6key/kai6/) - 3x2 button array, LEDs, hand-solderable

## See also

Random text files

* [Devices](docs/devices.md)
* [USB VID/PID codes](docs/pid-codes.md)
* [To-do list](todo.md)

Also check out my [blog posts](https://johnmu.com/categories/keyboard/).

Feedback? @ me on twitter.com/johnmu
