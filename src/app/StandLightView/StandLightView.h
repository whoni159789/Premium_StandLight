#ifndef STANDLIGHTVIEW_H
#define STANDLIGHTVIEW_H

#pragma once

#include <string>
#include "lightState.h"
#include "Led.h"
#include "LCD.h"

class StandLightView
{
private:
    int lightState;
    Led *light1;
    Led *light2;
    Led *light3;
    Led *light4;
    Led *light5;
    LCD *lcd;

public:
    StandLightView(Led *light1, Led *light2, Led *light3, Led *light4, Led *light5, LCD *lcd);
    ~StandLightView();
    void setState(int state);
    void lightView();
    void lightOff();
    void lightOn1();
    void lightOn2();
    void lightOn3();
    void lightOn4();
    void lightOn5();

};

#endif