#define C 262 // 도
#define D 294 // 레 
#define E 330 // 미 
#define F 349 // 파 
#define G 392 // 솔 
#define A 440 // 라 
#define B 494 // 시

//솔솔라라솔솔미
//솔솔미미레
//솔솔라라솔솔미
//솔미레미도

int buzzer = 6;
int note[25] = {G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C};

void setup() { 
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for (int i = 0; i < 7; i++) {
    tone(buzzer, note[i], 300);
    delay(300);
  }
  delay(200);
  for (int i = 7; i < 12; i++) {
    tone(buzzer, note[i], 300);
    delay(300);
  }
  delay(500);
  for (int i = 12; i < 19; i++) {
    tone(buzzer, note[i], 300);
    delay(300);
  }
  delay(200);
  for (int i = 19; i < 25; i++) {
    tone(buzzer, note[i], 300);
    delay(300);
  }
  delay(500);
}
