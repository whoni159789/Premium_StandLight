#ifndef LISTENER_H
#define LISTENER_H

#pragma once

//hw
#include "Button.h"
#include "ClockCheck.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "UltraSonic.h"

//app
#include "Controller.h"

class Listener
{
private:
    Button *lightButton;
    Button *motorButton;
    Button *fanButton;
    Button *modeButton;
    Button *stopstartButton;
    Button *resetButton;
    ClockCheck *clockCheck;
    DHT11 *dht11;
    UltraSonic *ultrasonic;
    Controller *controller;
    

public:
    Listener(Button *lightButton, Button *motorButton, Button *fanButton, Button *modeButton, Button *stopstartButton, Button *resetButton,
            ClockCheck *clockCheck, DHT11 *dht11, UltraSonic *ultrasonic, Controller *controller);
    ~Listener();
    void CheckEvent();


};

#endif