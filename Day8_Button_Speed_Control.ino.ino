#include<Stepper.h>

const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution,8,10,9,11);

const int buttonPin = 2;

bool isForward = true;
int speedLevel = 1;
unsigned long buttonPressTime = 0;
bool buttonPressed = false;

void setup(){
  pinMode(buttonPin,INPUT_PULLUP);
  Serial.begin(9600);
  updateSpeed();
}

void loop(){
  bool currentState = digitalRead(buttonPin) == LOW;

  if(currentState && !buttonPressed){
    buttonPressed = true;
    buttonPressTime = millis();
  }

if(!currentState && buttonPressed){
  unsigned long pressDuration = millis() - buttonPressTime;
  buttonPressed = false;

  if(pressDuration < 2000){
    isForward = !isForward;
    Serial.println(isForward ? "正转！" : "反转！");
    myStepper.step(isForward ? stepsPerRevolution : -stepsPerRevolution);
  }
}

if (currentState && buttonPressed && (millis() - buttonPressTime) > 2000){
  speedLevel = (speedLevel % 3) + 1;
  updateSpeed();
  Serial.print("速度切换到挡位");
  Serial.println(speedLevel);
  buttonPressTime = millis();
  }
}

void updateSpeed(){
  if (speedLevel == 1) myStepper.setSpeed(5);
  else if (speedLevel == 2) myStepper.setSpeed(10);
  else myStepper.setSpeed(15);
}