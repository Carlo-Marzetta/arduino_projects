int buzzer = 8;
int heartbeat = 0;
double alpha = 0.75;
int period = 100;
double change = 0.0;
double minval = 0.0;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  tone(buzzer, 500);

}

  void loop() {
    static double oldValue = 0;
  static double oldChange = 0;
  int rawValue = analogRead (heartbeat);
  double value = alpha * oldValue + (1 - alpha) * rawValue;
  Serial.print (rawValue);
  Serial.print (",");
  Serial.println (value);
  oldValue = value;
  if(value > 1000)
  {
    analogWrite(buzzer, 255);
  }
  else
  {
    analogWrite(buzzer, 0);  
  }
  delay(100);
}
