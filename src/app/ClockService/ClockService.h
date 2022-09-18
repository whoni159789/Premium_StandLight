#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H

#pragma once

#include <time.h>
#include <string>
#include "timerState.h"
#include "ClockTimerState.h"
#include "ClockView.h"

class ClockService
{
private:
    time_t curTime;
    int clockState;
    int timerState;
    ClockView *clockview;

public:
    ClockService(ClockView *clockview);
    ~ClockService();
    void updateEvent();
    void updateClockState(std::string strState);
    void updateTimerState(std::string strState);
};

#endif