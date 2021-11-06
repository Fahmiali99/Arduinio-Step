#include <BlynkSimpleStream.h>
#include "DHT.h"
#include <Blynk.h>

DHT dht1(13, DHT11);
DHT dht2(12, DHT11);
DHT dht3(11, DHT11);

char auth[] = "M0Vb8eDroXs8zLOsVNAD1e4mHhPzsc81";
BlynkTimer timer;
WidgetLED led1(V7);
WidgetLED led2(V6);
WidgetLED led3(V5);

void sendToBlynk() {
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  float hic1 = dht1.computeHeatIndex(t1, h1, false);
  int hic11 = hic1;

  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  float hic2 = dht2.computeHeatIndex(t2, h2, false);
  int hic21 = hic2;

  float h3 = dht3.readHumidity();
  float t3 = dht3.readTemperature();
  float hic3 = dht3.computeHeatIndex(t3, h3, false);
  int hic31 = hic3;

  float x = (hic1 + hic2 + hic3) / 3;

  if (x > 0 && x < 41) {
    led1.on();
    led2.off();
    led3.off();
  }
  else if (x >= 41 && x < 54) {
    led1.off();
    led2.on();
    led3.off();
  }
  else if (x >= 54) {
    led1.off();
    led2.off();
    led3.on();
  }
  else {
    led1.off();
    led2.off();
    led3.off();
  }
  Blynk.virtualWrite(V13, hic11);
  Blynk.virtualWrite(V12, hic21);
  Blynk.virtualWrite(V11, hic31);
}

void setup() {
  //  led Blue
  pinMode(7, OUTPUT);
  //  led Green
  pinMode(6, OUTPUT);
  //  led Red
  pinMode(5, OUTPUT);

  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  dht1.begin();
  dht2.begin();
  dht3.begin();

  timer.setInterval(1000L, sendToBlynk);
}

void loop() {
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  float hic1 = dht1.computeHeatIndex(t1, h1, false);

  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  float hic2 = dht2.computeHeatIndex(t2, h2, false);

  float h3 = dht3.readHumidity();
  float t3 = dht3.readTemperature();
  float hic3 = dht3.computeHeatIndex(t3, h3, false);

  float hasil = (hic1 + hic2 + hic3) / 3;

  if (hasil > 0 && hasil < 41) {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    delay(1000);
  }
  else if (hasil >= 41 && hasil < 54) {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    delay(1000);
  }
  else if (hasil >= 54) {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);

    delay(1000);
  }
  else {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);

    delay(1000);
  }

  Blynk.run();
  timer.run();
}
