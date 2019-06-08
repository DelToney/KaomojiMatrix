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

DEFINE_GRADIENT_PALETTE(gjones_gp) {
    0,   241, 241, 241,
    40,   207, 208, 209,
    80,   176, 177, 178,
    120,   157, 158, 159,
    160,   112, 112, 112,
    200,   157, 158, 159,
    220,   176, 177, 178,
    240,   207, 208, 209,
    255,   241, 241, 241,
};

DEFINE_GRADIENT_PALETTE( bonito_gp ) {
    0,    233, 233, 233,
    32,    199, 193, 221,
    64,    151, 161, 189,
    96,    142, 152, 174,
    128,    100, 144, 195,
    160,    104, 139, 186,
    182,    83, 135, 205,
    214,    49, 99, 168,
    255,    140, 190, 168
};
DEFINE_GRADIENT_PALETTE( sparks_gp ) {
0,       255,0,0,
64,     38, 35, 15,
128,     0, 255, 0, 
192,    38, 35, 15,
255,       255,0,0
};


Artist currentArtist = Sparks;

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
    case GJones:
        GJonesGradient(ledMatrix);
        break;
    case Bonito:
        BonitoGradient(ledMatrix);
        break;
    case Sparks:
        SparksGradient(ledMatrix);
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

void GJonesGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {
    colorPalette = gjones_gp;
    DoHorizontalGradient(ledMatrix, colorPalette);
}

void BonitoGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {
    colorPalette = bonito_gp;
    DoHorizontalGradient(ledMatrix, colorPalette);
}

void SparksGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {
    colorPalette = sparks_gp;
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