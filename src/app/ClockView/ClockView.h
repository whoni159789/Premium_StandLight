#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#pragma once

#include <time.h>
#include "timerState.h"
#include "ClockTimerState.h"
#include "LCD.h"

class ClockView
{
private:
    int clockState;
    int timerState;
    unsigned int timerCount;
    unsigned int Temp_timerCount;
    LCD *lcd;

public:
    ClockView(LCD *lcd);
    ~ClockView();
    void updateTime(struct tm *timeData);
    void setClockState(int clockstate);
    void setTimerState(int timerstate);
    void updateTimerCount();
    void TimerView();

};

#endif