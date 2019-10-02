int buzzerPin = 6;

int car_green = 8;
int car_yellow = 9;
int car_red = 10;

int pass_green = 11;
int pass_red = 12;

char read_data = '2';

void setup() {
  for (int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void beep(int delayms) {
  for (int i = 10; i < delayms; i = i + 10) {
    analogWrite(buzzerPin, 1);
    delay(delayms);
    analogWrite(buzzerPin, 0);
    delay(delayms);
  }
}

void carGreen() {
  digitalWrite(car_green, HIGH); // 자동차 초록불
  digitalWrite(car_yellow, LOW);
  digitalWrite(car_red, LOW);
  digitalWrite(pass_red, HIGH); // 보행자 빨간불
  digitalWrite(pass_green, LOW);
  delay(1000);
}

void carYellow() {
  digitalWrite(car_green, LOW);
  digitalWrite(car_yellow, HIGH); // 자동차 노란불
  digitalWrite(car_red, LOW);
  digitalWrite(pass_red, HIGH); // 보행자 빨간불
  digitalWrite(pass_green, LOW);
  delay(500);
}

void carRed() {
  digitalWrite(car_green, LOW);
  digitalWrite(car_yellow, LOW);
  digitalWrite(car_red, HIGH); // 자동차 빨간불
  digitalWrite(pass_red, LOW);
  digitalWrite(pass_green, HIGH); // 보행자 초록불
  beep(100);
  delay(1000);
}
void isSerial() {
  char save;

  if (Serial.available()) {
    read_data = Serial.read();
    save = read_data;

    if (read_data == '\0' || save == '1') {
      while (save == '1') {
        carGreen();
        read_data = Serial.read();
        if (read_data == '2')
          save = read_data;
      }
    }
  }
}

void loop() {
  isSerial();
  carGreen();
  isSerial();
  carYellow();
  isSerial();
  carRed();
}
