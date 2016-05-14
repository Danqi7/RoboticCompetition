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

int thSensorA1;
int thSensorA2;
int thSensorB1;
int thSensorB2;

int thLightA;
int thLightB;

#define interval 5000
#define speedL 87
#define speedR 80
#define middle 45
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
      //      //Serial.print("MoveA");
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      analogWrite(3, speedR);
      analogWrite(5, speedL);
    }

    void moveB()
    {
      //      //Serial.print("MoveB");
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      analogWrite(3, speedR);
      analogWrite(5, speedL);
    }

    void ccwA()
    {
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      analogWrite(3, fast);
      analogWrite(5, speedL);
    }
    void cwA()
    {
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      analogWrite(3, speedR);
      analogWrite(5, fast);
    }
    void ccwB()
    {
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      analogWrite(3, speedR);
      analogWrite(5, fast);
    }
    void cwB()
    {
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      analogWrite(3, fast);
      analogWrite(5, speedL);
    }

    void spin()
    {
      //Serial.println("SPIN========================!");
      
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      analogWrite(3, middle);
      analogWrite(5, middle);

    }

    void Rspin()
    {
       //Serial.println("SPIN========================!");
      
      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
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
      //Serial.println("OPP!");
      if (direct == 'A')
      {
        direct = 'B';
        moveB();
      }
      else if (direct == 'B')
      {
        direct = 'A';
        moveA();
      }
    }

    void stopMotion()
    {
      analogWrite(3, 0);
      analogWrite(5, 0);
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

void reset()
{
    thLightA = analogRead(A4) + 15;
    thLightB = analogRead(A5) + 15;
    //Serial.println(thLightA);
    //Serial.println(thLightB);
    thSensorA1 = analogRead(A0) + 60;
    thSensorA2 = analogRead(A1) + 60;
    thSensorB1 = analogRead(A2) + 60;
    thSensorB2 = analogRead(A3) + 60; 
}

void readInput()
{
  ////Serial.println("!@#$%^&*thresholdA:");
  ////Serial.println(thLightA);
  ////Serial.println("!@#$%^&*thresholdB:");
  ////Serial.println(thLightB);

  //read input
  ourCar.sensorA1 = analogRead(A0);
  ourCar.sensorA2 = analogRead(A1);
  ourCar.sensorB1 = analogRead(A2);
  ourCar.sensorB2 = analogRead(A3);
  ////Serial.println("B2:");
  ////Serial.println(ourCar.sensorB2);


  ourCar.lightA = analogRead(A4);
  ourCar.lightB = analogRead(A5);
 
}

unsigned long prev1 = 0;
unsigned long prev2 = 0;

void loop() {
  // put your main code here, to run repeatedly
  if (cnt == 0)
  {
      reset(); 
  }

  readInput();
  
  //Serial.println("LOOP NUMBER:");
  cnt = cnt + 1;
  //Serial.println(cnt);
  //Serial.println("DIRECTION:");
  //Serial.println(ourCar.direct);
  
  int lightA = ourCar.lightA;
  int lightB = ourCar.lightB;

  //Serial.println("LIGHT-A:");
  //Serial.println(lightA);
  //Serial.println("LIGHT-B:");
  //Serial.println(lightB);

   //ourCar.movePositive();

  //
  //    //Serial.println("=========");
  //    //Serial.println(ourCar.lightA);
  //    //Serial.println(ourCar.lightB);

  //assign input to local vars
  int sensorA1 = ourCar.sensorA1;
  int sensorA2 = ourCar.sensorA2;
  int sensorB1 = ourCar.sensorB1;
  int sensorB2 = ourCar.sensorB2;
  //Serial.println("A1:");
  //Serial.println(ourCar.sensorA1);
  //Serial.println("A2:");
  //Serial.println(ourCar.sensorA2);
  //Serial.println("B1:");
  //Serial.println(ourCar.sensorB1);
  //
  //
  //    //Serial.println("Lost Value:");
  //    //Serial.println(ourCar.lost);
  //    //Serial.println("???????????????");
  //    //Serial.println("prev Value:");
  //    //Serial.println(prev);

  //    int lightA = ourCar.lightA;
  //    int lightB = ourCar.lightB;

  unsigned long current = millis();//get current time

  //while we are running within the boundary
    if (lightA < thLightA && lightB < thLightB )
    {
      //ourCar.avoidObstacle();
      //target detected
      //Serial.println("running inside the boundary");
      if (sensorA1 >= thSensorA1 || sensorA2 >= thSensorA2 || sensorB1 >= thSensorB1 || sensorB2 >= thSensorB2)
      {
        //delay()
        //Serial.println("TARGET MODE");
        
        if (ourCar.lost == 1)
        {
          ourCar.Rspin();
          delay(240);
          ourCar.stopMotion();
          
          //delay(1000);
        }

//        do
//        {
//          readInput();
//          ourCar.movePositive();
//        }while (current - prev2 < 5000);
        
        delay(500);


        ourCar.lost = 0;
       
        if (sensorA1 >= thSensorA1 || sensorA2 >= thSensorA2)
        {
          ourCar.direct = 'A';
          ourCar.movePositive();

        }
        else if (sensorB1 >= thSensorB1 || sensorB2 >= thSensorB2)
        {
          ourCar.direct = 'B';
          ourCar.movePositive();
        }
           
      }
      //if target is NOT detected
      if (sensorA1 < thSensorA1 && sensorA2 < thSensorA2 && sensorB1 < thSensorB1 && sensorB2 < thSensorB2)
      {
        reset(); 
        ourCar.movePositive();
        
        //Serial.println("LOST MODE");
  
        if (ourCar.lost == 0)
        {
          prev = current;
          ourCar.lost = 1;
          //delay(1000);
        }

        //continuosly spin until we find the target
        do
        {
          ourCar.spin();
          readInput();
          current = millis();
          if (lightA >= thLightA || lightB >= thLightB)
                break;
          if (sensorA1 >= thSensorA1 || sensorA2 >= thSensorA2 || sensorB1 >= thSensorB1 || sensorB2 >= thSensorB2)
          {
              if (sensorA1 >= thSensorA1 || sensorA2 >= thSensorA2)
               {
                 ourCar.direct = 'A';
                 ourCar.movePositive();
               }
               else if (sensorB1 >= thSensorB1 || sensorB2 >= thSensorB2)
               {
                 ourCar.direct = 'B';
                 ourCar.movePositive();
               }
               
              break;
          }
        } while (current - prev < 2000 && ourCar.sensorA1 < thSensorA1 && ourCar.sensorA2 < thSensorA2 && ourCar.sensorB1 < thSensorB1 && ourCar.sensorB2 < thSensorB2);
        
        if (current - prev > 2000)//spin more than 5 sec
        {
          //Serial.println("MORE THAN 5 SEC~~~~~~~~~~~~");
          ourCar.lost = 0;
          prev1 = current;
          ourCar.movePositive();
          //delay(5000);
          //move 1 sec, breakout if we are out of boundary
          do
          {
            //Serial.println("WE ARE IN SEARCH MODE");
            current = millis();
           
            ourCar.movePositive();
            readInput();
            if (lightA >= thLightA || lightB >= thLightB)
                  break;
            if (sensorA1 >= thSensorA1 || sensorA2 >= thSensorA2 || sensorB1 >= thSensorB1 || sensorB2 >= thSensorB2)
            {
                if (sensorA1 >= thSensorA1 || sensorA2 >= thSensorA2)
                 {
                   ourCar.direct = 'A';
                   ourCar.movePositive();
                 }
                 if (sensorB1 >= thSensorB1 || sensorB2 >= thSensorB2)
                 {
                   ourCar.direct = 'B';
                   ourCar.movePositive();
                 }
                 
                break;
            }
                
            //Serial.println("INTERVAL");
            //Serial.println(current-prev1);
           }while (current-prev1 < 3000);
        }
      }
}

    //running into the boundary
    if (lightA > thLightA || lightB > thLightB)
    {
      //Serial.println("~~~~BOOM!~~~~~");
      ourCar.moveOpposite();
      delay(1000);
    }

}

