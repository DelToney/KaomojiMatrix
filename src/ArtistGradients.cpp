#include "ArtistGradients.h"

DEFINE_GRADIENT_PALETTE( madeon_gp ) {
0,       255,255,0,
128,     225, 15, 0, 
255,       255,255,0


// 0,       255,255,0,
// 64,      225,182,0,
// 128,     255,128,0
// 192,     224,131,16,
// 255,     224,126,7

};





void MadeonGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {

    colorPalette = madeon_gp;
    
    DoHorizontalGradient(ledMatrix, colorPalette);

}




void DoHorizontalGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete)  {

    static int count = 0;
    static byte colorIndex = 0;
    for (int i = 0; i < NUM_ROWS; i++) {

            
        for (int j = 0; j < ROW_LENGTH; j++) {
            int ledIndex = ledMatrixLayout[i][j];
            if (ledIndex != -1) {

                colorIndex = (j*(256/ROW_LENGTH)+count)%256;
                
                CRGB Color = ColorFromPalette(colorPalette, colorIndex, 5, currentBlending);
                ledMatrix(j, i).setRGB(Color.r, Color.g, Color.b);
                
            }
        }
    }

    if (count >= 256) {
        count = 0;
    } else {
        count+=2;
    }
}

void DoVerticalGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete)  {

    static int count = 0;
    static byte colorIndex = 0;
    for (int i = 0; i < NUM_ROWS; i++) {

            
        for (int j = 0; j < ROW_LENGTH; j++) {
            int ledIndex = ledMatrixLayout[i][j];
            if (ledIndex != -1) {

                colorIndex = (i*(256/NUM_ROWS)+count)%256;
                
                CRGB Color = ColorFromPalette(colorPalette, colorIndex, 5, currentBlending);
                ledMatrix(j, i).setRGB(Color.r, Color.g, Color.b);
                
            }
        }
    }

    if (count >= 256) {
        count = 0;
    } else {
        count+=2;
    }
}