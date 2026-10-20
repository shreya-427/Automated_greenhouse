#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <utills.c>



void TaskSoilStatus( void *pvParameters){
    //read the pin that connects to moisture sensor
    for(;;){
        int data = digitalRead();
        
        if(data <= lowM_threshold){
            //if moist level is low then taskWaterPlant will be awake
            taskEnter_CRITICAL();
            lowMoisture = true;
            taskEXIT_CRITICAL();
            xSemaphoreGive(TaskWaterPlant);
        }else{
            //if moist level is good/high, taskWaterPlant will be awake but won't water
            taskEnter_CRITICAL();
            lowMoisture = false;
            taskEXIT_CRITICAL();
            xSemaphoreGive(TaskWaterPlant);
        }
        
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}