#include "ArtistGradients.h"

DEFINE_GRADIENT_PALETTE( madeon_gp ) {
0,       255,255,0,
128,     225, 15, 0, 
255,       255,255,0
};

DEFINE_GRADIENT_PALETTE( porter_gp ) {
  0,        0xBF, 0x77, 0xB9,
  51,       0x88, 0x2E, 0xE3, 
  126,      0xB0, 0xA1, 0xED, 
  153,      0x81, 0xA7, 0xDB, 
  204,      0x7E, 0xA8, 0xE0, 
  220,      0x4F, 0x6F, 0x9E, 
  255,      0xBF, 0x77, 0xB9
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
    0, 229, 30, 50,
   84, 100, 11, 12,
  168,   3, 28,  2,
  255,  35,119, 10};

DEFINE_GRADIENT_PALETTE( anamanaguchi_gp ) {
0,   1,  2, 44,
   84,   9, 11,112,
  168,  77, 19,105,
  255, 255,100,137
};


DEFINE_GRADIENT_PALETTE( cat_gp ) {
    0, 101,  1,  1,
  127, 115, 38, 62,
  255, 220,144,132};



Artist currentArtist = Porter;

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
    case Anamanaguchi:
        AnamanaguchiGradient(ledMatrix);
        break;
    case Cat:
        CatGradient(ledMatrix);
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
    CrawlGradient(ledMatrix, colorPalette);
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

void AnamanaguchiGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {
    colorPalette = anamanaguchi_gp;
    DoHorizontalGradient(ledMatrix, colorPalette);
}

void CatGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {
    colorPalette = cat_gp;
    DoSmoothGradient(ledMatrix, colorPalette);
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

void DoSmoothGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete)  {

    static int count = 0;
    static byte colorIndex = 0;
    for (int i = 0; i < NUM_ROWS; i++) {

            
        for (int j = 0; j < ROW_LENGTH; j++) {
            int ledIndex = ledMatrixLayout[i][j];
            if (ledIndex != -1) {
                
                // colorIndex = (j*(256/ROW_LENGTH)/2)%256;
                // if (j>ROW_LENGTH/2) {
                //     colorIndex = 256- colorIndex;
                // }
                
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
void CrawlGradient (cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix, CRGBPalette256 currentPalete)  {

    static int count = 0;
    static byte colorIndex = 0;
    for (int i = 0; i < NUM_ROWS; i++) {

            
        for (int j = 0; j < ROW_LENGTH; j++) {
            int ledIndex = ledMatrixLayout[i][j];
            if (ledIndex != -1) {
                
                colorIndex = (j*(256/ROW_LENGTH)*5+count)%256;
                if (j>ROW_LENGTH/2) {
                    colorIndex = 256 - colorIndex;
                }
                
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