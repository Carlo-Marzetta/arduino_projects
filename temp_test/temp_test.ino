
float sensorVal = 0;
float temp = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello There");
  pinMode(10, OUTPUT);
}

void loop() {

  sensorVal = analogRead(A0);

  temp = (sensorVal * 0.8f) - 100;

  Serial.print(temp);
  Serial.println("° C");

  if(sensorVal > 30)
  {
    tone(10, 500, 100);
    delay(50 - temp);
    noTone(10);
  }
  delay((50 - temp) * 2);
  // put your main code here, to run repeatedly:

}
