//import task files

//events 

//states

void setup(){
    //Q-baud rate?
    Serial.begin()
//setup inputs & outputs


// create tasks
    //Q-how big should each task stack be?
    xTaskCreate(TaskDisplaySoilStatus, "DisplaySoilStatus", NULL, 0, NULL);
    xTaskCreate(TaskReservoirStatus, "ReservoirStatus", NULL, 1, NULL);
    xTaskCreate(TaskSoilStatus, "SoilStatus", NULL, 1, NULL);
    xTaskCreate(TaskWaterPlants, "WaterPlants", NULL, 2, NULL);
    

}
void loop(){}
