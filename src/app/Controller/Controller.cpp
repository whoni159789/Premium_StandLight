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
    if(strEvent == "lightButton")
        standlightservice->updatelightState("lightButton");


    // Button -> Listener -> Controller -> TempHumidService
    if(strEvent == "motorButton")
        temphumidservice->updateTempState("motorButton");

    if(strEvent == "fanButton")
        temphumidservice->updateFanState("fanButton");


    // Button -> Listener -> Controller -> ClcokService
    if(strEvent == "modeButton")
        clockservice->updateModeEvent("modeButton");

    if(strEvent == "stopstartButton")
        clockservice->updateTimerEvent("stopstartButton");

    if(strEvent == "resetButton")
        clockservice->updateTimerEvent("resetButton");


    // ClockCheck -> Listener -> Controller -> ClockService
    if(strEvent == "clockUpdate")
        clockservice->updateEvent();
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