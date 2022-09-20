#include "TempHumidView.h"
#include <stdio.h>

TempHumidView::TempHumidView(Led *led, LCD *lcd, PWM *pwm)
{
    this->tempState = TEMP_NORMAL;
    this->motorState = MOTOR_AUTO;
    this->fanState = FAN_OFF;
    this->led = led;
    this->lcd = lcd;
    this->pwm = pwm;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::setTempHumidState(int tempstate)
{
    tempState = tempstate;
}

void TempHumidView::setMotorState(int motorstate)
{
    motorState = motorstate;
}

void TempHumidView::setFanState(int fanstate)
{
    fanState = fanstate;
}

// DHT11 & DHT_Data -> Listener -> Controller -> TempHumidService -> TempHumidView -> LCD
void TempHumidView::setTempHumidData(float temp, float humid)
{
    char buff[30];
    sprintf(buff, "%.1lf C, %.1lf %c", temp, humid, '%');
    lcd->WriteStringXY(1, 0, buff);
}

// DHT11 & DHT_Data -> Listener -> Controller -> TempHumidService -> TempHumidView -> PWM(MOTOR)
void TempHumidView::PWMView()
{
    switch(motorState)
    {
        case MOTOR_MANUAL:
            led->Off();
            switch(fanState)
            {
                case FAN_OFF:
                    pwm->Write(0);
                break;

                case FAN_1:
                    pwm->Write(35);
                break;

                case FAN_2:
                    pwm->Write(65);
                break;

                case FAN_3:
                    pwm->Write(95);
                break;
            }
        break;

        case MOTOR_AUTO:
            led->On();
            switch(tempState)
            {
                case TEMP_NORMAL:
                    pwm->Write(0);
                break;

                case TEMP_WARNING:
                    pwm->Write(70);
                break;
            }
        break;
    }
}