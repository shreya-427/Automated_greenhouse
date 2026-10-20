//import task files (4 files)
#include "FreeRTOS.h"
// include the library code: (from https://www.arduino.cc/en/Reference/LiquidCrystal)
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//semaphore handles

void setup(){
    // set up the LCD's number of columns and rows: Q-how many columns and rows does the LCD have?
    lcd.begin(16, 2);
    //Q-baud rate?
    Serial.begin();
//setup inputs & outputs


// create tasks
    xTaskCreate(TaskDisplaySoilStatus, "DisplaySoilStatus", NULL, 0, NULL);
    xTaskCreate(TaskReservoirStatus, "ReservoirStatus", NULL, 1, NULL);
    xTaskCreate(TaskSoilStatus, "SoilStatus", NULL, 1, NULL);
    xTaskCreate(TaskWaterPlants, "WaterPlants", NULL, 2, NULL);
    
//create semaphore    
    xSemaphoreCreateBinary();

//create timers
    //timer for max watering time
    xCreateTimer();
    //timer for saturation set time
    xCreateTimer();
}
void loop(){}
