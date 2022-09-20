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
    unsigned int timerCount;
    ClockView *clockview;

public:
    ClockService(ClockView *clockview);
    ~ClockService();
    void updateEvent();
    void updateModeEvent(std::string strState);
    void updateTimerEvent(std::string strState);
    void updateTimerCount();
};

#endif