void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT); //buzzer
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(12, HIGH);
  delay(1000); 
  digitalWrite(1, HIGH);
  digitalWrite(0, HIGH);
  delay(2000);

  for(int i = 0; i < 13; i++){
    digitalWrite(i, LOW);
    for(int j = 0; j < 13; j++){
      digitalWrite(j, LOW);
    }
  }
}
