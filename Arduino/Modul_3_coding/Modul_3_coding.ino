#include "DHT.h"
DHT dht(9, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);

  digitalWrite(10, HIGH);

  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  float t = dht.readTemperature();

  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);

  //  index 0 biru
  if (t >= 0 && t < 41) {
    digitalWrite(7, HIGH);
    digitalWrite(2, HIGH);
    Serial.println(" Suhu !!! Dingin !!!");

    delay(1000);

    digitalWrite(7, LOW);
    digitalWrite(2, LOW);
    Serial.println(" Suhu !!! Dingin !!!");
    //  index 41 green
  } else if (t >= 41 && t < 54) {
    digitalWrite(6, HIGH);
    digitalWrite(2, HIGH);
    Serial.println(" Suhu !!! Normal !!!");

    delay(1000);

    digitalWrite(6, LOW);
    digitalWrite(2, LOW);
    //  index 54 merah
  } else {
    digitalWrite(5, HIGH);
    digitalWrite(2, HIGH);
    Serial.println(" Suhu !!! Hot !!!");

    delay(1000);

    digitalWrite(5, LOW);
    digitalWrite(2, LOW);
  }
}
