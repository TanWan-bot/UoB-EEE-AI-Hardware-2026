#include<Stepper.h>

const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution,8,10,9,11);

const int buttonPin = 2;

bool isForward = true;

int buttonState = 0;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup(){
  pinMode(buttonPin,INPUT_PULLUP),
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop(){
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH && (millis()-lastDebounceTime)>debounceDelay){

    lastDebounceTime = millis();

    isForward = !isForward;

    if (isForward){
      Serial.println("正转一圈");
      myStepper.step(stepsPerRevolution);
    } else {
      Serial.println("反转一圈");
      myStepper.step(-stepsPerRevolution);
    }
    delay(100);
  }

  lastButtonState = buttonState;
  
}