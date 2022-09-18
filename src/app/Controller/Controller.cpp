#include "Controller.h"

Controller::Controller(StandLightService *standlightservice, ClockService *clockservice, TempHumidService *temphumidservice)
{
    this->standlightservice = standlightservice;
    this->clockservice = clockservice;
    this->temphumidservice = temphumidservice;
}

Controller::~Controller()
{

}

void Controller::updateEvent(std::string strEvent)
{
    // Button -> Listener -> Controller -> StandLightService
    if(strEvent == "modeButton")
    {
        standlightservice->updatelightState("modeButton");
    }

    // Button -> Listener -> Controller -> TempHumidService
    if(strEvent == "motorButton")
    {
        temphumidservice->updateTempState("motorButton");
    }

    // Button -> Listener -> Controller -> ClcokService
    if(strEvent == "clockButton")
    {
        clockservice->updateClockState("clockButton");
    }
    if(strEvent == "stopstartButton")
    {  
        clockservice->updateTimerState("stopstartButton");
    }
    if(strEvent == "resetButton")
    {
        clockservice->updateTimerState("resetButton");
    }

    // ClockCheck -> Listener -> Controller -> ClockService
    if(strEvent == "clockUpdate")
    {
        clockservice->updateEvent();
    }
}

// DHT11 & DHT_Data -> Listener -> Controller -> TempHumidService
void Controller::updateTempHumid(DHT_Data dhtData)
{
    temphumidservice->updateTempHumid(dhtData);
}

// Ultrasonic -> Listener -> Controller -> StandLightService
void Controller::updateDistance(int distance)
{
    standlightservice->updateDistance(distance);
}