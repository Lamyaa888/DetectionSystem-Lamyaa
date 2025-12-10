# Detection System (Smoke/Gas)
### Name: Lamyaa Ahmed Guled  
### Course: CENG-464 — Design Patterns with C++  
### Subsystem: Detection System (Smoke/Gas)  
### Design Pattern Used: **Observer Pattern**

---

## 📌 1. Overview
The Detection System is responsible for **monitoring smoke/gas levels** inside the smart home.  
When the detector identifies abnormal levels, it **notifies all observers** (Alarm, Light, Logger) to react immediately.

This subsystem is designed to be **modular**, **extendable**, and **integration-ready** with the full Smart Home System.

---

## 📌 2. Observer Pattern — How It Works

The **Detector** acts as the **Subject**.  
It maintains a list of observers:

- `AlarmObserver`
- `LightObserver`
- `LogObserver`

Whenever danger is detected:

1. The detector calls `notify("Danger!")`
2. Every observer executes its own `update(msg)` independently:
   - **Alarm** → activates the siren  
   - **Light** → starts blinking  
   - **Logger** → records the event  

This design provides **loose coupling** and makes the system easy to integrate with other subsystems.

---

## 📌 3. Low-Level Requirements (LLRs) and Implementation

### ✅ **LLR-DS1 — Continuous monitoring**
The detector monitors smoke/gas and triggers the danger state when abnormal levels occur.

**Implemented as:**  
```cpp
detector.setDanger(true);
```

---

### ✅ **LLR-DS2 — User acknowledgement**
If danger is detected, system waits for user interaction (simulated in this version).

---

### ✅ **LLR-DS3 — Lights should blink if user does NOT acknowledge**
Simulated through:
```
[LIGHT] Blinking all lights... (simulation)
[LIGHT] Blinking interval = 1 second (simulation)
```

---

### ✅ **LLR-DS4 — Notify fire station if blinking is ignored**
Simulated through:
```
[System] Calling Fire Station... (simulation)
```

---

### ✅ **LLR-DS5 — Every step must be logged**
Logger records:
```
[LOGGER] Log entry: Danger!
```

---

## 📌 4. Class Responsibilities

### **Detector**
- Stores observer list  
- Detects danger  
- Broadcasts messages to attached observers  
- Simulates extended detection sequence (DS3, DS4)

### **AlarmObserver**
- Prints alarm activation message

### **LightObserver**
- Prints blinking behavior  
- Used for DS3 simulation

### **LogObserver**
- Logs every detection event

---

## 📌 5. How to Run This Subsystem
No external libraries required.

Compile with:
```sh
g++ main.cpp Alarm.h Light.h LogObserver.h Detector.h Observer.h -o DetectionSystem
```

Run:
```sh
./DetectionSystem
```

---

## 📌 6. Sample Output (Screenshots)

### 🔹 Danger Detected
```
[System] Danger signal received...
[ALARM] Danger detected! Alarm is ON!
[LIGHT] Blinking... Danger detected!
[LOGGER] Log entry: Danger!
```

### 🔹 Extended Detection Sequence
```
--- Detection Sequence Simulation ---
[System] No user acknowledgement detected.
[LIGHT] Blinking all lights... (simulation)
[LIGHT] Blinking interval = 1 second (simulation)
[System] Still no acknowledgement received.
[System] Calling Fire Station... (simulation)
```

---

## 📌 7. Integration Readiness
This subsystem follows the Observer Pattern exactly as defined in the Phase 2 design report.

✔ **Observers are modular**  
✔ **Danger event broadcasting is working**  
✔ **Extended behaviors (DS3, DS4) included as simulation**  
✔ **Team integrator can attach additional observers without modifying the detector**

Your subsystem is fully ready for integration with:
- Logging System  
- Menu System  
- Mode System  
- State System  
- Security System (Camera)  

