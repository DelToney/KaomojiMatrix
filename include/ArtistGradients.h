#ifndef __ARTIST__GRADIENTS__INCLUDED__
    #define __ARTIST__GRADIENTS__INCLUDED__ 1
    #include "Common.h"
    #include <FastLED_GFX.h>

    static CRGBPalette256 colorPalette;
    static TBlendType currentBlending = LINEARBLEND;

    void MadeonGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);

    void DoGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete);
#endif