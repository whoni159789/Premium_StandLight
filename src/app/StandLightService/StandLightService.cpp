#include "StandLightService.h"

StandLightService::StandLightService(StandLightView *standlightview)
{
    this->lightState = LIGHT_OFF;
    this->Temp_lightState = LIGHT_OFF;
    this->standlightview = standlightview;
}

StandLightService::~StandLightService()
{

}

// Button -> Listener -> Controller -> StandLightService -> StandLightView
void StandLightService::updatelightState(std::string strState)
{
    switch(lightState)
    {
        case LIGHT_OFF:
            if(Temp_lightState == LIGHT_READY)
            {
                if(strState == "modeButton")
                {
                    lightState = LIGHT_1;
                    standlightview->setState(lightState);
                }
            }
        break;

        case LIGHT_1:
            if(Temp_lightState == LIGHT_READY)
            {
                if(strState == "modeButton")
                {
                    lightState = LIGHT_2;
                    standlightview->setState(lightState);
                }
            }
        break;

        case LIGHT_2:
            if(Temp_lightState == LIGHT_READY)
            {
                if(strState == "modeButton")
                {
                    lightState = LIGHT_3;
                    standlightview->setState(lightState);
                }
            }
        break;

        case LIGHT_3:
            if(Temp_lightState == LIGHT_READY)
            {
                if(strState == "modeButton")
                {
                    lightState = LIGHT_4;
                    standlightview->setState(lightState);
                }
            }
        break;

        case LIGHT_4:
            if(Temp_lightState == LIGHT_READY)
            {
                if(strState == "modeButton")
                {
                    lightState = LIGHT_5;
                    standlightview->setState(lightState);
                }
            }
        break;

        case LIGHT_5:
            if(Temp_lightState == LIGHT_READY)
            {
                if(strState == "modeButton")
                {
                    lightState = LIGHT_OFF;
                    standlightview->setState(lightState);
                }
            }
        break;
    }
}

// Ultrasonic -> Listener -> Controller -> StandLightService -> StandLightView
void StandLightService::updateDistance(int distance)
{
    static unsigned int StandLightOffcount = 0;

    if(Temp_lightState == LIGHT_READY && distance >= 20)
    {
        StandLightOffcount++;
        printf("카운트 : %d\n", StandLightOffcount);
        if(StandLightOffcount >= 5)
        {
            Temp_lightState = lightState;
            lightState = LIGHT_OFF;
            StandLightOffcount = 0;
        }
    }
    else if(Temp_lightState != LIGHT_READY && (distance > 0 && distance < 20))
    {
        lightState = Temp_lightState;
        Temp_lightState = LIGHT_READY;
    }
    else if(Temp_lightState == LIGHT_READY && (distance > 0 && distance < 20))
         StandLightOffcount = 0;

    standlightview->setState(lightState);
}