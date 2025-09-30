#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lineS;
Zumo32U4ProximitySensors proxS;
Zumo32U4LCD lcd;
Zumo32U4Motors motors;

void setup() {
  lineS.initFiveSensors();
  proxS.initFrontSensor();

calibrateLineSensors();
}

void loop() {
  // put your main code here, to run repeatedly:


  uint16_t lineSensorVal[5] = {0, 0, 0, 0, 0};
  lineS.readCalibrated(lineSensorVal);
  if(lineSensorVal[1] < 200)
  {
    turnLeft();
  }
  else if(lineSensorVal[3] > 800)
  {
    turnRight();
  }
  else
  {
    if(proxS.countsFrontWithLeftLeds() < 5)
    {
      goStraight();
    }
  }

  
}


void goStraight()
{
  motors.setLeftSpeed(400);
  motors.setRightSpeed(400);
}

void turnLeft()
{
  motors.setLeftSpeed(300);
  motors.setRightSpeed(0);
}

void turnRight()
{
  motors.setLeftSpeed(0);
  motors.setRightSpeed(300);
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
