#include "ClockService.h"
#include <wiringPi.h>
#include <stdio.h>

ClockService::ClockService(ClockView *clockview)
{
    this->curTime = 0;
    this->clockState = CLOCK;
    this->timerState = TIMER_STOP;
    this->clockview = clockview;
}

ClockService::~ClockService()
{

}

// ClockCheck -> Listener -> Controller -> ClockService -> ClockView
void ClockService::updateEvent()
{
    curTime = time(NULL);
    struct tm *timeData = localtime(&curTime);
    clockview->updateTime(timeData);
}

// Button -> Listener -> Controller -> ClcokService -> ClockView
void ClockService::updateClockState(std::string strState)
{
    switch(clockState)
    {
        case CLOCK:
            if(strState == "clockButton")
            {
                clockState = TIMER;
                clockview->setClockState(clockState);
            }
        break;

        case TIMER:
            if(strState == "clockButton")
            {
                clockState = CLOCK;
                clockview->setClockState(clockState);
            }
        break;
    }
}
void ClockService::updateTimerState(std::string strState)
{
    if(clockState == TIMER)
    {
        switch(timerState)
        {
            case TIMER_STOP:
                if(strState == "clockButton")
                {
                    clockState = CLOCK;
                    clockview->setClockState(clockState);
                }
                if(strState == "stopstartButton")
                {
                    timerState = TIMER_START;
                }
                else if(strState == "resetButton")
                {
                    timerState = TIMER_RESET;
                }
                clockview->setTimerState(timerState);
            break;

            case TIMER_START:
                if(strState == "clockButton")
                {
                    clockState = CLOCK;
                    clockview->setClockState(clockState);
                }
                if(strState == "stopstartButton")
                {
                    timerState = TIMER_TEMPSTOP;
                }
                clockview->setTimerState(timerState);
            break;

            case TIMER_TEMPSTOP:
                if(strState == "clockButton")
                {
                    clockState = CLOCK;
                    clockview->setClockState(clockState);
                }
                if(strState == "stopstartButton")
                {
                    timerState = TIMER_RESTART;
                }
                else if(strState == "resetButton")
                {
                    timerState = TIMER_RESET;
                }
                clockview->setTimerState(timerState);
            break;
            
            case TIMER_RESTART:
                if(strState == "clockButton")
                {
                    clockState = CLOCK;
                    clockview->setClockState(clockState);
                }
                if(strState == "stopstartButton")
                {
                    timerState = TIMER_TEMPSTOP;
                }
                clockview->setTimerState(timerState);
            break;

            case TIMER_RESET:
                if(strState == "clockButton")
                {
                    clockState = CLOCK;
                    timerState = TIMER_STOP;
                    clockview->setClockState(clockState);
                }
                if(strState == "stopstartButton")
                {
                    timerState = TIMER_START;
                }
                clockview->setTimerState(timerState);
            break;
        }
    }
}