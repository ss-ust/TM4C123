#include <Servo.h>
Servo sg90; 

int pos = 90; 

void setup() {
  sg90.attach(13);
  Serial.begin(9600);
  sg90.write(pos); // Initialize servo to the starting position
}

void loop() {
  if (Serial.available()) {
    char read = Serial.read();

    if (read == 'l') {
      pos = 180; // Move servo to the leftmost position
    } else if (read == 'r') {
      pos = 0; // Move servo to the middle position
    }
    else if (read == 'm') pos = 90;
  }
  sg90.write(pos); // Write the new position to the servo
}
