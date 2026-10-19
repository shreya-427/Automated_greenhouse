#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

void TaskSoilStatus( void *pvParameters){
    //read the pin that connects to moisture sensor
    for(;;){
        int data = digitalRead();
        int lowM_threshold = ;
        int highM_threshold = ;
        int goodM_threshold = ;

        if(data <= lowM_threshold){
            //if moist level is low then taskWaterPlant will be awake
            xSemaphoreGive(TaskWaterPlant);
        }else if(data > lowM_threshold && data <= goodM_threshold){
            //set event good moisture
        }else{ //data must be greater than goodM_threshold (too much water)
            //TaskWaterPlant needs to stop watering
        }

        //wait for 5 seconds (every 5 seconds it gets soil moisture data)
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}