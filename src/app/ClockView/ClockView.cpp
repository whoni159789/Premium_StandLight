#include "ClockView.h"
#include "wiringPi.h"
#include <stdio.h>

ClockView::ClockView(LCD *lcd)
{
    this->clockState = CLOCK;
    this->timerState = TIMER_STOP;
    this->timerCount = 0;
    this->lcd = lcd;
}

ClockView::~ClockView() {}

void ClockView::setClockState(int clockstate)
{
    clockState = clockstate;
}

void ClockView::setTimerState(int timerstate)
{
    timerState = timerstate;
}

void ClockView::updateTimerTime(unsigned int count)
{
    timerCount = count;
}

void ClockView::updateTime(struct tm *timeData)
{
    if(clockState == CLOCK)
    {
        char buff[30];
        sprintf(buff, "TIME : %02d:%02d:%02d ",
        timeData->tm_hour,
        timeData->tm_min,
        timeData->tm_sec);
        lcd->WriteStringXY(0, 0, buff);
    }
}

void ClockView::TimerView()
{
    if(clockState == TIMER)
    {
        char buff[30];
        unsigned int timerCount_hour, timerCount_min, timerCount_sec;
        timerCount_hour = (timerCount / 36000) % 24;
        timerCount_min = (timerCount / 600) % 60;
        timerCount_sec = timerCount % 600;
        sprintf(buff, "TIMER : %02d:%02d:%02d",
        timerCount_hour,
        timerCount_min,
        timerCount_sec
        );
        lcd->WriteStringXY(0, 0, buff);
    }
}


