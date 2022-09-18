#ifndef STANDLIGHTSERVICE_H
#define STANDLIGHTSERVICE_H

#pragma once

#include <string>
#include "lightState.h"
#include "StandLightView.h"

class StandLightService
{
private:
    int lightState;
    int Temp_lightState;
    StandLightView *standlightview;

public:
    StandLightService(StandLightView *standlightview);
    ~StandLightService();
    void updatelightState(std::string strState);
    void updateDistance(int distance);


};

#endif