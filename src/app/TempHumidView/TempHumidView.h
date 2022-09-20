#ifndef TEMPHUMIDVIEW_H
#define TEMPHUMIDVIEW_H

#pragma once

#include "TempState.h"
#include "motorState.h"
#include "fanState.h"
#include "Led.h"
#include "LCD.h"
#include "PWM.h"

class TempHumidView
{
private:
    int tempState;
    int motorState;
    int fanState;
    Led *led;
    LCD *lcd;
    PWM *pwm;

public:
    TempHumidView(Led *led, LCD *lcd, PWM *pwm);
    ~TempHumidView();
    void setTempHumidState(int tempstate);
    void setMotorState(int motorstate);
    void setFanState(int fanstate);
    void setTempHumidData(float temp, float humid);
    void PWMView();

};

#endif