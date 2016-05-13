void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

//
//  pinMode(13, OUTPUT);
//  pinMode(12, OUTPUT);
//  pinMode(11, OUTPUT);
//  pinMode(10, OUTPUT);
//
//  pinMode(3, OUTPUT);
//  pinMode(2, OUTPUT);
//  pinMode(5, OUTPUT);
//  pinMode(4, OUTPUT);

}

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

    }

    void moveB()
    {

    }

    void ccwA()
    {
      
    }
    void cwA()
    {
      
    }
    void ccwB()
    {
      
    }
    void cwB()
    {
      digitalWrite(pin1, High);
      delayMicroseconds(1000)
    }

    void stopMotion()
    {
      
    }

    void spin()
    {
      
    }

    void clockwise()
    {
      if direct == 'A':
        cwA();
      else if direct == 'B':
        cwB();   
    }


    void counterclockwise()
    {
      if direct == 'A':
        ccwA();
      else if direct == 'B':
        ccwB();   
    }

    void movePositive() //move in the current moving direction
    {
      if direct == 'A':
        moveA();
      else if direct == 'B':
        moveB();
    }

    void moveOpposite() //move in the current opposite direction
    {
      if direct == 'A':
      {
        moveB();
        direct = 'B';
      }
      else if direct == 'B':
      {
        moveA();
        direct = 'A';
      }
    }
    
//    void spinCheck() 
//    {
//      int complete = 0;
//      while (complete != 5000)
//      {
//        if (sensorA1 < thSensor && sensor A2 < thSensor && sensorB1 < thSensor && sensorB2 < thSensor)
//        {
//            spin();
//            delay(1);
//            complete++;
//        }
//        else
//        {
//          break;
//        }
//      }
//   
//      movePositive();
//
//    }

    void avoidObstacle() //check whether we have run into obs and avoid it if so
    {
      int prevA1 = bumpA1, prevA2 = bumpA2, prevB1 = bumpB1, prevB2 = bumpB2;
      if (bumpA1 == 1 || bumpA2 == 1 || bumpB1 == 1 || bumpB2 == 1):
      {
          MoveOpposite();
          delay(20);//backward for 20 ms
          if (prevA1 == 1 && prevA2 == 0):
          {
              clockwise();//
          }
          else if (bumpB2 == 1 && bumpB1 == 0):
          {
              clockwise();
          }
          else if (bumpA1 == 0 && bumpA2 == 1):
          {
             counterclockwise();  //optiamlly 90 degree
          }
          else if (bumpB2 == 0 && bumpB1 == 1):
          {
              counterclockwise();
          }
          delay(20);//turn for 20 ms
          MovePositive();

      }
    }

};

#define thSensor 20
#define thLight 20
#define interval 5000
unsigned long prev = 0; //the start time when the car begins to spin 


RoboticCar ourCar;




void loop() {
    // put your main code here, to run repeatedly
    
    unsigned long current = millis();//get current time

    //while we are running within the boundary
    while (lightA < thLight && lightB < thLight )
    {
      ourCar.avoidObstacle();
      //target detected
      if (sensorA1 >= thSensor || sensorA2 >= thSensor || sensorB1 >= thSensor || sensorB2 >= thSensor)
      {
        if (sensorA1 >= thSensor || sensorA2 >= thSensor) 
        {
            ourCar.direct = 'A';
            ourCar.movePositive();
        }
        else if (sensorB1 >= thSensor || sensorB2 >= thSensor)
        {
            ourCar.direct = 'B';
            ourCar.movePositive();
        }

      }
      //if target is NOT detected
      else if (sensorA1 < thSensor && sensor A2 < thSensor && sensorB1 < thSensor && sensorB2 < thSensor)
      {
          if (current - prev < interval)
          {
            ourCar.spin();    
          }
          else //spin more than 5 sec
          { 
            prev = current;
            movePositive();
          }
      }

    }

    //running into the boundary
    while (lightA >= thLight && lightB < thLight) {
        ourCar.counterclockwise()
    }
    while (light1 >= thLight && light2 >= thLight) {
        ourCar.moveOpposite()
    }
    while ((light1 < threshold && light2 >= threshold) {
        ourCar.clockwise()
    }

}

