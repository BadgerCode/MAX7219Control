# MAX 7219 Control

A C library for controlling MAX7219 8x8 LED panels from Arduinos and similar microcontroller boards.

## Features

- Renders data to MAX2719 8X8 LED panels
- Supports up to 16 daisy-chain connecting panels (as per spec)
- Significantly more performant than other MAX7219 libraries
- Renders rows top-to-bottom on each panel
- Simplifies your rendering code, allowing for multiple changes per loop iteration without performance impact

## Performance

Performance was measured using 14 8x8 LED panels and compared against popular MAX7219 libraries.

- Rendering all panels
  - **93% more performant**
- Changing one row, then rendering all panels
  - **99% more performant**

_In terms of real world performance, in my own projects I saw my FPS increase from 5 to 980 on an Arduino nano._

<br>

---

<br>

# How to use

Copy the file [MAX7219_Example/MAX7219Control.h](MAX7219_Example/MAX7219Control.h) to your project.

See [MAX7219_Example/MAX7219_Example.ino](MAX7219_Example/MAX7219_Example.ino) for an example on how to use it.

<br>

---

<br>

# Additional Documentation

- MAX7219 DATA SPEC
  - https://www.analog.com/media/en/technical-documentation/data-sheets/MAX7219-MAX7221.pdf
  - (Page 6)
