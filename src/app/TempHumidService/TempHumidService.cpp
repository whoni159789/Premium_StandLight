#include "TempHumidService.h"
#include <stdio.h>

TempHumidService::TempHumidService(TempHumidView *temphumidview)
{
    this->tempState = TEMP_NORMAL;
    this->motorState = MOTOR_ACTIVE;
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
        case MOTOR_INACTIVE:
            if(strState == "motorButton")
            {
                motorState = MOTOR_ACTIVE;
                printf("모터 활성화\n");
                temphumidview->setMotorState(motorState);
            }   
        break;

        case MOTOR_ACTIVE:
            if(strState == "motorButton")
            {
                motorState = MOTOR_INACTIVE;
                printf("모터 비활성화\n");
                temphumidview->setMotorState(motorState);
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