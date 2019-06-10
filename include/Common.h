#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__ 
#include <Arduino.h>
#include <FastLED.h>
#include <LEDMatrix.h>
#include <Wire.h>
#include <math.h>

#define RELEASED 0x30
#define PRESSED 0x31

// const int NUM_LEDS PROGMEM = 26;
// const int NUM_ROWS PROGMEM = 7;
// const int NUM_BUFFER_LEDS PROGMEM = 49;
// const int ROW_LENGTH PROGMEM = 7;


const byte NUM_LEDS PROGMEM = 111;
const byte NUM_ROWS PROGMEM = 7;
const int NUM_BUFFER_LEDS PROGMEM = 287;
const byte ROW_LENGTH PROGMEM = 41;


static CRGB ledString[NUM_LEDS];

//add an enum value for every pattern
enum LEDPattern {
        PSpectrumStatic,
        PSpectrumWave,
        PArtistGradient
        };
        
static LEDPattern CurrentPattern = PArtistGradient;



//this holds the template for the LED Matrix; 
const int8_t ledMatrixLayout[NUM_ROWS][ROW_LENGTH] PROGMEM
// = { // test templpate
//     {1,2,3,-1,14,15,16},
//     {5,4,-1,-1,-1,18,17},
//     {6,-1,-1,-1,-1,-1,19},
//     {7,-1,-1,-1,-1,-1,20},
//     {8,-1,-1,-1,-1,-1,21},
//     {10,9,-1,-1,-1,23,22},
//     {11,12,13,-1,24,25,26}
// };


//FORFINAL VERSION
 = {
        {1,2,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,70,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,99,100,101},
        {5,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,29,31,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,69,71,72,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,103,102},
        {6,-1,-1,-1,14,15,16,17,18,-1,26,27,28,-1,33,34,35,-1,-1,-1,-1,-1,-1,-1,66,67,68,-1,73,74,75,-1,89,90,91,92,93,-1,-1,-1,104},
        {7,-1,-1,-1,-1,-1,-1,-1,-1,24,25,-1,-1,48,-1,-1,37,36,-1,-1,56,-1,-1,64,65,-1,-1,88,-1,-1,77,76,-1,-1,-1,-1,-1,-1,-1,-1,105},
        {8,-1,-1,-1,23,22,21,20,19,-1,47,46,45,-1,40,39,38,-1,-1,54,55,57,59,-1,87,86,85,-1,80,79,78,-1,98,97,96,95,94,-1,-1,-1,106},
        {10,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,43,41,-1,-1,51,52,53,-1,58,60,61,-1,-1,84,83,81,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,108,107},
        {11,12,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,42,-1,-1,49,50,-1,-1,-1,-1,-1,62,63,-1,-1,82,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,109,110,111}
};

#endif