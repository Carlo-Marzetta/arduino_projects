#include <Wire.h>
#include <Zumo32U4.h>
#include <Zumo32U4Buzzer.h>

Zumo32U4LineSensors lineS;
Zumo32U4ProximitySensors proxS;
Zumo32U4LCD lcd;
Zumo32U4Motors motors;
Zumo32U4Buzzer buzz;

void setup() {
  lineS.initFiveSensors();
  proxS.initFrontSensor();

  calibrateLineSensors();
}

void loop() {
  // put your main code here, to run repeatedly:


  uint16_t lineSensorVal[5] = {0, 0, 0, 0, 0};
  lineS.readCalibrated(lineSensorVal);

  if(lineSensorVal[2] > 800)
  {
    lcd.clear();
    lcd.print("line found");
    if(lineSensorVal[0] > 800)
    {
      turnRight();
    }
    else if(lineSensorVal[4] > 800)
    {
      turnLeft();
    }
    else
    {
      goStraight();
    }
    goStraight();
  }
  else if(lineSensorVal[0] > 800)
  {
    turnRight();
  }
  else if(lineSensorVal[4] > 800)
  {
    turnLeft();  
  }
  else
  {
    motors.setLeftSpeed(30);  
    motors.setRightSpeed(30);  
  }
}


  


void goStraight()
{
  motors.setLeftSpeed(400);
  motors.setRightSpeed(400);
}

void turnLeft()
{
  motors.setLeftSpeed(400);
  motors.setRightSpeed(-400);
}

void turnRight()
{
  motors.setLeftSpeed(-400);
  motors.setRightSpeed(400);
}

void turn()
{
  motors.setLeftSpeed(400);
  motors.setRightSpeed(-50);
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
