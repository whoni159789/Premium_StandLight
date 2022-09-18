#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once

#include <string>
#include "DHT_Data.h"
#include "StandLightService.h"
#include "ClockService.h"
#include "TempHumidService.h"

class Controller
{
private:
    StandLightService *standlightservice;
    ClockService *clockservice;
    TempHumidService *temphumidservice;

public:
    Controller(StandLightService *standlightservice, ClockService *clockservice, TempHumidService *temphumidservice);
    ~Controller();
    void updateEvent(std::string strEvent);
    void updateTempHumid(DHT_Data dhtData);
    void updateDistance(int distance);



};

#endif