typedef enum {
    Watering,
    Idle,
    Paused
} State;

typedef enum {
    lowMoisture,
    goodMoisture,
    reservoirEmpty,
    resevoirFull
} Event;

volatile Event currentEvent = goodMoisture;
volatile State currentState = Idle; // Global variable to hold the current state of the system

//PINS
const int floatSwitchPin = ; // Digital pin connected to the float switch
const int buzzerPin = ; // Digital pin connected to the buzzer
const int waterPumpPin = ; // Digital pin connected to the water pump relay
const int soilMoisturePin = ;//Analog pin connected to moisture sensor (input)

//CONST VARS
const int lowM_threshold = 0;

//FLAGS
volatile bool resevoirFull = false; // Flag to hold the resevoir status
volatile bool lowMoisture = false; //flag to hold moisture status