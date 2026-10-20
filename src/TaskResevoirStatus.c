// resevoir status task
#include <FreeRTOS.h>

typedef enum {
    Watering,
    Idle,
    Water_Empty
} State;

typedef enum {
    lowMoisture,
    goodMoisture,
    reservoirEmpty,
    resevoirFull
} Event; // Don't think we need these rn

volatile State currentState = Idle; // Global variable to hold the current state of the system

const int floatSwitchPin = ; // Digital pin connected to the float switch
const int buzzerPin = ; // Digital pin connected to the buzzer
const int waterPumpPin = ; // Digital pin connected to the water pump relay
volatile bool resevoirFull = false; // Flag to hold the resevoir status


// Assume HIGH means switch open (resevoir is empty) and LOW means switch closed (resevoir is full)
void TaskResevoirStatus(void *pvParameters) {
    pinMode(floatSwitchPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(waterPumpPin, OUTPUT);

    for (;;) {
        int floatSwitchState = digitalRead(floatSwitchPin);

        if(floatSwitchState == HIGH) { // Resevoir is empty
            resevoirFull = false; 
            digitalWrite(buzzerPin, HIGH);

            if(currentState == Watering) {
                digitalWrite(waterPumpPin, LOW);
                currentState = Water_Empty;
            }
            if(currentState == Idle) {
                currentState = Water_Empty;
            }
        }
        else { // Resevoir is full
            resevoirFull = true; 
            digitalWrite(buzzerPin, LOW);
        }

        vTaskDelay(pdMS_TO_TICKS(1000)); // Poll the float switch every second
    }
}