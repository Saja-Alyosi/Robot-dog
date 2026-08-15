# 🤖 Quadruped Robot Dog

> **Four-Legged Walking Robot | Arduino UNO & ESP32 Complete Guide**

![Robot Dog](https://img.shields.io/badge/Status-Complete-success?style=flat-square)
![License](https://img.shields.io/badge/License-Educational-blue?style=flat-square)
![Level](https://img.shields.io/badge/Level-Intermediate-yellow?style=flat-square)

---

## 📖 Table of Contents

- [🎯 Overview](#overview)
- [📦 Components](#components)
- [🏗️ Project Phases](#project-phases)
- [⚡ Pin Configuration](#pin-configuration)
- [🔌 Wiring Diagram](#wiring-diagram)
- [💻 Arduino Code](#arduino-code)
- [🚀 ESP32 Code](#esp32-code)
- [📊 Comparison](#comparison)
- [🔧 Troubleshooting](#troubleshooting)
- [📸 Photos](#photos)

---

## 🎯 Overview

Build a **fully functional quadruped walking robot** with:
- ✅ 4 Independent Servo Motors
- ✅ 3D-Printed Components (OnShape + FDM)
- ✅ Arduino UNO or ESP32 Control
- ✅ Natural Trotting Gait Pattern
- ✅ Breadboard-Based Electronics
---

## 📦 Components

### Electronic Components

| Component | Qty | Purpose | Specs |
|-----------|-----|---------|-------|
| **Servo Motor** | 4 | Leg actuation | 180° rotation, 5V |
| **Arduino UNO** | 1 | Microcontroller | 16 MHz, 2KB RAM |
| **ESP32** | 1 | Alternative MCU | 240 MHz, 520KB RAM |
| **Breadboard** | 2 | Circuit mounting | 830 holes |
| **Jumper Wires** | 30+ | Connections | Male-to-male |
| **Power Supply** | 1 | Servo power | 5V / 2A minimum |

### 3D-Printed Parts

| Part | Qty | Material | Print Time |
|------|-----|----------|-----------|
| **Chassis** | 1 | PLA | ~4 hours |
| **Front Legs** | 2 | PLA | ~1.5 hours each |
| **Back Legs** | 2 | PLA | ~1.5 hours each |
| **Servo Mounts** | 4 | PLA | Built-in |

---

## 🏗️ Project Phases

### Phase 1️⃣: Design (OnShape)
```
Dimensions:
├─ Body Length: 120 mm
├─ Body Width:  80 mm
├─ Leg Length:  60 mm
└─ Total Height: 100 mm (standing)
```

**Features:**
- Optimized servo mounting angles
- Cable routing grooves
- Lightweight structure
- Balanced weight distribution

---

### Phase 2️⃣: 3D Printing (FDM)

**Printer Settings:**
```
├─ Layer Height:    0.2 mm
├─ Nozzle Temp:     200-210°C
├─ Bed Temp:        60°C
├─ Support:         Tree supports
├─ Infill:          20-30%
└─ Total Time:      10-12 hours
```

**Post-Processing:**
1. Remove support material
2. Sand rough edges (200-400 grit)
3. Test-fit servo motors
4. Apply superglue to mounts

---

### Phase 3️⃣: Assembly

```
Step 1: Prepare Chassis
  └─ Clean parts
  └─ Test-fit servos
  └─ Verify leg rotation

Step 2: Attach Servos
  ├─ FR Servo → Leg 1
  ├─ FL Servo → Leg 2
  ├─ BR Servo → Leg 3
  └─ BL Servo → Leg 4

Step 3: Mount Electronics
  ├─ Place breadboards
  ├─ Attach microcontroller
  ├─ Organize servo cables
  └─ Route power/signal wires

Step 4: Verify Mechanics
  └─ Test servo ranges
  └─ Confirm no obstruction
  └─ Calibrate angles
```

---

### Phase 4️⃣: Programming

Upload code to microcontroller → Test walking pattern → Calibrate gait

---

## ⚡ Pin Configuration

### Arduino UNO R3

```cpp
┌─────────────────────────────────────┐
│      Arduino UNO PWM Pins           │
├─────────────────────────────────────┤
│ Front Right (FR) → Digital Pin 3    │
│ Front Left (FL)  → Digital Pin 5    │
│ Back Right (BR)  → Digital Pin 6    │
│ Back Left (BL)   → Digital Pin 9    │
├─────────────────────────────────────┤
│ Power:           +5V                │
│ Ground:          GND                │
└─────────────────────────────────────┘
```

### ESP32 DevKit

```cpp
┌─────────────────────────────────────┐
│       ESP32 GPIO Pins               │
├─────────────────────────────────────┤
│ Front Right (FR) → GPIO 18          │
│ Front Left (FL)  → GPIO 19          │
│ Back Right (BR)  → GPIO 21          │
│ Back Left (BL)   → GPIO 22          │
├─────────────────────────────────────┤
│ Power:           +5V                │
│ Ground:          GND                │
└─────────────────────────────────────┘
```

---

## 🔌 Wiring Diagram

### Servo Motor Connections

Each servo has **3 wires:**

```
Servo Motor
├─ 🔴 RED (5V)      → +5V Power Rail
├─ ⚫ BLACK (GND)    → Ground Rail
└─ 🟠 YELLOW (PWM)  → Signal Pin
```

### Power Distribution

```
┌──────────────────┐
│  Power Supply    │
│    5V / 2A       │
└────────┬─────────┘
         │
    ┌────┴────┐
    │          │
    ↓          ↓
 +5V Rail   GND Rail
    │          │
    ├─→ S1     ├─→ All Grounds
    ├─→ S2     │   MUST connect
    ├─→ S3     │   to same point!
    └─→ S4     │
```

⚠️ **CRITICAL:** All ground connections must connect to the same GND point!

---

## 💻 Arduino Code

### Complete Arduino UNO R3 Program

```cpp
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
```

### How to Upload

1. Connect Arduino UNO via USB
2. Open Arduino IDE
3. **Tools → Board → Arduino UNO**
4. **Tools → Port → COM3** (or your port)
5. Copy & Paste code
6. Click **Upload** button ⬆️
7. Wait for "Upload successful"
8. Disconnect USB → Connect 5V power

---

## 🚀 ESP32 Code

### Complete ESP32 Program

```cpp
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
```

### How to Upload

1. Install ESP32 board in Arduino IDE
   - File → Preferences → Additional Boards Manager URLs
   - Add: `https://dl.espressif.com/dl/package_esp32_index.json`
   - Tools → Board Manager → Search "esp32" → Install

2. **Tools → Board → ESP32 Dev Module**
3. **Tools → Port → COM3** (or your port)
4. Copy & Paste code
5. Click **Upload** button ⬆️
6. Press "Boot" button if upload fails
7. Connect 5V power

---

## 📊 Comparison

### Arduino UNO vs ESP32

| Feature | Arduino UNO | ESP32 |
|---------|-----------|-------|
| **CPU Speed** | 16 MHz | 240 MHz (15x faster) ⭐ |
| **RAM** | 2 KB | 520 KB (260x more) ⭐ |
| **Flash** | 32 KB | 4 MB ⭐ |
| **PWM Pins** | 6 | 16 ⭐ |
| **WiFi** | ❌ No | ✅ Yes ⭐ |
| **Bluetooth** | ❌ No | ✅ Yes ⭐ |
| **ADC Channels** | 6 | 12 ⭐ |
| **Cost** | $25 | $10-15 ⭐ |
| **Motion Smoothness** | Good | Excellent ⭐ |
| **Learning Curve** | Easy | Medium |

**Recommendation:** 
- **Arduino UNO:** Great for learning & prototyping
- **ESP32:** Better performance & future upgrades

---

## 🔧 Troubleshooting

### ❌ Servos Not Moving

**Causes & Solutions:**
```
┌─ Check Power Supply
│  └─ Verify 5V output (not USB power)
│  └─ Use 2A minimum power supply
│
├─ Check Connections
│  └─ All grounds connected to same point
│  └─ Signal wires on correct pins
│  └─ No loose jumper wires
│
├─ Test Servo
│  └─ Try servo on different pin
│  └─ Verify servo horn moves freely
│  └─ Check for mechanical binding
│
└─ Debug Code
   └─ Confirm pin numbers match
   └─ Test with simpler code
   └─ Check Serial output
```

### ❌ Jerky/Stuttering Motion

**Solutions:**
```
Arduino:
  ├─ Reduce Serial.print() calls
  ├─ Increase delay values
  ├─ Remove other code from loop()
  └─ Check power supply voltage

ESP32:
  ├─ Use ESP32 (much faster)
  ├─ Increase delay values slightly
  ├─ Upgrade power supply to 3A
  └─ Add cooling breaks between cycles
```

### ❌ Robot Walks in Circles

**Diagnosis:**
```
Cause #1: Servo Calibration Mismatch
  └─ Solution: Recalibrate each servo independently

Cause #2: Unequal Leg Lengths
  └─ Solution: Check 3D-printed leg dimensions

Cause #3: Friction Asymmetry
  └─ Solution: Apply light lubricant to all joints

Cause #4: Weight Distribution
  └─ Solution: Balance electronics weight on both sides
```

### ❌ Servo Overheating

**Solutions:**
```
├─ Clear any mechanical obstructions
├─ Ensure servo can rotate freely
├─ Upgrade power supply (3A recommended)
├─ Add 5-10 second break between walking cycles
├─ Check for servo stalling
└─ Reduce continuous duty cycle
```

---

## ⚙️ Specifications

| Parameter | Value |
|-----------|-------|
| **Power Requirement** | 5V / 2A minimum |
| **Servo Range** | 0-180 degrees |
| **Standing Angle** | 90 degrees (neutral) |
| **Step Angle Range** | ±30 degrees from neutral |
| **Step Duration** | 300ms (Arduino) / 250ms (ESP32) |
| **Complete Cycle** | ~1.2 seconds |
| **Robot Dimensions** | 120 × 80 × 100 mm |
| **Print Material** | PLA Filament |
| **Total Print Weight** | ~150-180g |

---

## 🎓 Learning Outcomes

By completing this project, you'll master:

- ✅ **Microcontroller Programming** - Arduino & ESP32
- ✅ **Servo Motor Control** - PWM signals, timing
- ✅ **Electronics & Wiring** - Breadboard prototyping
- ✅ **3D Modeling** - OnShape CAD design
- ✅ **3D Printing** - FDM printer settings
- ✅ **Robotics Kinematics** - Walking gaits
- ✅ **Problem Solving** - Debugging skills
- ✅ **Hardware Integration** - System assembly

---

## 📸 Photos

### 📷 Image 1: Complete Assembly
![Image 1 Placeholder](https://via.placeholder.com/500x400?text=Complete+Assembly)
*The robot in its final assembled state with all servo motors mounted*

### 📷 Image 2: Electronics & Wiring
![Image 2 Placeholder](https://via.placeholder.com/500x400?text=Electronics+Detail)
*Detailed view of servo connections and breadboard layout*

### 📷 Image 3: Mechanics & Legs
![Image 3 Placeholder](https://via.placeholder.com/500x400?text=Leg+Mechanics)
*Underneath view showing servo mounts and leg articulation*

---

## 🔗 Resources

### Online Tools & Platforms
- **OnShape:** https://www.onshape.com/ (CAD Design)
- **Arduino IDE:** https://www.arduino.cc/ (Programming)
- **Tinkercad:** https://www.tinkercad.com/ (Circuit Simulation)

### Documentation
- [Arduino Servo Library](https://www.arduino.cc/en/Reference/Servo)
- [ESP32 Documentation](https://docs.espressif.com/)
- [Servo Motor Datasheet](https://servo-datasheet.pdf)

---

## 🚀 Future Enhancements

- [ ] Add infrared sensors for obstacle avoidance
- [ ] Implement WiFi control (ESP32)
- [ ] Create Bluetooth remote interface
- [ ] Design custom walking gaits
- [ ] Add camera for navigation
- [ ] Implement voice control
- [ ] Machine learning gait optimization
- [ ] Multi-robot swarm coordination

---

## 💡 Pro Tips

1. **Start with Arduino UNO** - Easier for learning
2. **Test servos individually** before full assembly
3. **Use external power supply** - Never rely on USB power
4. **Document your wiring** - Take photos for reference
5. **Calibrate servos carefully** - This affects walking quality
6. **Add cooling breaks** - Prevent servo overheating
7. **Keep code modular** - Easy to modify & debug
8. **Back up your code** - Save to GitHub or cloud

---

## 🎯 Quick Reference

### Pin Assignments
```
Arduino:  3, 5, 6, 9 (PWM)
ESP32:   18, 19, 21, 22 (GPIO)
```

### Servo Commands
```cpp
servo.attach(pin);          // Attach to pin
servo.write(angle);         // Set angle (0-180)
servo.read();               // Get current angle
servo.detach();             // Release servo
```

### Walking Pattern
```
Angle 90:   Standing (neutral)
Angle 120:  Leg forward/up
Angle 60:   Leg backward/down
```

---

<div align="center">

![Last Updated](https://img.shields.io/badge/Last%20Updated-August%202026-blue?style=flat-square)
![Version](https://img.shields.io/badge/Version-2.0-success?style=flat-square)

</div>
