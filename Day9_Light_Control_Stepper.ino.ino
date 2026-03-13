#include <Stepper.h>

const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

const int buttonPin = 2;
const int lightPin = A0;

bool isForward = true;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  myStepper.setSpeed(15);   
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    isForward = !isForward;
    Serial.println(isForward ? "切换到正转方向" : "切换到反转方向");
    delay(300);
  }

  if (digitalRead(lightPin) == LOW) {   
    myStepper.step(isForward ? 8 : -8);   
    delay(8);
  } else {
    delay(8);
  }
}