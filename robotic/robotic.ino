void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //set pins as output
  //10,11,12,13 front
  //0,1,2,3 rear

  //pindMode();
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
}
#define threshold 600

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
 
  if (sensorValue > threshold) //thre is a cup in front
  {
    //digitalWrite(5, LOW);
    //digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(0, LOW);
  }
  else
  {
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(0, HIGH);
  }
}
