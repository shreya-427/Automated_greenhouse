#include <Arduino.h>
#include <Arduino_freeRTOS.h>

void TaskWaterPlant(void *pvParameters){

    //blocked waiting for sem from SoilStatus
    for(;;){
        xSemaphoreTake()
    }

    //if event is low moisture
        //water pump on
    //if event is good moisture or high moisture
        //water pump off
}