Arduino 5-Servo Robotic Arm Control
This project uses an Arduino board to control a 5-servo robotic arm with two joysticks. The first joystick controls the base and arm servos, and the second joystick controls the gripper servo.

Components
Arduino Uno

Two Joystick Modules

Five Servo Motors (e.g., MG996R or SG90)

Jumper Wires

External Power Source (e.g., a battery pack with 4.8V-7.2V output)

Wiring Diagram
1. Power and Ground
Connect the Arduino's 5V and GND pins to the power rails on your breadboard. This provides a common ground for the entire circuit.

2. First Joystick (Base and Arm Control)
Connect the first joystick for controlling the arm's movement:

VCC pin to the 5V power rail

GND pin to the ground rail

VRx (X-axis) to Arduino Analog Pin A0

VRy (Y-axis) to Arduino Analog Pin A1

3. Second Joystick (Gripper Control)
Connect the second joystick for controlling the gripper:

VCC pin to the 5V power rail

GND pin to the ground rail

VRx (X-axis) to Arduino Analog Pin A2

VRy (Y-axis) to Arduino Analog Pin A3

4. Servo Motors
Important: The MG996R servos require more power than the Arduino can provide. You must power all your servos from an external power source and create a common ground with the Arduino.

Motor 1 (controlled by X-axis):

Signal wire to Arduino Digital Pin 5

VCC wire to the positive (+) rail of your external power supply

GND wire to the negative (-) rail of your external power supply

Motor 2 (controlled by Y-axis):

Signal wire to Arduino Digital Pin 6

VCC wire to the positive (+) rail of your external power supply

GND wire to the negative (-) rail of your external power supply

Motor 3 (controlled by X-axis):

Signal wire to Arduino Digital Pin 9

VCC wire to the positive (+) rail of your external power supply

GND wire to the negative (-) rail of your external power supply

Motor 4 (controlled by Y-axis):

Signal wire to Arduino Digital Pin 10

VCC wire to the positive (+) rail of your external power supply

GND wire to the negative (-) rail of your external power supply

Gripper Servo:

Signal wire to Arduino Digital Pin 11

VCC wire to the positive (+) rail of your external power supply

GND wire to the negative (-) rail of your external power supply

Common Ground: Connect the GND of your external power supply to the GND on the Arduino. This is critical for the servos to receive a proper signal.

This wiring diagram will ensure all components are properly connected and powered for the project to function as intended.
