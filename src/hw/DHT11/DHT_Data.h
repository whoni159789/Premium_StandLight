#ifndef DHT_DATA_H
#define DHT_DATA_H

#pragma once

class DHT_Data
{
public:
    int RH;
    int RHDec;
    int Temp;
    int TempDec;
    int checksum;
    int error;
};

#endif