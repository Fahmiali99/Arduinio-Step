int buttonState = 0;
void setup() {
  // put your setup code here, to run once:

  //  LED Blue;
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  digitalWrite(13, HIGH);

  //  LED Green;
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  digitalWrite(8, HIGH);

  //  LED Red;
  pinMode(4, OUTPUT);
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);

  digitalWrite(4, HIGH);

}


void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(12);

  if (buttonState == HIGH) {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }


  buttonState = digitalRead(7);

  if (buttonState == HIGH) {
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }

  buttonState = digitalRead(3);

  if (buttonState == HIGH) {
    digitalWrite(2, HIGH);
    digitalWrite(1, HIGH);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(1, LOW);
  }

}
