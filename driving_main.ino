#include <TinyGPS++.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

//sensor pins
#define trig 3
#define echo 4

//motor pinout
int ForwardRight = 5; 
int ForwardLeft = 6;
int BackwardRight = 7;
int BackwardLeft = 8;

//our servo name
Servo servo;

//our gps object
TinyGPSPlus gps;

// Assign a Uniquej ID to the HMC5883 Compass Sensor
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

unsigned long timer,pre=0;
double Lat=0, Lon=0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(ForwardRight, OUTPUT);
  pinMode(ForwardLeft, OUTPUT);
  pinMode(BackwardRight, OUTPUT);
  pinMode(BackwardLeft, OUTPUT);

  servo.attach(10); //our servo pin

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  
  // stop at begining
  Stand();

  Serial.begin(9600);  Serial1.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

Blisten();
}
