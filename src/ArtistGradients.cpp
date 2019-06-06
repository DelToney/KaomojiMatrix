#include "ArtistGradients.h"

DEFINE_GRADIENT_PALETTE( madeon_gp ) {
0,       199,193,3,
64,      225,174,0,
128,     217,171,13,
192,     224,131,16,
255,     224,126,7};





void MadeonGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {

    colorPalette = madeon_gp;
    
    DoGradient(ledMatrix, colorPalette);

}



void DoGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete)  {

    static int count = 0;
    static byte colorIndex;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < ROW_LENGTH; j++) {
            int ledIndex = ledMatrixLayout[i][j];
            if (ledIndex != -1) {

                // calc index so that the gradient appears forward and then reverse
                colorIndex = (i > NUM_ROWS/2 ?
                                ((256-(256/(NUM_ROWS/2))*(NUM_ROWS-i))%256) :
                                ((256/(NUM_ROWS/2))*i)%256);



                CRGB Color = ColorFromPalette(colorPalette, colorIndex, 5, LINEARBLEND);
                ledMatrix(j, i).setRGB(Color.r, Color.g, Color.b);
                // Serial.print((String)Color.b + " ");
            }
        }
        // Serial.println();
    }
    
    count+=2;
}