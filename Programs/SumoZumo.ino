#include<Zumo32U4.h>
#include <Wire.h>


Zumo32U4ButtonA bA;
Zumo32U4ButtonB bB;
Zumo32U4ButtonC bC;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;

Zumo32U4LineSensors lineS;
Zumo32U4ProximitySensors proxS;


void setup() {
  // put your setup code here, to run once:
  ledRed(1);
  ledYellow(1);
  ledGreen(1);
  lcd.print("JESUS");
  proxS.initThreeSensors();
  lineS.initThreeSensors();

  calibrateLineSensors();

  //motors.setLeftSpeed(200);
 // motors.setRightSpeed(200);
  
}

void loop() 
{
      
  
  uint16_t lineSensorVal[3] = {0, 0, 0};
  lineS.readCalibrated(lineSensorVal);
  if(lineSensorVal[1] < 200)
  {
    goBack();
  }
  else if(lineSensorVal[0] < 200)
  {
      goRight();
  }
  else if(lineSensorVal[2] < 200)
  {
    goLeft();
  }
  else
  {
    
  }


  
  proxS.read();
  if(proxS.countsLeftWithLeftLeds() >= 2)
  {
    turnL();
  }
  else if(proxS.countsRightWithRightLeds() >= 2)
  {
    turnR();  
  }

  uint16_t dif = proxS.countsFrontWithRightLeds() - proxS.countsFrontWithLeftLeds();
  lcd.clear();
  lcd.print(dif);
  if(dif > 0)
  {
    gL(dif);
  }
  else if(dif < 0)
  {
    gR(dif);  
  }


  
}

void border()
{
  goBack();
  goLeft();
}
void goLeft()
{
    motors.setLeftSpeed(100);
  motors.setRightSpeed(300);
}

void goRight()
{
    motors.setLeftSpeed(300);
  motors.setRightSpeed(100);
}

void gR(uint16_t angle)
{
  motors.setRightSpeed(400 - (angle  * 200));
  motors.setLeftSpeed(400);
}

void gL(uint16_t angle)
{
  motors.setLeftSpeed(400 + (angle  * 200));
  motors.setRightSpeed(400);
}

void goStraight()
{
    motors.setLeftSpeed(400);
  motors.setRightSpeed(400);
}

void goStop()
{
    motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
}

void goBack()
{
  motors.setLeftSpeed(0);
  motors.setRightSpeed(-400);
  delay(200);
  goStop();
}

void turnL()
{
  motors.setLeftSpeed(-400);
  motors.setRightSpeed(400);
}

void turnR()
{
  motors.setLeftSpeed(400);
  motors.setRightSpeed(-400);
}






void calibrateLineSensors()
{
// To indicate we are in calibration mode, turn on the yellow LED
// and print "Line cal" on the LCD.
  ledYellow(1);
  lcd.clear();
  lcd.print(F("Line cal"));
  for (uint16_t i = 0; i < 400; i++)
  {
  lcd.gotoXY(0, 1);
  lcd.print(i);
  lineS.calibrate();
  }
  ledYellow(0);
  lcd.clear();
}



void uselsessness()
{
  if(bA.isPressed())
  {
    for(int i = 0; i < 350; i++)
    {
    motors.setRightSpeed(i);
    }
    motors.setRightSpeed(0);
  }
    if(bC.isPressed())
  {
    for(int i = 0; i < 350; i++)
    {
    motors.setLeftSpeed(i);
    }
     motors.setLeftSpeed(0);
  }

    if(bB.isPressed())
  {
    for(int i = 0; i < 200; i++)
    {
    motors.setRightSpeed(i);
    motors.setLeftSpeed(i);
    }
     motors.setRightSpeed(0);
      motors.setLeftSpeed(0);
  }
  }



  void notThatGood()
  {
   uint16_t lineSensorVal[3] = {0, 0, 0};
  lineS.readCalibrated(lineSensorVal);
    for(uint16_t i : lineSensorVal)
  {
    if(i > 800)
    {
      motors.setLeftSpeed(0);
      motors.setRightSpeed(0);
      lcd.print("OOPSIE");
    }
    else
    {
      lcd.print("GOGOGO");
      motors.setLeftSpeed(200);
      motors.setRightSpeed(200);
     }
  }
  
}  
