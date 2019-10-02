#define trigPin 12
#define echoPin 13

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long microsecondsToInches(long microseconds)
{
  return microseconds/74/2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds/29/2;
}

void loop() {
  long duration, inches, cm;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("inch, ");
  Serial.print(cm);
  Serial.println(" cm");

  delay(100);
}
