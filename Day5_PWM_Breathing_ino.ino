// Day5 最终版：PWM呼吸灯 + 按钮随时控制（非阻塞版）

const int ledPin = 9;
const int buttonPin = 2;

bool isBreathing = false;        // false = 停止呼吸
unsigned long previousMillis = 0;
int brightness = 0;
bool increasing = true;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // 随时检查按钮（随时都能响应）
  if (digitalRead(buttonPin) == LOW) {
    isBreathing = !isBreathing;
    delay(250);                   // 防抖动
  }

  // 如果正在呼吸，就慢慢呼吸
  if (isBreathing) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 5) {
      previousMillis = currentMillis;

      analogWrite(ledPin, brightness);

      if (increasing) {
        brightness++;
        if (brightness >= 255) increasing = false;
      } else {
        brightness--;
        if (brightness <= 0) increasing = true;
      }
    }
  } else {
    analogWrite(ledPin, 0);   // 停止时直接彻底灭灯
  }
}