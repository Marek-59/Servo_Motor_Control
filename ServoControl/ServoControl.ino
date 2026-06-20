
#include <ESP32PWM.h>
#include <ESP32Servo.h>

Servo myServo;

const int servoPin = 27;  //Servo Motor
const int potPin = 4;     //Potentiometer

//if value of voltage is needed
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  myServo.attach(servoPin);
  pinMode(potPin, INPUT);

  Serial.begin(115200);
  myServo.write(0);
}

void loop() {
  
  int potValue = analogRead(potPin);
  int potAngle = map(potValue, 700, 4095, 0, 180);  //max 180 degree

  Serial.println(potValue);
  Serial.println(potAngle);

  //as a voltage reference
  float voltage = floatMap(potValue, 0, 4095, 0, 5.0); 

  Serial.println(potValue);
  Serial.println(potAngle); 
  Serial.println(voltage); 
  Serial.println("");

  myServo.write(potAngle);
  delay(100);

}
