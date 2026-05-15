#include "MAX7219Control.h"

const int MatrixPinDIN = 6;
const int MatrixPinCS = 8;
const int MatrixPinCLK = 7;
const int NumberOfPanels = 16;
int PanelBrightness = 7;  // 0-15. A greater brightness also increases power draw

byte ASCIINumbers[16][8] = {
  { B00000000, B00111100, B01100110, B01101110, B01110110, B01100110, B01100110, B00111100 },  // 0
  { B00000000, B00011000, B00011000, B00111000, B00011000, B00011000, B00011000, B01111110 },  // 1
  { B00000000, B00111100, B01100110, B00000110, B00001100, B00110000, B01100000, B01111110 },  // 2
  { B00000000, B00111100, B01100110, B00000110, B00011100, B00000110, B01100110, B00111100 },  // 3
  { B00000000, B00001100, B00011100, B00101100, B01001100, B01111110, B00001100, B00001100 },  // 4
  { B00000000, B01111110, B01100000, B01111100, B00000110, B00000110, B01100110, B00111100 },  // 5
  { B00000000, B00111100, B01100110, B01100000, B01111100, B01100110, B01100110, B00111100 },  // 6
  { B00000000, B01111110, B01100110, B00001100, B00001100, B00011000, B00011000, B00011000 },  // 7
  { B00000000, B00111100, B01100110, B01100110, B00111100, B01100110, B01100110, B00111100 },  // 8
  { B00000000, B00111100, B01100110, B01100110, B00111110, B00000110, B01100110, B00111100 },  // 9
  { B00011000, B00111100, B01100110, B01100110, B01111110, B01100110, B01100110, B01100110 },  // A
  { B01111100, B01111110, B01100110, B01111110, B01111110, B01100110, B01111110, B01111100 },  // B
  { B01111100, B01111100, B01100000, B01100000, B01100000, B01100000, B01111100, B01111100 },  // C
  { B01111100, B01111110, B01100110, B01100110, B01100110, B01100110, B01111110, B01111100 },  // D
  { B01111100, B01111100, B01100000, B01111100, B01111100, B01100000, B01111100, B01111100 },  // E
  { B01111100, B01111100, B01100000, B01111100, B01111100, B01100000, B01100000, B01100000 },  // F
};

MAX7219Control* LEDPanels;


// Starting up sequence
void setup() {
  // Set up the LED matrix panels
  LEDPanels = new MAX7219Control(MatrixPinDIN, MatrixPinCS, MatrixPinCLK, NumberOfPanels);
  LEDPanels->Initialise();
  LEDPanels->SetBrightness(PanelBrightness);

  // Loose connections causing panels to turn off? Try this!
  // LEDPanels->SetRapidAutoRecovery(true);
}


void loop() {
  // EXAMPLE 1: Print a number on each panel
  for (int panel = 0; panel < NumberOfPanels; panel++) {
    // Option 1: Set the data for the whole panel (top-to-bottom)
    LEDPanels->SetPanel(panel, ASCIINumbers[panel]);

    // Option 2: Render one row at a time
    // for (int row = 0; row < 8; row++) {
    //   LEDPanels->SetRow(panel, row, ASCIINumbers[panel][row]);
    // }


    // UPSIDE DOWN PANELS
    // Option 1: Set the data for the whole panel
    // LEDPanels->SetFlippedPanel(panel, ASCIINumbers[panel]);

    // Option 2: Render one row at a time
    // for (int row = 0; row < 8; row++) {
    //   LEDPanels->SetFlippedRow(panel, row, ASCIINumbers[panel][row]);
    // }
  }


  // EXAMPLE 2: Alternating lit up columns
  // bool showAlt = (millis() / 1000) % 2 == 0;
  // for (int p = 0; p < NumberOfPanels; p++) {
  //   for (int i = 0; i < 8; i++) {
  //     LEDPanels->SetRow(p, i, showAlt ? B01010101 : B10101010);
  //   }
  // }

  // Render any updates
  LEDPanels->RenderDisplays();
}
