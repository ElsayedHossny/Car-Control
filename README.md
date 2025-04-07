# Car-Control 🚗🔧

This project is an embedded system for controlling a small car using an ATmega32 microcontroller and a Bluetooth module. The car can move forward, backward, turn left or right, stop, and adjust speed based on numerical commands sent via a mobile app or terminal. Additionally, a Raspberry Pi 4 is used for advanced processing and interfacing.

## 📌 Features

- Wireless control via Bluetooth
- Real-time obstacle detection using Ultrasonic sensor
- Motor control using L293D driver
- Adjustable speed control based on numeric values
- LCD display to show status
- Modular code structure (MCAL, HAL layers)
- Raspberry Pi 4 integration for advanced control and interface

## 🧠 System Overview

- **Microcontroller**: ATmega32
- **Bluetooth Module**: HC-05
- **Motor Driver**: L293D
- **Ultrasonic Sensor**: HC-SR04
- **LCD**: 16x2 character LCD
- **Raspberry Pi 4**: For handling complex tasks and communication
- **Speed Control**: Numeric input to control speed (1 = 100, 2 = 20, 3 = 30, etc.)

## 🔄 How It Works

1. **Raspberry Pi 4** handles high-level communication, such as receiving control commands via a web interface or custom app.
2. Raspberry Pi sends Bluetooth commands to the **ATmega32** to control the car's movement and speed.
3. **ATmega32** receives the command via UART and controls the motor driver to move the car with the specified speed.
     - **F**: Move the car **front** (forward). 
     - **B**: Move the car **back** (backward).
     - **L**: Turn the car **left**.
     - **R**: Turn the car **right**.
     - **S**: **Stop** the car.
5. Speed is controlled by numeric values:
   - **1** = Speed 100
   - **2** = Speed 20
   - **3** = Speed 30
   - ...
   - **9** = Speed 90
6. The car checks the distance using the ultrasonic sensor to avoid obstacles before moving.
7. Status messages are shown on the **LCD**.

## 🐍 Raspberry Pi 4 Integration

The Raspberry Pi 4 can serve as the central hub for controlling the car. It can:
- Receive commands from a custom mobile app or web interface.
- Send commands to the ATmega32 via Bluetooth to control the car.
- Process sensor data (optional) for more advanced features.

## 📁 Project Structure

### Explanation of the Folder Structure

- **main.c**: This is the entry point for the car control system. It contains the main logic for controlling the car, processing sensor data, and sending commands to the motor driver.

- **HAL/**: This folder contains the hardware abstraction layers. It provides drivers for interfacing with the car's hardware (e.g., motors, sensors, LCD, Bluetooth).

  - **Motor/**: The motor control module handles PWM signals to control the speed and direction of the car's motors.
  - **LCD/**: The LCD interface module is responsible for displaying information such as speed, status, and error messages on a 16x2 LCD.
  - **Ultrasonic/**: The ultrasonic sensor control module is used to measure the distance in front of the car and prevent collisions.
  - **Bluetooth/**: This module handles Bluetooth communication (using HC-05) between the ATmega32 and external devices like Raspberry Pi or a mobile app.

- **MCAL/**: This folder contains the microcontroller abstraction layers for low-level operations, such as I/O operations, timers, and UART communication.

  - **DIO/**: The digital I/O module is responsible for reading inputs (e.g., button presses) and sending outputs (e.g., controlling motor pins).
  - **Timer/**: This module handles the timing for PWM control and other time-based tasks.
  - **UART/**: The UART communication module is used for serial communication between the ATmega32 and external devices like the Raspberry Pi or mobile app via Bluetooth.

- **Car/RaspberryPi/**: This folder contains files related to the Raspberry Pi integration.

  - **control.py**: A Python script that controls the car via Bluetooth from the Raspberry Pi. This script can send movement and speed commands to the ATmega32 to control the car.

