#include <Arduino.h>
#include <Arduino_freeRTOS.h>
#include <timers.h>


void TaskWaterPlant(void *pvParameters){

    //blocked waiting for sem from SoilStatus
    for(;;){
        xSemaphoreTake()
    }

    //water when moisture is low and reservoir is full
    if(lowMoisture == false && reservoirFull == true){
        //change state to watering
        taskEnter_CRITICAL();
        currentState = WATERING;
        taskEXIT_CRITICAL();
        digitalWrite(waterPumpPin, HIGH); //waterpump on
    }else{ //moisture if good or high
        taskEnter_CRITICAL();
        currentState = IDLE
        taskEXIT_CRITICAL();
        digitalWrite(waterPumpPin, LOW); //waterpump off
    }
    
}