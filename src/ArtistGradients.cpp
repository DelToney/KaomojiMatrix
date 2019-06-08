#include "ArtistGradients.h"

DEFINE_GRADIENT_PALETTE( madeon_gp ) {
0,       255,255,0,
128,     225, 15, 0, 
255,       255,255,0
};

DEFINE_GRADIENT_PALETTE( porter_gp ) {


  0,        244, 166, 251,
  51,       204, 176, 248,
  102,      191, 112, 227,
  153,      128, 183, 251,
  204,      128, 169, 236,
  220,      120, 142, 174,
  255,      244, 166, 251

};

Artist currentArtist = Madeon;

CRGBPalette256 colorPalette;
TBlendType currentBlending = LINEARBLEND;


void DoArtistGradients(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {
    switch (currentArtist)
    {
    case Porter:
        PorterGradient(ledMatrix);
        break;
    case Madeon:
        MadeonGradient(ledMatrix);
        break;
    default:
        break;
    }
}

void NextGradient () {
    int temp = currentArtist;
    int numArtists = (int)NUM_ARTISTS;
    temp++;
    currentArtist = (Artist)(temp%numArtists);
    }

void PrevGradient () {
    int temp = currentArtist;
    int numArtists = (int)NUM_ARTISTS;
    temp--;
    Serial.println(temp);
    currentArtist = (Artist)(temp%numArtists);
    }

void MadeonGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {
    colorPalette = madeon_gp;
    DoHorizontalGradient(ledMatrix, colorPalette);
}

void PorterGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {
    colorPalette = porter_gp;
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
                
                CRGB Color = ColorFromPalette(colorPalette, colorIndex, 128, currentBlending);
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

    int count = 0;
    byte colorIndex = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < ROW_LENGTH; j++) {
            int ledIndex = ledMatrixLayout[i][j];
            if (ledIndex != -1) {

                colorIndex = (i*(256/NUM_ROWS)+count)%256;
                
                CRGB Color = ColorFromPalette(colorPalette, colorIndex, 60, currentBlending);
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


// void DoWeirdSinWaveThingGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete)  {

//     static int count = 0;
//     static byte colorIndex = 0;
//     for (int i = 0; i < NUM_ROWS; i++) {

            
//         for (int j = 0; j < ROW_LENGTH; j++) {
//             int ledIndex = ledMatrixLayout[i][j];
//             if (ledIndex != -1) {

//                 colorIndex = (beatsin8(60, 0, 255) + j*(256/ROW_LENGTH))%256;
                
//                 CRGB Color = ColorFromPalette(colorPalette, colorIndex, 5, currentBlending);
//                 ledMatrix(j, i).setRGB(Color.r, Color.g, Color.b);
                
//             }
//         }
//     }

//     if (count >= 256) {
//         count = 0;
//     } else {
//         count+=2;
//     }
// }