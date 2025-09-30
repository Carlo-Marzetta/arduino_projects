
int sensorPin = 5;
int value = 0;
int redpin = 10; 
int greenpin = 11;
int bluepin = 12;
int x = 0;
int y = 0;
int speakerPin = 8;

void setup() 
{
  pinMode (redpin, OUTPUT);
  pinMode (greenpin, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  pinMode (speakerPin, OUTPUT);
}

void loop() 
{
  value = analogRead(0);
  x = value;
  Serial.print("X:");
  Serial.print(value, DEC);
  value = analogRead(1);
  y = value;
  Serial.print(" | Y:");
  Serial.print(value, DEC);
  value = digitalRead(7);
  Serial.print(" | Z: ");
  Serial.println(value, DEC);


  analogWrite(redpin, x/4);
  analogWrite(greenpin, y/4);
  analogWrite(bluepin, (y + x)/12);

  /*if(x > y)
  {
    if(x > 500)
    {
      analogWrite(redpin, 255);  
      analogWrite(greenpin, 0);
      analogWrite(bluepin, 0);  
    }
    else
    {
      analogWrite(bluepin, 255);  
      analogWrite(redpin, 0);  
      analogWrite(greenpin, 0);
    }
  }
  else
  {
    if(y > 500)
    {
      analogWrite(greenpin, 255);  
      analogWrite(redpin, 0);
      analogWrite(bluepin, 0);  
    }
        else
    {
      analogWrite(bluepin, 255);  
      analogWrite(redpin, 0);  
      analogWrite(greenpin, 0);
    }
  }*/
}
