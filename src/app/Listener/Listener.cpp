#include "Listener.h"
#include "wiringPi.h"
#include <stdio.h>

Listener::Listener(Button *lightButton, Button *motorButton, Button *fanButton, Button *modeButton, Button *stopstartButton, Button *resetButton,
            ClockCheck *clockCheck, DHT11 *dht11, UltraSonic *ultrasonic, Controller *controller)
{
    this->lightButton = lightButton;
    this->motorButton = motorButton;
    this->fanButton = fanButton;
    this->modeButton = modeButton;
    this->stopstartButton = stopstartButton;
    this->resetButton = resetButton;
    this->clockCheck = clockCheck;
    this->dht11 = dht11;
    this->ultrasonic = ultrasonic;
    this->controller = controller;
}

Listener::~Listener()
{

}

void Listener::CheckEvent()
{
    // Button -> Listener -> Controller
    if(lightButton->getState() == RELEASE_ACTIVE)
        controller->updateEvent("lightButton");

    if(motorButton->getState() == RELEASE_ACTIVE)
        controller->updateEvent("motorButton");

    if(fanButton->getState() == RELEASE_ACTIVE)
        controller->updateEvent("fanButton");

    if(modeButton->getState() == RELEASE_ACTIVE)
        controller->updateEvent("modeButton");
    if(stopstartButton->getState() == RELEASE_ACTIVE)
        controller->updateEvent("stopstartButton");

    if(resetButton->getState() == RELEASE_ACTIVE)
        controller->updateEvent("resetButton");

    // ClockCheck -> Listener -> Controller
    if(clockCheck->isUpdate())
        controller->updateEvent("clockUpdate");

    // DHT11 & DHT_Data -> Listener -> Controller
    static unsigned int prevTempHumidTime = 0;
    if(millis() - prevTempHumidTime >= 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if(!dhtData.error)
        {
            controller->updateTempHumid(dhtData);
        }
    }

    // Ultrasonic -> Listener -> Controller
    static unsigned int prevUltrasonicTime = 0;
    if(millis() - prevUltrasonicTime >= 1000)
    {
        prevUltrasonicTime = millis();
        int distance = ultrasonic->readDistance();
        controller->updateDistance(distance);
        printf("Distance : %d\n", distance);
    }
}