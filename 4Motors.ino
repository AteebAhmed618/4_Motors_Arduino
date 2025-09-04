// Define the pins for the joystick and the motors.
// The joystick X-axis is connected to an analog pin (A0).
// The joystick Y-axis is connected to an analog pin (A1).
// The motor pins MUST be connected to PWM pins on the Arduino (pins with a ~).
const int joystickPinX = A0;
const int joystickPinY = A1;

// Motor pins (using descriptive names for clarity)
// Using pins 5, 6, 9, 10 as they are PWM-capable on an Arduino Uno.
const int motorForward = 5;
const int motorBackward = 6;
const int motorLeft = 9;
const int motorRight = 10;

// Variables to store the joystick values.
int joystickValueX = 0;
int joystickValueY = 0;

// Set a threshold for the center and outer positions of the joystick.
// A neutral zone is needed to account for small jitters when the joystick is at rest.
const int NEUTRAL_ZONE_MIN = 400;
const int NEUTRAL_ZONE_MAX = 600;

void setup() {
  // Configure the motor pins as OUTPUTS.
  pinMode(motorForward, OUTPUT);
  pinMode(motorBackward, OUTPUT);
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);

  // Initialize the Serial Monitor for debugging.
  Serial.begin(9600);
}

void loop() {
  // Read the analog values from the joystick's X and Y-axis pins.
  joystickValueX = analogRead(joystickPinX);
  joystickValueY = analogRead(joystickPinY);

  // Print the current joystick values to the Serial Monitor.
  Serial.print("X: ");
  Serial.print(joystickValueX);
  Serial.print(" | Y: ");
  Serial.println(joystickValueY);

  // Stop all motors by setting their speed to 0.
  // This is a crucial step to ensure the motors are off by default.
  analogWrite(motorForward, 0);
  analogWrite(motorBackward, 0);
  analogWrite(motorLeft, 0);
  analogWrite(motorRight, 0);

  // Check for the joystick position and control the corresponding motor with PWM.
  // The independent 'if' statements allow for combined movements (e.g., diagonal).

  // Check for UP (Forward) movement on the Y-axis.
  if (joystickValueY > NEUTRAL_ZONE_MAX) {
    // Map the joystick value from the upper half of the range (600-1023)
    // to the motor speed range (0-255).
    int speed = map(joystickValueY, NEUTRAL_ZONE_MAX, 1023, 0, 255);
    analogWrite(motorForward, speed);
  }
  // Check for DOWN (Backward) movement on the Y-axis.
  else if (joystickValueY < NEUTRAL_ZONE_MIN) {
    // Map the joystick value from the lower half of the range (0-400)
    // to the motor speed range (0-255). Note the reversed order for mapping.
    int speed = map(joystickValueY, NEUTRAL_ZONE_MIN, 0, 0, 255);
    analogWrite(motorBackward, speed);
  }

  // Check for LEFT movement on the X-axis.
  if (joystickValueX < NEUTRAL_ZONE_MIN) {
    // Map the joystick value from the lower half of the range (0-400)
    // to the motor speed range (0-255).
    int speed = map(joystickValueX, NEUTRAL_ZONE_MIN, 0, 0, 255);
    analogWrite(motorLeft, speed);
  }
  // Check for RIGHT movement on the X-axis.
  else if (joystickValueX > NEUTRAL_ZONE_MAX) {
    // Map the joystick value from the upper half of the range (600-1023)
    // to the motor speed range (0-255).
    int speed = map(joystickValueX, NEUTRAL_ZONE_MAX, 1023, 0, 255);
    analogWrite(motorRight, speed);
  }

  // A small delay to keep the loop from running too fast.
  delay(10);
}
