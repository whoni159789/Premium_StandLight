#include "StandLightView.h"
#include "wiringPi.h"

StandLightView::StandLightView(Led *light1, Led *light2, Led *light3, Led *light4, Led *light5)
{
    this->lightState = LIGHT_OFF;
    this->light1 = light1;
    this->light2 = light2;
    this->light3 = light3;
    this->light4 = light4;
    this->light5 = light5;
}

StandLightView::~StandLightView()
{

}

void StandLightView::setState(int state)
{
    lightState = state;
}

void StandLightView::lightView()
{
    switch(lightState)
    {
        case LIGHT_OFF:
            lightOff();
        break;

        case LIGHT_1:
            lightOn1();
        break;

        case LIGHT_2:
            lightOn2();
        break;

        case LIGHT_3:
            lightOn3();
        break;

        case LIGHT_4:
            lightOn4();
        break;

        case LIGHT_5:
            lightOn5();
        break;
    }
}

void StandLightView::lightOff()
{
    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void StandLightView::lightOn1()
{
    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void StandLightView::lightOn2()
{
    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void StandLightView::lightOn3()
{
    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
}

void StandLightView::lightOn4()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
}

void StandLightView::lightOn5()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
}