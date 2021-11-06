
#define BLYNK_PRINT SwSerial
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
#include "DHT.h"
#define DHTPIN 12
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
#include <BlynkSimpleStream.h>
#include <Servo.h>

char auth[] = "_qdekLlDcgXgfWWd8zGa_aVVUM3zzBIb";

Servo servo;
BlynkTimer timer;
bool autos = false;

BLYNK_WRITE(V2)
{
  //  servo.write(param.asInt());

  if (param.asInt() == 0) {
    autos = false;
  } else if (param.asInt() == 1) {
    autos = true;
  }
}

BLYNK_WRITE(V3)
{
  if (autos = true) {
    servo.write(param.asInt());
  }
}

void myTimerEvent() {

  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(h) || isnan(t)) {
    //    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hic = dht.computeHeatIndex(t, h);


  SwSerial.println(F("HIC: "));
  SwSerial.println(hic);
  SwSerial.println("  ");

  Blynk.virtualWrite(V5, hic);
  if (hic < 41.0 && autos == false) {
    servo.write(180);
    SwSerial.println("Low Pressure !");

  } else if (hic > 45.0 && autos == false) {
    servo.write(0);
    SwSerial.println("Heigh Pressure !");
  }
  else if (autos == false) {
    servo.write(90);
    SwSerial.println("Normal");
  }

//  
//int ldr = A0;
int nilai = analogRead(A0);
  if (nilai < 100) {
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(500);
    
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    delay(500);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);

  }

}

void setup()
{
  // Debug console
  SwSerial.begin(9600);

  Serial.begin(9600);
  Blynk.begin(Serial, auth);

  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

  servo.attach(9);
  timer.setInterval(1000L, myTimerEvent);
  dht.begin();
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
