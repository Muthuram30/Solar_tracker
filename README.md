# Solar Tracker

An intelligent **dual-axis solar tracking system** that automatically aligns a solar panel toward the sun using light sensors and servo-based motion control. The project is designed as a compact, low-cost, and practical prototype for improving solar panel exposure and efficiency.

## Project Overview

Traditional fixed solar panels cannot continuously face the sun throughout the day. This project solves that problem by using a **dual-axis tracking mechanism** that adjusts both the horizontal and vertical angle of the panel based on sunlight intensity.

The system uses:

* **Four LDR sensors** to detect sunlight direction
* **Two servo motors** for pan and tilt movement
* **ESP32 microcontroller** for real-time control
* A **custom mounting frame** to hold the panel securely

## Features

* Dual-axis solar tracking
* Automatic sun alignment
* LDR-based light direction sensing
* Servo-controlled pan and tilt motion
* ESP32-based embedded control
* Compact and educational hardware prototype
* Suitable for renewable energy demonstrations and college projects

## Working Principle

The solar panel is mounted on a movable frame. Four LDRs are arranged in a 2×2 layout behind a small divider. When sunlight falls unevenly on the sensors, the ESP32 compares the light values and determines the direction in which the panel should move.

* If the left sensors receive more light, the panel shifts left.
* If the right sensors receive more light, the panel shifts right.
* If the top sensors receive more light, the panel tilts upward.
* If the bottom sensors receive more light, the panel tilts downward.

This closed-loop feedback helps the panel stay aligned with the brightest light source.

## Components Used

* ESP32 development board
* 2 × servo motors
* 4 × LDR sensors
* Solar panel
* Resistors
* Connecting wires
* Mounting frame
* Base support
* Power supply
* Electronics enclosure

## Project Images

### Hardware Prototype

![Solar Tracker Prototype 1](Images/img_1)

![Solar Tracker Prototype 2](Images/img_2)

### AI Generated Concept

![Solar Tracker AI Concept](Images/Solar_tracker_ai)

## Repository Structure

```bash
Solar_tracker/
├── Images/
│   ├── img_1
│   ├── img_2
│   └── Solar_tracker_ai
├── README.md
└── source code files
```

## Applications

* Solar energy optimization
* College mini project
* Renewable energy demonstration
* Embedded systems learning
* Smart automation prototype

## Future Improvements

* Add IoT monitoring
* Store tracking data for analysis
* Use stepper motors for larger panels
* Add battery charging management
* Integrate weather-based tracking logic

## Author

**Muthuram30**

GitHub: https://github.com/Muthuram30/Solar_tracker.git
