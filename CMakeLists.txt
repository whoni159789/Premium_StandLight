cmake_minimum_required(VERSION 3.0.0)

project(Premium_StandLight)

add_executable(${PROJECT_NAME}
    ./src/main.cpp
    ./src/hw/Button/Button.cpp
    ./src/hw/ClockCheck/ClockCheck.cpp
    ./src/hw/DHT11/DHT11.cpp
    ./src/hw/I2C/I2C.cpp
    ./src/hw/LCD/LCD.cpp
    ./src/hw/Led/Led.cpp
    ./src/hw/PWM/PWM.cpp
    ./src/hw/UltraSonic/UltraSonic.cpp
    ./src/app/Listener/Listener.cpp
    ./src/app/Controller/Controller.cpp
    ./src/app/StandLightService/StandLightService.cpp
    ./src/app/ClockService/ClockService.cpp
    ./src/app/TempHumidService/TempHumidService.cpp
    ./src/app/StandLightView/StandLightView.cpp
    ./src/app/ClockView/ClockView.cpp
    ./src/app/TempHumidView/TempHumidView.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ./src/hw/Button
    ./src/hw/ClockCheck
    ./src/hw/DHT11
    ./src/hw/I2C
    ./src/hw/LCD
    ./src/hw/Led
    ./src/hw/PWM
    ./src/hw/UltraSonic
    ./src/app/Listener
    ./src/app/Controller
    ./src/app/StandLightService
    ./src/app/ClockService
    ./src/app/TempHumidService
    ./src/app/StandLightView
    ./src/app/ClockView
    ./src/app/TempHumidView
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)