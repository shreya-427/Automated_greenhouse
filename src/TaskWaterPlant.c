#include <Arduino.h>
#include <Arduino_freeRTOS.h>
#include <timers.h>


void TaskWaterPlant(void *pvParameters){

    for(;;){
        //blocked waiting for sem from SoilStatus
        if(xSemaphoreTake(xSemaphore, (TickType_t) 10) == pdTRUE){

            //water when moisture is low and reservoir is full
            if(currentEvent == lowMoisture){
                //change state to watering
                taskEnter_CRITICAL();
                currentState = WATERING;
                taskEXIT_CRITICAL();
                digitalWrite(waterPumpPin, HIGH); //waterpump on

                //acts like a timer
                int count = 0
                while(count <= 5000){
                    vTaskDelay(pdMS_TO_TICKS(10));
                    count += 10;
                }
                digitalWrite(waterPumpPin, LOW);

                //time for water to settle
                vTaskDelay(pdMS_TO_TICKS(3000));
            }else{ //moisture if good or high
                taskEnter_CRITICAL();
                currentState = IDLE
                taskEXIT_CRITICAL();
                digitalWrite(waterPumpPin, LOW); //waterpump off
            }

            //you have to give back semaphore after done
            xSemaphoreGive(xSemaphore);
        }
        
    }
}