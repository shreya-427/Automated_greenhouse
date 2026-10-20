// display soil status on the screen
#include <FreeRTOS.h>

// include the library code: (from https://www.arduino.cc/en/Reference/LiquidCrystal) 
#include <LiquidCrystal.h> // Adding here for now until we make a seperate header file

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void TaskDisplaySoilStatus(void *pvParameters) {
    lcd.begin(16, 2);
     for (;;) {
        // Display current state on the LCD using global variable currentState
        /* lcd.setCursor(0, 0);
        lcd.print("State: " + getCurrentStateString(currentState));
        */

        // Display soil status and moisture level on LCD using global variable lowMoisture
        /* lcd.setCursor(0, 1);
        lcd.print("Soil Status:" + getSoilStatusString(lowMoisture) + " Moisture Level:" + moistureLevel);
        */
     }

}
