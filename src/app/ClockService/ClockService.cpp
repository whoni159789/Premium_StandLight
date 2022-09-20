#include "ClockService.h"
#include <wiringPi.h>
#include <stdio.h>

ClockService::ClockService(ClockView *clockview)
{
    this->curTime = 0;
    this->clockState = CLOCK;
    this->timerState = TIMER_STOP;
    this->timerCount = 0;
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
void ClockService::updateModeEvent(std::string strState)
{
    switch(clockState)
    {
        case CLOCK:
            if(strState == "modeButton")
            {
                clockState = TIMER;
                clockview->setClockState(clockState);
            }
        break;

        case TIMER:
            if(strState == "modeButton")
            {
                clockState = CLOCK;
                clockview->setClockState(clockState);
            }
        break;
    }
}

// Button -> Listener -> Controller -> ClockService -> ClockView
// 버튼을 입력 받을 때만 (한 번씩만) 호출하는 함수
void ClockService::updateTimerEvent(std::string strState)
{
    switch(timerState)
    {
        case TIMER_STOP:

            if(strState == "stopstartButton")
            {
                timerState = TIMER_START;
                clockview->setTimerState(timerState);
            }

        break;

        case TIMER_START:

            if(strState == "stopstartButton")
            {
                timerState = TIMER_TEMPSTOP;
                clockview->setTimerState(timerState);
            }

        break;

        case TIMER_TEMPSTOP:

            if(strState == "stopstartButton")
            {
                timerState = TIMER_RESTART;
                clockview->setTimerState(timerState);
            }
            else if(strState == "resetButton")
            {
                timerState = TIMER_RESET;
                clockview->setTimerState(timerState);
            }

        break;
    }
}

// ClockService -> ClockView
void ClockService::updateTimerCount()
{
    static unsigned int Temp_timerCount = 0;
    static time_t prevTime = 0;
    time_t curTime = time(NULL);

    switch(timerState)
    {
        case TIMER_STOP:

            prevTime = curTime;
            clockview->updateTimerTime(timerCount);

        break;

        case TIMER_START:

            if(prevTime == curTime)
                return;
            else
            {
                prevTime = curTime;
                timerCount++;
                clockview->updateTimerTime(timerCount);
            }
printf("timerCount : %d\n", timerCount);

        break;

        case TIMER_TEMPSTOP:

            prevTime = curTime;
            Temp_timerCount = timerCount;
            clockview->updateTimerTime(Temp_timerCount);

        break;

        case TIMER_RESTART:

            timerCount = Temp_timerCount;
            timerState = TIMER_START;
            clockview->setTimerState(timerState);

        break;

        case TIMER_RESET:
        
            Temp_timerCount = 0;
            prevTime = 0;
            timerCount = 0;
            Temp_timerCount = 0;
            timerState = TIMER_STOP;
            clockview->setTimerState(timerState);

        break;
    }
}