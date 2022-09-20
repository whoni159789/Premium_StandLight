#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#pragma once

#include <string>
#include "DHT_Data.h"
#include "TempState.h"
#include "motorState.h"
#include "fanState.h"
#include "TempHumidView.h"

class TempHumidService
{
private:
    int tempState;
    int motorState;
    int fanState;
    TempHumidView *temphumidview;

public:
    TempHumidService(TempHumidView *temphumidview);
    ~TempHumidService();
    void updateTempHumid(DHT_Data dhtData);
    void updateTempState(std::string strState);
    void updateFanState(std::string strState);

};

#endif