#ifndef __ARTIST__GRADIENTS__INCLUDED__
    #define __ARTIST__GRADIENTS__INCLUDED__ 1
    #include "Common.h"


    enum Artist {
        Madeon = 0,
        Porter,
        NUM_ARTISTS
    };

    //checks current  gradient and displays it
    void DoArtistGradients (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);

    void NextGradient();
    void PrevGradient();

    
    void MadeonGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
    void PorterGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);

    void DoHorizontalGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete);
    void DoVerticalGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete);
    void DoWeirdSinWaveThingGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete);
#endif