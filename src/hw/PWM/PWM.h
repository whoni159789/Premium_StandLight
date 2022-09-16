#ifndef PWM_H
#define PWM_H

#pragma once

#include <wiringPi.h>
#include <softPwm.h>

class PWM
{
private:
    int pwmPin;

public:
    PWM(int pin);
    ~PWM();
    void Write(int pwmValue);

};

#endif