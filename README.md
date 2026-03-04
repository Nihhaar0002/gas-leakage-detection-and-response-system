# Gas Leakage Detection and Automatic Safety Control System

## Overview

This project is an embedded safety system designed to detect gas leakage and automatically trigger protective actions. The system uses an MQ gas sensor to continuously monitor gas concentration levels. When gas concentration exceeds a predefined threshold, the system performs automatic safety responses.

## Features

* Gas leakage detection using MQ gas sensor
* Automatic electrical power cutoff using relay
* Exhaust fan activation for ventilation
* Automatic gas valve shutoff using servo motor
* Real-time monitoring of gas concentration

## Technologies Used

* Arduino
* MQ Gas Sensor
* Servo Motor
* Relay Module
* Embedded Systems

## Hardware Components

* Arduino Uno
* MQ Gas Sensor
* Servo Motor
* Relay Module
* Exhaust Fan
* AC LED Bulb (for appliance simulation)

## System Working

1. The MQ gas sensor monitors gas concentration levels.
2. If gas levels exceed the safe threshold:

   * The relay turns OFF electrical appliances.
   * The exhaust fan turns ON to ventilate the area.
   * The servo motor rotates to close the gas valve.
3. The system continues monitoring until gas levels return to safe conditions.

## Hardware Setup
![WhatsApp Image 2025-01-26 at 19 25 41_5e7f5609](https://github.com/user-attachments/assets/e9095136-667a-4e78-8c84-ad8db43e7d33)



## System Demonstration

![WhatsApp Image 2025-01-27 at 21 03 59_323dbc49](https://github.com/user-attachments/assets/32ba52f9-3726-45ab-823b-797745ffe02d)


## Demo Video



https://github.com/user-attachments/assets/f83d4c15-bbf5-49de-b5ca-0b7241ed89a1



## Author

Menta Sai Nihhaar
Persuing B Tech degree in Eclectronics and Communication Engineering
