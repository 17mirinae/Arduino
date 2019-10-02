int led = 9;
int sensorPin = A0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = 0;

  sensorValue = analogRead(sensorPin);
  analogWrite(led, sensorValue);
  Serial.println(sensorValue);

  delay(10);
}
