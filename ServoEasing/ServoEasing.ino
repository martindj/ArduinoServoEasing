#include "easing.h"
#include <Servo.h>

Servo myservo;
int servoPin = 9;        // Forbind den orange ledning til denne pin
float iterations = 1000; // Iterationer pr animation

float pos = 0;
float servopos = 0;

void setup() {
  myservo.attach(servoPin);

  myservo.write(0);
  delay(1000);

}

void loop() {
  for (pos = 0; pos <= iterations; pos += 1) {
    
    servopos = 5+170*BounceEaseOut(pos/iterations);
    myservo.write(servopos);
    delay(2);
  }

  delay(1000);
  
  for (pos = iterations; pos >= 0; pos -= 1) {
    servopos = 5+170*BounceEaseIn(pos/iterations);
    myservo.write(servopos);
    delay(2);
  }
  
  delay(2000);
}
