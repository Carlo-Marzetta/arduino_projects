const int trigPin = 9;
const int echoPin = 10;
int redpin = 11;
int gpin = 12;
int bpin = 13;
// defines variables




long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(redpin, OUTPUT);
analogWrite(redpin, 255);
pinMode(gpin, OUTPUT);
pinMode(bpin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}



void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  

  if(distance > 20)
  {
    analogWrite(redpin, 0);
    
    analogWrite(gpin, 255);
    
    analogWrite(bpin, 0);
  }
  else
  {
    analogWrite(redpin, 255);
    
    analogWrite(gpin, 0);
    
    analogWrite(bpin, 0);
  }
  
}
