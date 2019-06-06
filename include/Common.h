#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__ 2
#include <Arduino.h>
#include <FastLED.h>
#include <LEDMatrix.h>
#include <Wire.h>


// const int NUM_LEDS = 26;
// const int NUM_ROWS = 7;
// const int NUM_BUFFER_LEDS = 49;
// const int ROW_LENGTH = 7;


const int NUM_LEDS = 113;
const int NUM_ROWS = 7;
const int NUM_BUFFER_LEDS = 343;
const int ROW_LENGTH = 45;


static CRGB ledString[NUM_LEDS];

//add an enum value for every pattern
enum LEDPattern {
        PSpectrumStatic,
        PSpectrumWave,
        PMadeonGradient
        };
        
static LEDPattern CurrentPattern = PMadeonGradient;



//this holds the template for the LED Matrix; 
const int ledMatrixLayout[NUM_ROWS][ROW_LENGTH] 
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
    {1,2,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,71,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,101,102,103},
    {5,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,29,31,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,70,72,73,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,105,104},
    {6,-1,-1,-1,14,15,16,17,18,-1,-1,-1,26,27,28,-1,33,34,35,-1,-1,-1,-1,-1,-1,-1,67,68,69,-1,74,75,76,-1,-1,-1,91,92,93,94,95,-1,-1,-1,106},
    {7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,24,25,-1,48,-1,-1,-1,37,36,-1,-1,57,-1,-1,65,66,-1,89,-1,-1,-1,78,77,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,107},
    {8,-1,-1,-1,23,22,21,20,19,-1,-1,-1,47,46,45,49,40,39,38,-1,-1,55,56,58,60,-1,88,87,86,90,81,80,79,-1,-1,-1,100,99,98,97,96,-1,-1,-1,108},
    {10,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,43,41,-1,-1,52,53,54,-1,59,61,62,-1,-1,85,84,82,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,109},
    {11,12,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,42,-1,-1,50,51,-1,-1,-1,-1,-1,63,64,-1,-1,83,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,111,112,113}
};

#endif