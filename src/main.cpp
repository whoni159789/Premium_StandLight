#include <iostream>
#include <wiringPi.h>

// hw
#include "Button.h"
#include "ClockCheck.h"
#include "DHT11.h"
#include "I2C.h"
#include "LCD.h"
#include "Led.h"
#include "PWM.h"
#include "UltraSonic.h"

// app
#include "Listener.h"
#include "Controller.h"
#include "StandLightService.h"
#include "ClockService.h"
#include "TempHumidService.h"
#include "StandLightView.h"
#include "ClockView.h"
#include "TempHumidView.h"

int main()
{
    // hw
    Button modeButton(27);
    Button motorButton(28);
    Button clockButton(29);
    Button stopstartButton(2);
    Button resetButton(3);
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    Led motorStateLed(1);
    ClockCheck clockcheck;
    DHT11 dht(7);
    UltraSonic ultrasonic(5, 4);
    LCD lcd(new I2C("/dev/i2c-1", 0x25));
    PWM pwm(26);
    
    // app
    StandLightView standlightview(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockview(&lcd);
    TempHumidView temphumidview(&motorStateLed, &lcd, &pwm);
    StandLightService standlightservice(&standlightview);
    ClockService clockservice(&clockview);
    TempHumidService temphumidservice(&temphumidview);
    Controller controller(&standlightservice, &clockservice, &temphumidservice);
    Listener listener(&modeButton, &motorButton, &clockButton, &stopstartButton, 
                    &resetButton, &clockcheck, &dht, &ultrasonic, &controller);
    while(1)
    {
        listener.CheckEvent();
        standlightview.lightView();
        temphumidview.PWMView();
        clockview.updateTimerCount();
        clockview.TimerView();
        delay(60);
    }

    return 0;
}