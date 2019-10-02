#include <Dht11.h>
#define DHT11PIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT11 Test Program");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(Dht11::VERSION);
  Serial.println();
}

void loop() {
  static Dht11 sensor(DHT11PIN);

  switch(sensor.read()) {
    case Dht11::OK:
    Serial.print("Humidity (%): ");
    Serial.println(sensor.getHumidity());

    Serial.print("Temperature (C): ");
    Serial.println(sensor.getTemperature());
    break;
    
    case Dht11::ERROR_CHECKSUM:
    Serial.println("Checksum error");
    break;

    case Dht11::ERROR_TIMEOUT:
    Serial.println("Timeout error");
    break;

    default:
    Serial.println("Unknown error");
    break;
  }

  delay(2000);
}
