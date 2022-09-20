#include "TempHumidService.h"
#include <stdio.h>

TempHumidService::TempHumidService(TempHumidView *temphumidview)
{
    this->tempState = TEMP_NORMAL;
    this->motorState = MOTOR_AUTO;
    this->fanState = FAN_OFF;
    this->temphumidview = temphumidview;
}

TempHumidService::~TempHumidService()
{

}

// Button -> Listener -> Controller -> TempHumidService -> TempHumidView
void TempHumidService::updateTempState(std::string strState)
{
    switch(motorState)
    {
        case MOTOR_MANUAL:
            if(strState == "motorButton")
            {
                motorState = MOTOR_AUTO;
                printf("선풍기 자동 모드\n");
                temphumidview->setMotorState(motorState);
            }  
        break;

        case MOTOR_AUTO:
            if(strState == "motorButton")
            {
                motorState = MOTOR_MANUAL;
                fanState = FAN_OFF;
                printf("선풍기 수동 모드\n");
                temphumidview->setMotorState(motorState);
                temphumidview->setFanState(fanState);
            } 
        break;
    }
}

// Button -> Listener -> Controller -> TempHumidService -> TempHumidView
void TempHumidService::updateFanState(std::string strState)
{
    switch(fanState)
    {
        case FAN_OFF:
            if(strState == "fanButton")
            {
                fanState = FAN_1;
                printf("선풍기 1단\n");
                temphumidview->setFanState(fanState);
            }
        break;

        case FAN_1:
            if(strState == "fanButton")
            {
                fanState = FAN_2;
                printf("선풍기 2단\n");
                temphumidview->setFanState(fanState);
            }
        break;

        case FAN_2:
            if(strState == "fanButton")
            {
                fanState = FAN_3;
                printf("선풍기 3단\n");
                temphumidview->setFanState(fanState);
            }
        break;

        case FAN_3:
            if(strState == "fanButton")
            {
                fanState = FAN_OFF;
                printf("선풍기 OFF\n");
                temphumidview->setFanState(fanState);
            }
        break;
    }
}

// DHT11 & DHT_Data -> Listener -> Controller -> TempHumidService -> TempHumidView
void TempHumidService::updateTempHumid(DHT_Data dhtData)
{
    float temp, humid;
    temp = (float)dhtData.Temp + (float)dhtData.TempDec/10.0;
    humid = (float)dhtData.RH + (float)dhtData.RHDec/10.0;

    if(temp >= 27.0)
    {
        tempState = TEMP_WARNING;
    }
    else
    {
        tempState = TEMP_NORMAL;
    }
    temphumidview->setTempHumidState(tempState);
    temphumidview->setTempHumidData(temp, humid);
}