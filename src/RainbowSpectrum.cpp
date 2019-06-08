#include <RainbowSpectrum.h>

// Fill the dots one after the other with a color
void SpectrumStatic(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix)  {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < ROW_LENGTH; j++)
    {
      int ledIndex = ledMatrixLayout[i][j];
      if (ledIndex != -1) {
        ledMatrix(j, i).setHSV((256/ROW_LENGTH)*j, 255, 50);
      }
    }
  }
}

void SpectrumWave(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix)  {
  static int count = 0;
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < ROW_LENGTH; j++)
    {
      int ledIndex = ledMatrixLayout[i][j];
      if (ledIndex != -1) {
        ledMatrix(j, i).setHSV((256/ROW_LENGTH)*j+count, 255, 200);
      }
    }
  }
  count+=2;
}