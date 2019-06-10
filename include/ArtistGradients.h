#ifndef __ARTIST__GRADIENTS__INCLUDED__
#define __ARTIST__GRADIENTS__INCLUDED__ 1
#include "Common.h"

enum Artist
{
    Madeon = 0,
    Porter,
    GJones,
    Bonito,
    Sparks,
    Anamanaguchi,
    Cat,
    Nina,
    Wednesday,
    Sarah,
    NUM_ARTISTS
};

enum Pattern
{
    Horizontal,
    Vertical,
    Smooth,
    Crawl,
    Sin,
    NUM_PATTERNS
};

//checks current  gradient and displays it
void DoArtistGradients(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);

void NextGradient();
void PrevGradient();

void NextPattern();
void PrevPattern();

void MadeonGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void PorterGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void GJonesGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void BonitoGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void SparksGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void AnamanaguchiGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void CatGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void NinaGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void WednesdayGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void SarahGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);

void RandomizeArtistGradient();

void DoHorizontalGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void DoSmoothGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void DoVerticalGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void CrawlGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
void DoWeirdSinWaveThingGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);
#endif