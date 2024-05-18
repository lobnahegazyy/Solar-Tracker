#include <Servo.h>

Servo vertical; // Vertical servo

// LDR pin connections
int ldrPin1 = 8; // Digital pin for LDR 1
int ldrPin2 = 9; // Digital pin for LDR 2

// Servo angle limits
const int verticalMinAngle = 0;
const int verticalMaxAngle = 180;

void setup() {
  vertical.attach(7); // Attach vertical servo to pin 6
  vertical.write(180); // Set initial position to 180 degrees
  pinMode(ldrPin1, INPUT); // Set LDR pin 1 as input
  pinMode(ldrPin2, INPUT); // Set LDR pin 2 as input
}

void loop() {
  // Read light levels from LDRs
  int lightLevel1 = digitalRead(ldrPin1);
  int lightLevel2 = digitalRead(ldrPin2);

  // Calculate the difference between light levels
  int lightDifference = lightLevel1 - lightLevel2;

  // Define servo movement increment
  int movementIncrement = 5;

  // Adjust servo position based on light difference
  if (lightDifference > 0) {
    vertical.write(vertical.read() - movementIncrement); // Move servo forward
  } else if (lightDifference < 0) {
    vertical.write(vertical.read() + movementIncrement); // Move servo backward
  }

  delay(100); // Adjust delay as needed
}