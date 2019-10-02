int led1 = 13;
int led2 = 12;
int led1_status = LOW;
int led2_status = LOW;

void setup() {
  Serial.begin(9600);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  char read_data;
  
  if(Serial.available()){
    read_data = Serial.read();
    if(read_data == '1' && led1_status==LOW){
      digitalWrite(led1, HIGH);
      led1_status = HIGH;
      Serial.println("LED1 ON");
    }
    else if(read_data == '1' && led1_status == HIGH){
      digitalWrite(led1, LOW);
      led1_status = LOW;
      Serial.println("LED1 OFF");
    }
    else if(read_data == '2' && led2_status==LOW){
      digitalWrite(led2, HIGH);
      led2_status = HIGH;
      Serial.println("LED2 ON");
    }
    else if(read_data == '2' && led2_status == HIGH){
      digitalWrite(led2, LOW);
      led2_status = LOW;
      Serial.println("LED2 OFF");
    }
  }
  
  delay(10);
}
