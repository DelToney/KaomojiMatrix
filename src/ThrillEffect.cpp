#include "ThrillEffect.h"

Frame currentFrame = Frame1;
bool forward = true;

void NextFrame();

void ThrillEffect(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix)
{

    static int count = 0;
    static byte colorIndex = 0;
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < ROW_LENGTH; j++)
        {
            int ledIndex;
            switch (currentFrame)
            {
            case Frame1:
                ledIndex = frame1[i][j];
                forward = true;
                break;
            case Frame2:
                ledIndex = frame2[i][j];
                break;
            case Frame3:
                ledIndex = frame3[i][j];
                break;
            case Frame4:
                ledIndex = frame4[i][j];
                forward = false;
                break;
            default:
                break;
            }
            ledMatrix(j, i).setRGB(0, 0, 0);
            if (ledIndex != -1)
            {
                ledMatrix(j, i).setRGB(70, 70, 70);
            }
        }
    }

    uint64_t current_millis = millis();
    static uint64_t previous_millis = 0;
    if ((uint64_t)(current_millis - previous_millis) >= EffectSpeed)
    {
        NextFrame();
        previous_millis = current_millis;
    }
}

void NextFrame()
{

    if (forward)
    {
        int8_t temp = currentFrame;
        temp++;
        currentFrame = (Frame)(temp);
    }
    else if (!forward)
    {
        int8_t temp = currentFrame;
        temp--;
        currentFrame = (Frame)(temp);
    }
}

void IncreaseSpeed()
{
    EffectSpeed -= 15;
    EffectSpeed = constrain(EffectSpeed, 30, 10000);
}

void DecreaseSpeed()
{
    EffectSpeed += 15;
    EffectSpeed = constrain(EffectSpeed, 30, 10000);
}
