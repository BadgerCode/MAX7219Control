# MAX 7219 Control

A C library for controlling MAX7219 8x8 LED panels from Arduinos and similar microcontroller boards.

## Features

- Renders data to MAX2719 8X8 LED panels
- Supports up to 16 daisy-chain connecting panels (as per spec)
- Significantly more performant than other MAX7219 libraries
- Renders rows top-to-bottom on each panel
- Simplifies your rendering code, allowing for multiple changes per loop iteration without performance impact
- Automatic recovery of panels with loose connections (& the option to auto-recover quicker)

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

## Sample Code

### 1. Initialisation
```c
const int MatrixPinDIN = 6;
const int MatrixPinCS = 8;
const int MatrixPinCLK = 7;
const int NumberOfPanels = 16;
int PanelBrightness = 7;  // 0-15. A greater brightness also increases power draw

// Setup the controller
LedController = new MAX7219Control(MatrixPinDIN, MatrixPinCS, MatrixPinCLK, NumberOfPanels);
LedController->Initialise();
LedController->SetBrightness(PanelBrightness); // 0-15

// Loose connections causing panels to turn off? Try this!
// LEDPanels->SetRapidAutoRecovery(true);
```

### 2. Updating rows/panels
```c
// Panel numbers start at 0 and go up to your number of panels
// Panel 0 is the first panel in the chain
// Rows are 0-7, top-to-bottom

// Clear panels
LEDPanels->ClearAllPanels();
LEDPanels->ClearPanel(panelNumber);

// Update panel data
LEDPanels->SetRow(panelNumber, row, B11001100);
LEDPanels->SetPanel(panel, new byte[8]{ B00000000, B00111100, B01100110, B01101110, B01110110, B01100110, B01100110, B00111100 });

// Update panel data (for upside down panels)
LEDPanels->SetFlippedRow(panelNumber, row, B11001100);
LEDPanels->SetFlippedPanel(panel, new byte[8]{ B00000000, B00111100, B01100110, B01101110, B01110110, B01100110, B01100110, B00111100 });
```

### 3. Rendering any pending changes
```c
// You should put this at the end of your loop() function, after writing your changes to the panels/rows

// Render any changes
LEDPanels->RenderDisplays();
```

<br>

---

<br>

# Additional Documentation

- MAX7219 DATA SPEC
  - https://www.analog.com/media/en/technical-documentation/data-sheets/MAX7219-MAX7221.pdf
  - (Page 6)
