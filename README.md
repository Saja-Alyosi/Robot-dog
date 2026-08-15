# 🤖 Quadruped Robot Dog - Four-Legged Walking Robot

> **A complete guide to building and programming a four-legged robotic dog using 3D-printed parts and servo motors**

---

## 📋 Table of Contents

1. [Project Overview](#project-overview)
2. [Components & Parts List](#components--parts-list)
3. [Design & 3D Printing Process](#design--3d-printing-process)
4. [Hardware Assembly](#hardware-assembly)
5. [Electrical Wiring & Connections](#electrical-wiring--connections)
6. [Programming with Arduino UNO](#programming-with-arduino-uno)
7. [Programming with ESP32](#programming-with-esp32)
8. [Code Comparison: Arduino vs ESP32](#code-comparison-arduino-vs-esp32)
9. [Troubleshooting & Tips](#troubleshooting--tips)
10. [Project Photos](#project-photos)

---

## 🎯 Project Overview

This project demonstrates how to build a **quadruped (four-legged) walking robot** that mimics natural dog locomotion. The robot uses four servo motors to control individual leg movements, creating a smooth trotting walking pattern.

### Key Features ✨

- 🦮 **4 Independent Servo Motors** - One for each leg
- 🏗️ **3D-Printed Components** - Designed in OnShape, printed on FDM printer
- 📱 **Microcontroller Compatible** - Works with Arduino UNO or ESP32
- 🔄 **Smooth Motion Control** - Sequential leg movement for natural walking
- ⚡ **Easy to Program** - Simple servo control code

### Project Phases 📊

| Phase | Description | Tool |
|-------|-------------|------|
| **Phase 1: Design** | CAD modeling and design optimization | OnShape (Cloud-based CAD) |
| **Phase 2: Fabrication** | 3D printing of all plastic components | FDM 3D Printer |
| **Phase 3: Assembly** | Hardware integration and wiring | Breadboard & Jumper Wires |
| **Phase 4: Programming** | Microcontroller firmware development | Arduino IDE or PlatformIO |

---

## 📦 Components & Parts List

### Main Components

| Component | Quantity | Purpose | Notes |
|-----------|----------|---------|-------|
| **Servo Motor** (MG996R or SG90) | 4 | Leg actuation | 180° rotation range |
| **Breadboard (830 holes)** | 2 | Component mounting | For circuit organization |
| **Jumper Wires** | 30+ | Electrical connections | Male-to-male connectors |
| **Microcontroller** | 1 | Brain of robot | Arduino UNO R3 OR ESP32 |
| **Power Supply** | 1 | Servo power | 5V/2A+ recommended |
| **USB Cable** | 1 | Programming | USB A to B for Arduino |

### 3D-Printed Parts

| Part | Quantity | Function | Orientation |
|------|----------|----------|-------------|
| **Robot Chassis** | 1 | Main body frame | Horizontal |
| **Front Legs** | 2 | Forward movement | Vertical |
| **Back Legs** | 2 | Backward support | Vertical |
| **Servo Mounts** | 4 | Servo attachment brackets | Integrated |

---

## 🎨 Design & 3D Printing Process

### Stage 1️⃣ : CAD Design (OnShape)

The robot was designed entirely in **OnShape** - a cloud-based CAD platform:

**Design Considerations:**
- ✅ Leg length proportional to body size
- ✅ Servo mounting points aligned with rotation axes
- ✅ Weight distribution for stability
- ✅ Cable routing for servo connections

**Key Design Features:**
```
Body Length:      120mm
Body Width:       80mm
Leg Length:       60mm
Servo Spacing:    25mm
Total Height:     100mm (standing)
```

### Stage 2️⃣ : 3D Printing

**FDM Printer Settings:**
- Layer Height: 0.2mm
- Nozzle Temp: 200-210°C
- Bed Temp: 60°C
- Support: Tree supports
- Orientation: Optimized for minimal supports
- Infill: 20-30%

**Print Results:**
- 4 servo mount brackets: ~1.5 hours each
- 1 chassis body: ~4 hours
- Total print time: ~10-12 hours
- Material used: ~150-180g PLA filament

**Post-Processing:**
1. Remove all support material carefully
2. Sand down rough edges with 200-400 grit sandpaper
3. Test-fit servo motors before assembly
4. Apply superglue to servo mounts for permanent bonding

---

## 🔧 Hardware Assembly

### Step 1: Prepare the Chassis

1. Clean all 3D-printed parts
2. Test-fit servo motors into mounting brackets
3. Verify leg rotation without obstruction
4. Apply threadlock to all screw connections

### Step 2: Attach Servo Motors

```
Front Right Servo → Leg 1 (FR)
Front Left Servo  → Leg 2 (FL)
Back Right Servo  → Leg 3 (BR)
Back Left Servo   → Leg 4 (BL)
```

**Assembly Tips:**
- Ensure servo horns point downward
- Leave 2-3mm clearance for rotation
- Secure servo arms with small M2 screws
- Apply locating pin for accurate positioning

### Step 3: Mount Electronics

1. Place breadboards on chassis using double-sided tape
2. Mount microcontroller (Arduino or ESP32) on breadboard
3. Organize servo cables along chassis groove
4. Secure power wires with zip ties
5. Route signal wires away from power lines (noise prevention)

### Step 4: Verify Mechanical Movement

1. Apply 5V power (no microcontroller yet)
2. Manually test each servo range (0-180°)
3. Confirm leg movement doesn't hit chassis
4. Adjust servo horn position if needed

---

## ⚡ Electrical Wiring & Connections

### Pin Configuration (CRITICAL)

#### Arduino UNO R3 Connections

```
Servo PIN Assignment (Arduino UNO)
═══════════════════════════════════

Front Right Servo  → Digital Pin 3  (PWM)
Front Left Servo   → Digital Pin 5  (PWM)
Back Right Servo   → Digital Pin 6  (PWM)
Back Left Servo    → Digital Pin 9  (PWM)

Power Distribution:
════════════════════
Servo Power (Red)   → +5V Rail
Servo Ground (Blk)  → GND Rail
Arduino GND         → Power GND (IMPORTANT!)
USB Power Supply    → Arduino +5V & GND
```

#### ESP32 Connections

```
Servo PIN Assignment (ESP32)
═════════════════════════════

Front Right Servo  → GPIO 18 (supports PWM)
Front Left Servo   → GPIO 19 (supports PWM)
Back Right Servo   → GPIO 21 (supports PWM)
Back Left Servo    → GPIO 22 (supports PWM)

Power Distribution:
════════════════════
Servo Power (Red)   → 5V Rail
Servo Ground (Blk)  → GND Rail
ESP32 GND           → Power GND (IMPORTANT!)
USB Power Supply    → ESP32 +5V & GND
```

### Wiring Diagram (Text Format)

```
┌─────────────────────────────────────────┐
│        Power Supply (5V/2A)             │
│                                         │
│    RED ────→ +5V Rail                  │
│    BLACK ──→ GND Rail                  │
└─────────────────────────────────────────┘
          │                │
          ↓                ↓
   ┌──────────────┐  ┌──────────────┐
   │  Breadboard  │  │  Breadboard  │
   │   (Module 1) │  │   (Module 2) │
   └──────────────┘  └──────────────┘
          │                │
        ┌─┴─────────────────┴─┐
        │   Servo Connections │
        ├─────────────────────┤
        │ FR Servo: Signal→P3 │  Arduino
        │ FL Servo: Signal→P5 │
        │ BR Servo: Signal→P6 │
        │ BL Servo: Signal→P9 │
        └─────────────────────┘
```

### Servo Motor Wiring

Each servo has **3 wires**:

| Wire Color | Voltage | Purpose |
|-----------|---------|---------|
| 🔴 **RED** | +5V | Power supply |
| ⚫ **BLACK** | GND | Ground return |
| 🟠 **YELLOW** | PWM Signal | Microcontroller signal |

**CRITICAL:** All ground connections must be connected to the same point!

---

## 💻 Programming with Arduino UNO

### Arduino UNO Code

```cpp
/*
 * ═══════════════════════════════════════════════════════════════════
 * QUADRUPED ROBOT DOG - Arduino UNO R3 VERSION
 * ═══════════════════════════════════════════════════════════════════
 * Four-legged walking robot using 4 servo motors
 * Compatible with Arduino UNO R3 and breadboard prototyping
 * 
 * ➜ Pin Assignment (PWM Required):
 *    - Front Right: Digital Pin 3
 *    - Front Left:  Digital Pin 5
 *    - Back Right:  Digital Pin 6
 *    - Back Left:   Digital Pin 9
 * 
 * ➜ Power Supply: 5V/2A+ external source
 * ═══════════════════════════════════════════════════════════════════
 */

#include <Servo.h>  // ✓ Standard Arduino servo library

// ═════════════════════════════════════════════════════════════════════
// SERVO OBJECT DECLARATIONS
// ═════════════════════════════════════════════════════════════════════

Servo frontRight;   // Front Right leg servo
Servo frontLeft;    // Front Left leg servo
Servo backRight;    // Back Right leg servo
Servo backLeft;     // Back Left leg servo

// ═════════════════════════════════════════════════════════════════════
// PIN DEFINITIONS (Arduino UNO Digital PWM Pins)
// ═════════════════════════════════════════════════════════════════════

const int PIN_FR = 3;   // ⚙️ Front Right servo control pin
const int PIN_FL = 5;   // ⚙️ Front Left servo control pin
const int PIN_BR = 6;   // ⚙️ Back Right servo control pin
const int PIN_BL = 9;   // ⚙️ Back Left servo control pin

// ═════════════════════════════════════════════════════════════════════
// MOTION PARAMETERS
// ═════════════════════════════════════════════════════════════════════

const int STAND_ANGLE = 90;      // 📍 Neutral standing position
const int LEG_LIFT = 30;         // 🔼 Degrees to lift leg (diagonal)
const int STEP_DELAY = 300;      // ⏱️  Milliseconds per step
const int PUSH_DELAY = 400;      // ⏱️  Milliseconds for push phase

// ═════════════════════════════════════════════════════════════════════
// SETUP FUNCTION - Runs once on startup
// ═════════════════════════════════════════════════════════════════════

void setup() {
  Serial.begin(9600);  // Open serial for debugging
  
  // Attach all servo objects to their respective pins
  frontRight.attach(PIN_FR);
  frontLeft.attach(PIN_FL);
  backRight.attach(PIN_BR);
  backLeft.attach(PIN_BL);
  
  Serial.println("🤖 Robot Initializing...");
  delay(500);
  
  // Move robot to standing position
  robotStand();
  Serial.println("✅ Robot Ready!");
  delay(2000);
}

// ═════════════════════════════════════════════════════════════════════
// MAIN LOOP - Continuous execution
// ═════════════════════════════════════════════════════════════════════

void loop() {
  // Infinite walking sequence
  robotWalk();
}

// ═════════════════════════════════════════════════════════════════════
// FUNCTION: robotStand() - Return robot to neutral standing position
// ═════════════════════════════════════════════════════════════════════

void robotStand() {
  // All legs at 90° (neutral)
  frontRight.write(STAND_ANGLE);
  frontLeft.write(STAND_ANGLE);
  backRight.write(STAND_ANGLE);
  backLeft.write(STAND_ANGLE);
  
  Serial.println("📍 Standing Position");
}

// ═════════════════════════════════════════════════════════════════════
// FUNCTION: robotWalk() - Main walking gait sequence
// ═════════════════════════════════════════════════════════════════════
/*
 * TROTTING GAIT PATTERN:
 * 
 * In nature, quadrupeds use a "trotting" gait where diagonal legs
 * move together for efficiency and balance.
 * 
 * Step 1: Lift Front-Left & Back-Right (diagonal)
 * Step 2: Lift Front-Right & Back-Left (opposite diagonal)
 * Step 3: Push all legs together for forward momentum
 */

void robotWalk() {
  // 🐾 STEP 1: Lift diagonal pair #1 (Front-Left + Back-Right)
  Serial.println("Step 1️⃣: Lift FL & BR diagonals");
  frontLeft.write(STAND_ANGLE + LEG_LIFT);   // Lift front-left
  backRight.write(STAND_ANGLE - LEG_LIFT);   // Lift back-right
  delay(STEP_DELAY);
  
  // 🐾 STEP 2: Lift diagonal pair #2 (Front-Right + Back-Left)
  Serial.println("Step 2️⃣: Lift FR & BL diagonals");
  frontRight.write(STAND_ANGLE + LEG_LIFT);  // Lift front-right
  backLeft.write(STAND_ANGLE - LEG_LIFT);    // Lift back-left
  delay(STEP_DELAY);
  
  // 🐾 STEP 3: Push phase - All legs extend for forward momentum
  Serial.println("Step 3️⃣: Push forward");
  robotStand();  // Return all to neutral for push
  delay(PUSH_DELAY);
}

// ═════════════════════════════════════════════════════════════════════
// END OF CODE
// ═════════════════════════════════════════════════════════════════════
```

### Upload to Arduino

1. **Connect Arduino to Computer** via USB
2. **Open Arduino IDE** (arduino.cc)
3. **Select Board:** Tools → Board → Arduino UNO
4. **Select Port:** Tools → Port → COM3 (or your port)
5. **Copy & Paste** the code above
6. **Click Upload** (⬆️ button)
7. **Wait** for "Upload successful" message
8. **Disconnect USB** and connect external 5V power

---

## 🚀 Programming with ESP32

### ESP32 Advantages Over Arduino UNO

| Feature | Arduino UNO | ESP32 |
|---------|-----------|-------|
| **Processing Speed** | 16 MHz | 240 MHz (15x faster) |
| **RAM** | 2 KB | 520 KB |
| **WiFi** | ❌ No | ✅ Yes |
| **Bluetooth** | ❌ No | ✅ Yes |
| **PWM Pins** | 6 | 16 |
| **ADC Channels** | 6 | 12 |
| **Cost** | $25 | $10-15 |

### ESP32 Code

```cpp
/*
 * ═══════════════════════════════════════════════════════════════════
 * QUADRUPED ROBOT DOG - ESP32 VERSION
 * ═══════════════════════════════════════════════════════════════════
 * Enhanced version with WiFi capabilities and improved performance
 * 
 * ➜ Pin Assignment (Any PWM-capable GPIO):
 *    - Front Right: GPIO 18
 *    - Front Left:  GPIO 19
 *    - Back Right:  GPIO 21
 *    - Back Left:   GPIO 22
 * 
 * ➜ Advantages:
 *    ✓ Native ESP32Servo library support
 *    ✓ 240 MHz processing vs 16 MHz (15x faster)
 *    ✓ More responsive servo control
 *    ✓ Future WiFi integration capability
 * ═══════════════════════════════════════════════════════════════════
 */

#include <ESP32Servo.h>  // ✓ ESP32-optimized servo library

// ═════════════════════════════════════════════════════════════════════
// SERVO OBJECT DECLARATIONS
// ═════════════════════════════════════════════════════════════════════

Servo frontRight;   // Front Right leg servo
Servo frontLeft;    // Front Left leg servo
Servo backRight;    // Back Right leg servo
Servo backLeft;     // Back Left leg servo

// ═════════════════════════════════════════════════════════════════════
// GPIO PIN DEFINITIONS (ESP32 Flexible PWM)
// ═════════════════════════════════════════════════════════════════════

const int PIN_FR = 18;   // ⚙️ Front Right servo control pin
const int PIN_FL = 19;   // ⚙️ Front Left servo control pin
const int PIN_BR = 21;   // ⚙️ Back Right servo control pin
const int PIN_BL = 22;   // ⚙️ Back Left servo control pin

// ═════════════════════════════════════════════════════════════════════
// MOTION PARAMETERS
// ═════════════════════════════════════════════════════════════════════

const int STAND_ANGLE = 90;       // 📍 Neutral standing position
const int LEG_LIFT = 30;          // 🔼 Degrees to lift leg
const int STEP_DELAY = 250;       // ⏱️  Faster step (ESP32 advantage)
const int PUSH_DELAY = 350;       // ⏱️  Push phase timing

// ═════════════════════════════════════════════════════════════════════
// SETUP FUNCTION - Runs once on startup
// ═════════════════════════════════════════════════════════════════════

void setup() {
  Serial.begin(115200);  // ESP32 supports higher baud rate
  
  Serial.println("\n🤖 ESP32 Quadruped Robot - Initializing...");
  delay(500);
  
  // Attach all servo objects to GPIO pins
  frontRight.attach(PIN_FR);
  frontLeft.attach(PIN_FL);
  backRight.attach(PIN_BR);
  backLeft.attach(PIN_BL);
  
  Serial.println("✅ Servo motors attached");
  
  // Move robot to standing position
  robotStand();
  Serial.println("✅ Robot Standing - Ready for autonomous walking!");
  delay(2000);
}

// ═════════════════════════════════════════════════════════════════════
// MAIN LOOP - Continuous execution
// ═════════════════════════════════════════════════════════════════════

void loop() {
  // Infinite walking sequence with smooth motion
  robotWalkSmooth();
}

// ═════════════════════════════════════════════════════════════════════
// FUNCTION: robotStand() - Neutral standing position
// ═════════════════════════════════════════════════════════════════════

void robotStand() {
  frontRight.write(STAND_ANGLE);
  frontLeft.write(STAND_ANGLE);
  backRight.write(STAND_ANGLE);
  backLeft.write(STAND_ANGLE);
}

// ═════════════════════════════════════════════════════════════════════
// FUNCTION: robotWalkSmooth() - Smooth trotting gait
// ═════════════════════════════════════════════════════════════════════

void robotWalkSmooth() {
  // 🐾 STEP 1: Diagonal lift #1
  Serial.print("📍 Step 1: ");
  smoothMovePair(PIN_FL, STAND_ANGLE + LEG_LIFT, PIN_BR, STAND_ANGLE - LEG_LIFT, 50);
  delay(STEP_DELAY);
  
  // 🐾 STEP 2: Diagonal lift #2
  Serial.print("📍 Step 2: ");
  smoothMovePair(PIN_FR, STAND_ANGLE + LEG_LIFT, PIN_BL, STAND_ANGLE - LEG_LIFT, 50);
  delay(STEP_DELAY);
  
  // 🐾 STEP 3: Push phase
  Serial.println("📍 Step 3: Push!");
  robotStand();
  delay(PUSH_DELAY);
}

// ═════════════════════════════════════════════════════════════════════
// FUNCTION: smoothMovePair() - Interpolated smooth motion
// ═════════════════════════════════════════════════════════════════════
/*
 * This function moves two servos smoothly using linear interpolation.
 * Instead of jumping to target angle, it gradually steps through angles
 * for more natural, lifelike motion.
 * 
 * Parameters:
 *   servo1Pin, target1: First servo pin and target angle
 *   servo2Pin, target2: Second servo pin and target angle
 *   steps: Number of interpolation steps (higher = smoother)
 */

void smoothMovePair(int servo1Pin, int target1, int servo2Pin, int target2, int steps) {
  Servo temp1, temp2;
  temp1.attach(servo1Pin);
  temp2.attach(servo2Pin);
  
  int current1 = temp1.read();
  int current2 = temp2.read();
  
  for (int i = 0; i <= steps; i++) {
    int angle1 = current1 + (target1 - current1) * i / steps;
    int angle2 = current2 + (target2 - current2) * i / steps;
    
    temp1.write(angle1);
    temp2.write(angle2);
    delay(5);  // Small delay between interpolation steps
  }
  
  temp1.detach();
  temp2.detach();
}

// ═════════════════════════════════════════════════════════════════════
// END OF CODE
// ═════════════════════════════════════════════════════════════════════
```

### Upload to ESP32

1. **Install ESP32 Board** in Arduino IDE:
   - File → Preferences → Additional Boards Manager URLs
   - Add: `https://dl.espressif.com/dl/package_esp32_index.json`
   - Tools → Board Manager → Search "esp32" → Install

2. **Select ESP32 Board:**
   - Tools → Board → ESP32 Dev Module

3. **Upload Code:**
   - Copy the ESP32 code above
   - Click Upload
   - Press "Boot" button on ESP32 if upload fails

---

## 🔄 Code Comparison: Arduino vs ESP32

### Key Differences

| Aspect | Arduino UNO | ESP32 |
|--------|-----------|-------|
| **Library** | `#include <Servo.h>` | `#include <ESP32Servo.h>` |
| **Pin Type** | Fixed PWM pins | Any GPIO (more flexible) |
| **Speed** | 16 MHz | 240 MHz (15× faster) |
| **Min Delay** | ~1 ms acceptable | ~0.1 ms possible |
| **Smooth Motion** | Good | Excellent |
| **Baud Rate** | 9600 typical | 115200 supported |

### Feature Comparison Table

```
╔═════════════════════╦════════════╦═════════╗
║ FEATURE             ║ Arduino    ║ ESP32   ║
╠═════════════════════╬════════════╬═════════╣
║ Processing Power    ║ ⭐⭐      ║ ⭐⭐⭐⭐⭐║
║ Motion Smoothness   ║ ⭐⭐⭐    ║ ⭐⭐⭐⭐⭐║
║ Pin Flexibility     ║ ⭐⭐      ║ ⭐⭐⭐⭐⭐║
║ WiFi Capable        ║ ❌        ║ ✅     ║
║ Bluetooth Capable   ║ ❌        ║ ✅     ║
║ Cost                ║ $$$       ║ $     ║
║ Learning Curve      ║ ⭐⭐      ║ ⭐⭐⭐  ║
╚═════════════════════╩════════════╩═════════╝
```

---

## 🔧 Troubleshooting & Tips

### Problem: Servos Not Moving

**Solution:**
1. ✅ Check power supply voltage (should be 5V)
2. ✅ Verify all ground connections are complete
3. ✅ Test servo with known working code
4. ✅ Check pin assignments match your wiring

### Problem: Jerky/Stuttering Motion

**Arduino:**
- Reduce other code operations
- Avoid Serial.print() in loop()
- Use delay instead of millis()

**ESP32:**
- Increase delay values slightly
- Use `delay()` for more consistent timing
- Check power supply under load

### Problem: Robot Walks in Circles

**Causes:**
- Servo calibration mismatch
- Uneven leg lengths
- Friction asymmetry

**Solutions:**
1. Calibrate each servo individually
2. Verify 3D-printed legs are identical
3. Check all servo mounting angles
4. Apply light oil to leg joints

### Problem: Servo Overheating

**Causes:**
- Continuous stalling
- Excessive torque demand
- Poor power supply

**Solutions:**
- Ensure servo can move freely
- Use high-quality power supply (2A+)
- Add cooling breaks (delay every cycle)
- Check for mechanical obstruction

### Pro Tips 💡

1. **Battery Powered:** Use external 5V power supply, not USB
2. **Calibration:** Test each servo independently first
3. **Smooth Motion:** Shorter delays = smoother but requires more power
4. **Current Draw:** 4 servos × 500mA = 2A minimum supply
5. **Cable Management:** Keep signal wires separate from power
6. **Future Upgrades:**
   - Add distance sensor for obstacle avoidance
   - Implement WiFi control (ESP32)
   - Add camera for environment mapping
   - Create custom gaits via web interface

---

## 📸 Project Photos

### 📷 Image 1: Complete Assembly Overview
![Quadruped Robot Assembly](https://via.placeholder.com/400x300?text=Assembly+Overview)
*The robot in its final assembled state with all four servo motors mounted and breadboard electronics integrated*

### 📷 Image 2: Electronics & Wiring
![Electronics Close-up](https://via.placeholder.com/400x300?text=Electronics+Detail)
*Detailed view of servo connections, breadboard layout, and power distribution using jumper wires*

### 📷 Image 3: Bottom View & Leg Mechanics
![Bottom Mechanics](https://via.placeholder.com/400x300?text=Mechanics+Detail)
*Underneath view showing servo mounts, leg articulation points, and mechanical linkages*

---

## 📚 Resources & References

### Online Platforms & Tools

🔗 **OnShape CAD:** https://www.onshape.com/
- Cloud-based 3D modeling platform
- Free for educational projects
- Used for entire robot design

🔗 **Arduino Official:** https://www.arduino.cc/
- Download Arduino IDE
- Official documentation
- Community forums

🔗 **ESP32 Documentation:** https://docs.espressif.com/
- Hardware specifications
- Software development kit
- Technical references

### Library Documentation

- **Servo Library (Arduino):** Built-in standard library
- **ESP32Servo Library:** Optimized for ESP32 microcontroller

### Video Tutorials

- Arduino Servo Control Basics
- ESP32 Getting Started Guide
- 3D Printing Optimization Tips
- Quadruped Robotics Principles

---

## 🚀 Future Enhancements

### Phase 5: Advanced Features

- [ ] **Autonomous Walking:** Add IR sensors for obstacle detection
- [ ] **WiFi Control:** Stream video and control via smartphone (ESP32)
- [ ] **Bluetooth Remote:** Wireless controller interface
- [ ] **Custom Gaits:** Implement different walking patterns
- [ ] **Learning AI:** Reinforcement learning for gait optimization
- [ ] **Camera Integration:** Computer vision for navigation
- [ ] **Voice Control:** Use microphone for voice commands

---

## 📄 License & Credits

**Project Type:** Educational Robotics
**Difficulty Level:** Intermediate
**Time to Build:** 20-30 hours (design + print + assembly)
**Cost Estimate:** $50-100 USD

---

## ✉️ Support & Questions

For questions or improvements to this project:
- Check the troubleshooting section
- Review servo motor datasheet
- Test components individually
- Consult robotics forums and communities

---

**🎓 Learning Outcomes:**

By completing this project, you'll master:
- ✅ Microcontroller programming (Arduino & ESP32)
- ✅ Servo motor control and PWM signals
- ✅ 3D modeling and printing workflow
- ✅ Electronics wiring and breadboard prototyping
- ✅ Robotic kinematics and gait design
- ✅ Problem-solving and debugging

---

**Happy Building! 🤖🐾**

*Last Updated: August 2026*
*Version: 2.0 - Complete Guide*

---

### 📊 Quick Reference Card

```
╔════════════════════════════════════════════════════════════╗
║           QUADRUPED ROBOT QUICK REFERENCE                 ║
╠════════════════════════════════════════════════════════════╣
║                                                            ║
║  🔌 CONNECTIONS:                                          ║
║     Servo 1 (FR) → Pin 3/GPIO18                           ║
║     Servo 2 (FL) → Pin 5/GPIO19                           ║
║     Servo 3 (BR) → Pin 6/GPIO21                           ║
║     Servo 4 (BL) → Pin 9/GPIO22                           ║
║                                                            ║
║  ⚡ POWER:                                                 ║
║     Supply: 5V / 2A minimum                               ║
║     GND: Common to all devices                            ║
║                                                            ║
║  🎯 MOTION RANGE:                                          ║
║     Servo: 0-180 degrees                                  ║
║     Standing: 90 degrees                                  ║
║     Step: ±30 degrees from neutral                        ║
║                                                            ║
║  ⏱️  TIMING:                                                ║
║     Step Delay: 300ms                                     ║
║     Push Delay: 400ms                                     ║
║     Cycle Time: ~1.2 seconds                              ║
║                                                            ║
╚════════════════════════════════════════════════════════════╝
```

---
