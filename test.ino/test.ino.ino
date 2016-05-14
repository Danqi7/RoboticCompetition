void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //directoin digital: A,B
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

  //speed analog for R,L wheels
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

#define thSensor 100
#define thLight 86
#define interval 5000
#define speedL 80
#define speedR 80
#define middle 60
#define fast 170


unsigned long prev = 0; //the start time when the car begins to spin

class RoboticCar
{

  public:
    int lost = 0;
    //front sensors
    int sensorA1;
    int sensorA2;

    //rear sensors
    int sensorB1;
    int sensorB2;

    //LED sensors
    int lightA;
    int lightB;

    //bump
    //  bumpA1;
    //  bumpA2;
    //  bumpB1;
    //  bumpB2;

    int counter = 0;
    char direct = 'A';

    void moveA()
    {
      //      Serial.print("MoveA");
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      analogWrite(3, speedR);
      analogWrite(5, speedL);
    }

    void moveB()
    {
      //      Serial.print("MoveB");
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      analogWrite(3, speedL);
      analogWrite(5, speedR);
    }

    void ccwA()
    {
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      analogWrite(3, fast);
      analogWrite(5, middle);
    }
    void cwA()
    {
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      analogWrite(3, middle);
      analogWrite(5, fast);
    }
    void ccwB()
    {
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      analogWrite(3, middle);
      analogWrite(5, fast);
    }
    void cwB()
    {
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      analogWrite(3, fast);
      analogWrite(5, middle);
    }

    void spin()
    {
      Serial.println("SPIN========================!");
      
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      analogWrite(3, middle);
      analogWrite(5, middle);

    }

    void clockwise()
    {
      if (direct == 'A')
        cwA();
      else if (direct == 'B')
        cwB();
    }


    void counterclockwise()
    {
      if (direct == 'A')
        ccwA();
      else if (direct == 'B')
        ccwB();
    }

    void movePositive() //move in the current moving direction
    {
      if (direct == 'A')
        moveA();
      else if (direct == 'B')
        moveB();
    }

    void moveOpposite() //move in the current opposite direction
    {
      Serial.println("OPP!");
      if (direct == 'A')
      {
        moveB();
        direct = 'B';
      }
      else if (direct == 'B')
      {
        moveA();
        direct = 'A';
      }
    }

    //    void avoidObstacle() //check whether we have run into obs and avoid it if so
    //    {
    //      int prevA1 = bumpA1, prevA2 = bumpA2, prevB1 = bumpB1, prevB2 = bumpB2;
    //      if (bumpA1 == 1 || bumpA2 == 1 || bumpB1 == 1 || bumpB2 == 1):
    //      {
    //          MoveOpposite();
    //          delay(20);//backward for 20 ms
    //          if (prevA1 == 1 && prevA2 == 0)
    //          {
    //              clockwise();//
    //          }
    //          else if (bumpB2 == 1 && bumpB1 == 0)
    //          {
    //              clockwise();
    //          }
    //          else if (bumpA1 == 0 && bumpA2 == 1)
    //          {
    //             counterclockwise();  //optiamlly 90 degree
    //          }
    //          else if (bumpB2 == 0 && bumpB1 == 1)
    //          {
    //              counterclockwise();
    //          }
    //          delay(20);//turn for 20 ms
    //          MovePositive();
    //
    //      }
    //    }

};

int cnt = 0;
RoboticCar ourCar;


void loop() {
  // put your main code here, to run repeatedly


  //read input
  Serial.println("LOOP NUMBER:");
  cnt = cnt + 1;
  Serial.println(cnt);
  Serial.println("DIRECTION:");
  Serial.println(ourCar.direct);

  ourCar.sensorA1 = analogRead(A0);
  ourCar.sensorA2 = analogRead(A1);
  ourCar.sensorB1 = analogRead(A2);
  ourCar.sensorB2 = analogRead(A3);
  Serial.println("B2:");
  Serial.println(ourCar.sensorB2);


  ourCar.lightA = analogRead(A4);
  ourCar.lightB = analogRead(A5);

  int lightA = ourCar.lightA;
  int lightB = ourCar.lightB;

  ourCar.movePositive();
  //Serial.println(ourCar.direct);


  //
  //    Serial.println("=========");
  //    Serial.println(ourCar.lightA);
  //    Serial.println(ourCar.lightB);

  //assign input to local vars
  int sensorA1 = ourCar.sensorA1;
  int sensorA2 = ourCar.sensorA2;
  int sensorB1 = ourCar.sensorB1;
  int sensorB2 = ourCar.sensorB2;
  Serial.println("A1:");
  Serial.println(ourCar.sensorA1);
  Serial.println("A2:");
  Serial.println(ourCar.sensorA2);
  Serial.println("B1:");
  Serial.println(ourCar.sensorB1);
  //
  //
  //    Serial.println("Lost Value:");
  //    Serial.println(ourCar.lost);
  //    Serial.println("???????????????");
  //    Serial.println("prev Value:");
  //    Serial.println(prev);

  //    int lightA = ourCar.lightA;
  //    int lightB = ourCar.lightB;

  unsigned long current = millis();//get current time
//
//  if (cnt == 0)
//    ourCar.spin();
//
//  if (cnt > 5000)
//  {
//    ourCar.movePositive();
//    Serial.println("STOP~~~~~~~~~~~~~~~~~~~");
//  }
  

  


}

