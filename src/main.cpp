
#include <string.h>
#include "RainbowSpectrum.h"
#include "ArtistGradients.h"
#include "ThrillEffect.h"
#include "Common.h"
#include "packetparser.h"


#include "BluefruitConfig.h"
#define LED_STRING_1 10


//instantiate LEDMatrix so that you can assign to it
static cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledBuffer;


//packet buffer for bluefruit
extern uint8_t packetbuffer[];
//Bluefruit Device
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

long idleTimer = 180000;
long current_millis;
long input_millis = millis();


//input manager

//call whenever you wanna refresh the strip
void UpdateLEDStrip();

//print some element iteratedover the matrix
void PrintMatrix();

//prints over the ledString
void PrintString();

//fills the buffer with 0's
void InitializeMatrix();

bool IdleTimerCheck ();

//Check bluetooth for input, 
boolean CheckForInput();

//sets up the bluetooth device
void SetupBluetooth(); 

void Randomize();

// function prototypes over in packetparser.cpp
uint8_t readPacket(Adafruit_BLE *ble, uint16_t timeout);
float parsefloat(uint8_t *buffer);
void printHex(const uint8_t * data, const uint32_t numBytes);













void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, LED_STRING_1>(ledString, NUM_LEDS);

  
  InitializeMatrix();
  SetupBluetooth();

}

void loop() {  
  UpdateLEDStrip();
 



  EVERY_N_MILLISECONDS(100) {

    if (CheckForInput()) {
      //check and set the current LED pattern to what it is told to be
      if (packetbuffer[1] == 'B') {
        uint8_t button = packetbuffer[2];
        uint8_t releaseCheck = packetbuffer[3];
        if (button == 0x31) CurrentLEDPattern = (LEDPattern)0;
        if (button == 0x32) CurrentLEDPattern = (LEDPattern)1;
        if (button == 0x33) CurrentLEDPattern = (LEDPattern)2;
        if (button == 0x35 && releaseCheck == RELEASED && CurrentLEDPattern == PArtistGradient) NextGradient();
        if (button == 0x36 && releaseCheck == RELEASED && CurrentLEDPattern == PArtistGradient) PrevGradient();
        if (button == 0x37 && releaseCheck == RELEASED && CurrentLEDPattern == PArtistGradient) NextPattern();
        if (button == 0x38 && releaseCheck == RELEASED && CurrentLEDPattern == PArtistGradient) PrevPattern();
        if (button == 0x35 && releaseCheck == RELEASED && CurrentLEDPattern == PThrillEffect) IncreaseSpeed();
        if (button == 0x36 && releaseCheck == RELEASED && CurrentLEDPattern == PThrillEffect) DecreaseSpeed();
      }
      input_millis = millis();
    }
  }
  current_millis = millis();
  if (IdleTimerCheck()) {
    Randomize();
  }



//add new pattern here as well
  switch (CurrentLEDPattern)
  {
    case PSpectrumWave:{SpectrumWave(ledBuffer);
                        break;}
    case PThrillEffect:{ThrillEffect(ledBuffer);
                        break;}
    case PArtistGradient:{DoArtistGradients(ledBuffer);
                        break;}
    
    default:
      for(int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j< ROW_LENGTH; j++) {
          ledBuffer(j, i) = 0;
        }
      }
      break;
  }

  // delay(1);
}







void Randomize() {
  RandomizeArtistGradient();
  CurrentLEDPattern = PArtistGradient;
}

bool IdleTimerCheck () {
  if (current_millis - input_millis >= idleTimer) {
    input_millis = millis();
    return true;
  }
  return false;
}

void SetupBluetooth() {  
  if (!ble.begin()) Serial.println("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?");

  /* Perform a factory reset to make sure everything is in a known state */
  Serial.println(F("Performing a factory reset: "));
  if ( ! ble.factoryReset() ){
    Serial.println(F("Couldn't factory reset"));
  }

  ble.echo(false);
  
  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();

  Serial.println(F("Please use Adafruit Bluefruit LE app to connect in Controller mode"));
  Serial.println(F("Then activate/use the sensors, color picker, game controller, etc!"));
  Serial.println();

  ble.verbose(false);  // debug info is a little annoying after this point!

  Serial.println(F("***********************"));

  // Set Bluefruit to DATA mode
  Serial.println( F("Switching to DATA mode!") );
  ble.setMode(BLUEFRUIT_MODE_DATA);

  Serial.println(F("***********************"));

  /*
  ************************************************************************************************
  ************************************************************************************************
  ************************************************************************************************
  *************************************SARAH ITS THIS LINE****************************************
  ************************************************************************************************
  ************************************************************************************************
  ************************************************************************************************
  ************************************************************************************************
   */
  ble.sendCommandCheckOK(F("AT+GAPDEVNAME=Del's Outfit"));
};

boolean CheckForInput() {
  uint8_t len = readPacket(&ble, BLE_READPACKET_TIMEOUT);
  if (len == 0) return false;
  printHex(packetbuffer, len);
  return true;
}


void InitializeMatrix() {
  for(int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j< ROW_LENGTH; j++) {
      ledBuffer(j, i) = 0;
    }
  }
  Serial.println("Matrix Initialized!");
}

void PrintString() {
  for(int i = 0; i < NUM_LEDS; i++) {
    int ledIndex = 0;
    // Serial.println("%i ", ledString[i].g);
  }
  Serial.println();
}

void PrintMatrix() {
  
  for(int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < ROW_LENGTH; j++) {
      int ledIndex = 0;
      ledIndex = ledMatrixLayout[i][j];
      Serial.print(" " + (String)ledBuffer(j, i).r + ", " + (String)ledBuffer(j, i).g + ", " + (String)ledBuffer(j, i).b);
    }
    Serial.println();
  }
}

void UpdateLEDStrip() {
  int ledIndex;
  for(int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < ROW_LENGTH; j++) {
      ledIndex = ledMatrixLayout[i][j];
      if (ledIndex != -1) {
        ledString[ledIndex-1].setRGB(ledBuffer(j, i).r, ledBuffer(j, i).g, ledBuffer(j, i).b);
      }
    }
  }
  FastLED.show();
}