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
#define speedR 78
#define middle 80
#define fast 170
#define slow 50

unsigned long prev = 0; //the start time when the car begins to spin

class RoboticCar
{

  public:
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


RoboticCar ourCar;


void loop() {
  // put your main code here, to run repeatedly

  //read input
  //    ourCar.sensorA1 = analogRead(A0);
  //    ourCar.sensorA2 = analogRead(A1);
  //    ourCar.sensorB1 = analogRead(A2);
  //    ourCar.sensorB2 = analogRead(A3);

  ourCar.movePositive();
  Serial.println(ourCar.direct);



  ourCar.lightA = analogRead(A4);
  ourCar.lightB = analogRead(A5);
  Serial.println("=========");
  Serial.println(ourCar.lightA);
  Serial.println(ourCar.lightB);

  //assign input to local vars
  //    int sensorA1 = ourCar.sensorA1;
  //    int sensorA2 = ourCar.sensorA2;
  //    int sensorB1 = ourCar.sensorB1;
  //    int sensorB2 = ourCar.sensorB2;
  //    int lightA = ourCar.lightA;
  //    int lightB = ourCar.lightB;

  //    unsigned long current = millis();//get current time
  //
  //    //while we are running within the boundary
  //    while (lightA < thLight && lightB < thLight )
  //    {
  //      ourCar.avoidObstacle();
  //      //target detected
  //      if (sensorA1 >= thSensor || sensorA2 >= thSensor || sensorB1 >= thSensor || sensorB2 >= thSensor)
  //      {
  //        ourCar.lost = 0;
  //        if (sensorA1 >= thSensor || sensorA2 >= thSensor)
  //        {
  //            ourCar.direct = 'A';
  //            ourCar.movePositive();
  //        }
  //        else if (sensorB1 >= thSensor || sensorB2 >= thSensor)
  //        {
  //            ourCar.direct = 'B';
  //            ourCar.movePositive();
  //        }
  //
  //      }
  //      //if target is NOT detected
  //      else if (sensorA1 < thSensor && sensor A2 < thSensor && sensorB1 < thSensor && sensorB2 < thSensor)
  //      {
  //          if (ourCar.lost == 0)
  //          {
  //              prev = current;
  //              ourCar.lost = 1;
  //          }
  //          if (current - prev < interval)
  //          {
  //            ourCar.spin();
  //          }
  //          else //spin more than 5 sec
  //          {
  //            ourCar.lost = 0;
  //            movePositive();
  //          }
  //      }
  //
  //    }

  int lightA = ourCar.lightA;
  int lightB = ourCar.lightB;

  //running into the boundary
  while (lightA <= thLight && lightB > thLight)
  {
    //         Serial.print("Mode1");
    ourCar.lightA = analogRead(A4);
    ourCar.lightB = analogRead(A5);
    lightA = ourCar.lightA;
    lightB = ourCar.lightB;
//    ourCar.moveOpposite();
    ourCar.clockwise();
    delay(1000);
  }
  while (lightA <= thLight && lightB <= thLight)
  {
    //         Serial.print("REVERSE");
    ourCar.lightA = analogRead(A4);
    ourCar.lightB = analogRead(A5);

    lightA = ourCar.lightA;
    lightB = ourCar.lightB;
    ourCar.moveOpposite();
    delay(1000);
  }

  while (lightA > thLight && lightB <= thLight)
  {
    ourCar.lightA = analogRead(A4);
    ourCar.lightB = analogRead(A5);
    lightA = ourCar.lightA;
    lightB = ourCar.lightB;
    //ourCar.moveOpposite();
//    delay(1000);
    ourCar.counterclockwise();
  }

}

