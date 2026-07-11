#include <ESP32Servo.h>

Servo panServo;
Servo tiltServo;

// LDR pins
const int LDR_TL = 33;
const int LDR_TR = 32;
const int LDR_BL = 35;
const int LDR_BR = 34;

// Servo pins
const int PAN_PIN  = 18;
const int TILT_PIN = 19;

// Initial angles
int panAngle  = 90;
int tiltAngle = 90;

// Limits
const int PAN_MIN  = 0;
const int PAN_MAX  = 180;

const int TILT_MIN = 45;
const int TILT_MAX = 150;

// Sensitivity
const int threshold = 70;

void setup() {
  Serial.begin(115200);

  panServo.setPeriodHertz(50);
  tiltServo.setPeriodHertz(50);

  panServo.attach(PAN_PIN, 500, 2400);
  tiltServo.attach(TILT_PIN, 500, 2400);

  panServo.write(panAngle);
  tiltServo.write(tiltAngle);

  delay(1000);
}

void loop() {

  // Read LDRs
  int tl = analogRead(LDR_TL);
  int tr = analogRead(LDR_TR);
  int bl = analogRead(LDR_BL);
  int br = analogRead(LDR_BR);

  // Calculate averages
  int left   = (tl + bl) / 2;
  int right  = (tr + br) / 2;

  int top    = (tl + tr) / 2;
  int bottom = (bl + br) / 2;

  // Errors
  int panError  = left - right;
  int tiltError = top - bottom;

  // PAN
  if (panError > threshold)
    panAngle--;
  else if (panError < -threshold)
    panAngle++;

  // TILT
  if (tiltError > threshold)
    tiltAngle--;
  else if (tiltError < -threshold)
    tiltAngle++;

  // Limit angles
  panAngle  = constrain(panAngle, PAN_MIN, PAN_MAX);
  tiltAngle = constrain(tiltAngle, TILT_MIN, TILT_MAX);

  // Move servos
  panServo.write(panAngle);
  tiltServo.write(tiltAngle);

  // Debug
  Serial.printf(
      "TL:%4d TR:%4d BL:%4d BR:%4d | PanErr:%4d TiltErr:%4d | Pan:%3d Tilt:%3d\n",
      tl, tr, bl, br, panError, tiltError, panAngle, tiltAngle);

  delay(30);
}