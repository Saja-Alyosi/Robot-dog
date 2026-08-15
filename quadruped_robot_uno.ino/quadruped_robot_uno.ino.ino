/*
 * ═══════════════════════════════════════════════════════════════════
 * QUADRUPED ROBOT - Arduino UNO R3
 * Four-legged walking robot using 4 servo motors
 * ═══════════════════════════════════════════════════════════════════
 */

#include <Servo.h>

// Servo objects for each leg
Servo frontRight, frontLeft, backRight, backLeft;

// Pin assignments (PWM pins)
const int PIN_FR = 3;   // Front Right
const int PIN_FL = 5;   // Front Left
const int PIN_BR = 6;   // Back Right
const int PIN_BL = 9;   // Back Left

// Motion parameters
const int STAND_ANGLE = 90;    // Neutral position
const int LEG_LIFT = 30;       // Lift height
const int STEP_DELAY = 300;    // Step timing
const int PUSH_DELAY = 400;    // Push timing

void setup() {
  Serial.begin(9600);
  
  // Attach servos to pins
  frontRight.attach(PIN_FR);
  frontLeft.attach(PIN_FL);
  backRight.attach(PIN_BR);
  backLeft.attach(PIN_BL);
  
  Serial.println("🤖 Robot Initializing...");
  robotStand();
  delay(2000);
  Serial.println("✅ Ready to walk!");
}

void loop() {
  robotWalk();
}

// ═══════════════════════════════════════════════════════════════════
// Robot Standing Position
// ═══════════════════════════════════════════════════════════════════

void robotStand() {
  frontRight.write(STAND_ANGLE);
  frontLeft.write(STAND_ANGLE);
  backRight.write(STAND_ANGLE);
  backLeft.write(STAND_ANGLE);
  Serial.println("📍 Standing");
}

// ═══════════════════════════════════════════════════════════════════
// Walking Gait - Trotting Pattern
// ═══════════════════════════════════════════════════════════════════
/*
 * TROTTING GAIT SEQUENCE:
 * 
 * Step 1: Lift diagonal pair #1 (FL + BR)
 * Step 2: Lift diagonal pair #2 (FR + BL)
 * Step 3: Push all legs for forward momentum
 */

void robotWalk() {
  // Step 1: First diagonal pair
  Serial.println("Step 1️⃣");
  frontLeft.write(STAND_ANGLE + LEG_LIFT);
  backRight.write(STAND_ANGLE - LEG_LIFT);
  delay(STEP_DELAY);
  
  // Step 2: Second diagonal pair
  Serial.println("Step 2️⃣");
  frontRight.write(STAND_ANGLE + LEG_LIFT);
  backLeft.write(STAND_ANGLE - LEG_LIFT);
  delay(STEP_DELAY);
  
  // Step 3: Push phase
  Serial.println("Step 3️⃣");
  robotStand();
  delay(PUSH_DELAY);
}