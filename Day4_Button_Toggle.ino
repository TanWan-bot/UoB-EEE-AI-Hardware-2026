// Day4 项目：按钮控制LED闪烁
// TanWan 2026硬件备战
const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;
bool ledState = false;
int lastButtonState = HIGH;   // 记录上一次按钮状态
unsigned long lastDebounceTime = 0; 
void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {               
    ledState = !ledState;                 
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    delay(300);                          
  }
}
