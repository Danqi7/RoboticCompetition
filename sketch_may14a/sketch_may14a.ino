void setup() {
  // put your setup code here, to run once:
//directoin digital: A,B
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

  //speed analog for R,L wheels
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      analogWrite(3, 100);
      analogWrite(5, 100);
}
