#include <Servo.h>

// Define the pins for the joysticks and the motors.
// The joystick X-axis is connected to an analog pin (A0).
// The joystick Y-axis is connected to an analog pin (A1).
const int joystickPinX = A0;
const int joystickPinY = A1;

// The gripper joystick's X-axis is connected to an analog pin (A2).
const int gripperJoystickPinX = A2;

// All 5 motors are now servos. We need to create a Servo object for each.
// A standard servo needs a digital pin. Pins 5, 6, 9, 10, and 11 are good choices.
const int motorForwardPin = 5;
const int motorBackwardPin = 6;
const int motorLeftPin = 9;
const int motorRightPin = 10;
const int gripperServoPin = 11;

// Create a Servo object for each motor.
Servo motorForward;
Servo motorBackward;
Servo motorLeft;
Servo motorRight;
Servo gripperServo;

// Variables to store the joystick values.
int joystickValueX = 0;
int joystickValueY = 0;
int gripperJoystickValueX = 0;

// Set a threshold for the center and outer positions of the joystick.
const int NEUTRAL_ZONE_MIN = 400;
const int NEUTRAL_ZONE_MAX = 600;

// Define the angles for the servo movements.
const int GRIPPER_OPEN_ANGLE = 160;
const int GRIPPER_CLOSED_ANGLE = 20;

// Define the angles for forward, backward, and stopping the drive servos.
// Note: These values might need to be adjusted based on your robot's wheels/gearing.
const int SERVO_FORWARD_ANGLE = 180;
const int SERVO_BACKWARD_ANGLE = 0;
const int SERVO_STOP_ANGLE = 90;

void setup() {
  // Attach all five Servo objects to their respective pins.
  // This tells the Arduino which pins are used to control the servos.
  motorForward.attach(motorForwardPin);
  motorBackward.attach(motorBackwardPin);
  motorLeft.attach(motorLeftPin);
  motorRight.attach(motorRightPin);
  gripperServo.attach(gripperServoPin);

  // Initialize the Serial Monitor for debugging.
  Serial.begin(9600);
}

void loop() {
  // Read the analog values from the joysticks.
  joystickValueX = analogRead(joystickPinX);
  joystickValueY = analogRead(joystickPinY);
  gripperJoystickValueX = analogRead(gripperJoystickPinX);

  // Print the current joystick values to the Serial Monitor.
  Serial.print("X: ");
  Serial.print(joystickValueX);
  Serial.print(" | Y: ");
  Serial.print(joystickValueY);
  Serial.print(" | Gripper X: ");
  Serial.println(gripperJoystickValueX);

  // Stop all four drive motors by default.
  motorForward.write(SERVO_STOP_ANGLE);
  motorBackward.write(SERVO_STOP_ANGLE);
  motorLeft.write(SERVO_STOP_ANGLE);
  motorRight.write(SERVO_STOP_ANGLE);

  // ----- Control for the four drive motors -----
  // The 'if/else if' structure now ensures that only one of the four drive servos
  // is controlled at any one time based on the primary joystick direction.
  
  // Check for UP (Forward) movement on the Y-axis.
  if (joystickValueY > NEUTRAL_ZONE_MAX) {
    motorForward.write(SERVO_FORWARD_ANGLE);
  }
  // Check for DOWN (Backward) movement on the Y-axis.
  else if (joystickValueY < NEUTRAL_ZONE_MIN) {
    motorBackward.write(SERVO_BACKWARD_ANGLE);
  }
  // Check for LEFT movement on the X-axis (pivot turn).
  else if (joystickValueX < NEUTRAL_ZONE_MIN) {
    motorLeft.write(SERVO_FORWARD_ANGLE);
  }
  // Check for RIGHT movement on the X-axis (pivot turn).
  else if (joystickValueX > NEUTRAL_ZONE_MAX) {
    motorRight.write(SERVO_FORWARD_ANGLE);
  }

  // ----- Control for the gripper servo -----
  // The logic remains the same for the gripper servo, using the joystick's X-axis
  // to command the servo to a specific open or closed angle.
  if (gripperJoystickValueX > NEUTRAL_ZONE_MAX) {
    gripperServo.write(GRIPPER_OPEN_ANGLE);
  } else if (gripperJoystickValueX < NEUTRAL_ZONE_MIN) {
    gripperServo.write(GRIPPER_CLOSED_ANGLE);
  }

  // A small delay to keep the loop from running too fast.
  delay(10);
}
