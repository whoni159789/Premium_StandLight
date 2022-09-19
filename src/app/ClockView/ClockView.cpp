#include "ClockView.h"
#include "wiringPi.h"
#include <stdio.h>

ClockView::ClockView(LCD *lcd)
{
    this->clockState = CLOCK;
    this->timerState = TIMER_STOP;
    this->timerCount = 0;
    this->Temp_timerCount = 0;
    this->prevTime = 0;
    this->lcd = lcd;
}

ClockView::~ClockView()
{

}

void ClockView::setClockState(int clockstate)
{
    clockState = clockstate;
}

void ClockView::setTimerState(int timerstate)
{
    timerState = timerstate;
}

void ClockView::updateTimerCount()
{
    static unsigned int prevTimerTime = 0;

    time_t curTime = time(NULL);
    //printf("%d\n", curTime);

    switch(timerState)
    {
        case TIMER_STOP:
            prevTime = curTime;
        break;
        case TIMER_START:
            if(curTime == prevTime)
            {
                timerCount = timerCount;
            }
            else
            {
                prevTime = curTime;
                timerCount++;
                printf("타이머 시작\n");
            }
        break;

        case TIMER_TEMPSTOP:
            prevTime = curTime;
            Temp_timerCount = timerCount;
        break;

        case TIMER_RESTART:
            timerCount = Temp_timerCount;
            timerState = TIMER_START;
        break;

        case TIMER_RESET:
            prevTimerTime = 0;
            timerCount = 0;
            Temp_timerCount = 0;
            timerState = TIMER_STOP;
        break;
    }
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


