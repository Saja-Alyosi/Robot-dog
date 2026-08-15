/*
 * ═══════════════════════════════════════════════════════════════════
 * QUADRUPED ROBOT - ESP32
 * Enhanced version with faster processing and WiFi capability
 * ═══════════════════════════════════════════════════════════════════
 */

#include <ESP32Servo.h>

// Servo objects
Servo frontRight, frontLeft, backRight, backLeft;

// GPIO pin assignments (flexible on ESP32)
const int PIN_FR = 18;  // Front Right
const int PIN_FL = 19;  // Front Left
const int PIN_BR = 21;  // Back Right
const int PIN_BL = 22;  // Back Left

// Motion parameters
const int STAND_ANGLE = 90;
const int LEG_LIFT = 30;
const int STEP_DELAY = 250;   // Faster on ESP32
const int PUSH_DELAY = 350;

void setup() {
  Serial.begin(115200);  // Higher baud rate
  
  // Attach servos to GPIO pins
  frontRight.attach(PIN_FR);
  frontLeft.attach(PIN_FL);
  backRight.attach(PIN_BR);
  backLeft.attach(PIN_BL);
  
  Serial.println("\n🤖 ESP32 Robot Starting...");
  robotStand();
  delay(2000);
  Serial.println("✅ Walking mode activated!");
}

void loop() {
  robotWalkSmooth();
}

void robotStand() {
  frontRight.write(STAND_ANGLE);
  frontLeft.write(STAND_ANGLE);
  backRight.write(STAND_ANGLE);
  backLeft.write(STAND_ANGLE);
}

void robotWalkSmooth() {
  // Diagonal pair 1
  frontLeft.write(STAND_ANGLE + LEG_LIFT);
  backRight.write(STAND_ANGLE - LEG_LIFT);
  delay(STEP_DELAY);
  
  // Diagonal pair 2
  frontRight.write(STAND_ANGLE + LEG_LIFT);
  backLeft.write(STAND_ANGLE - LEG_LIFT);
  delay(STEP_DELAY);
  
  // Push phase
  robotStand();
  delay(PUSH_DELAY);
}