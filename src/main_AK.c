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

volatile State currentState = Idle;
volatile Event currentEvent = goodMoisture;