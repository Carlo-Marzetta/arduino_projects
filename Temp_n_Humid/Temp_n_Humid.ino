int DHpin = 8;
int buzzer = 9;
byte dat [5];

void setup() {
  Serial.begin (9600);
  pinMode (DHpin, OUTPUT);
  pinMode (buzzer, OUTPUT);

}

void loop() {
  start_test();
  Serial.print(dat[1], DEC);
  Serial.println("% Humidity");
  Serial.print(dat[3], DEC);
  Serial.println("C Temperature");

}



byte read_data () {
  byte data;
  for (int i = 0; i < 8; i ++) {
    if (digitalRead (DHpin) == LOW) {
      while (digitalRead (DHpin) == LOW); // wait for 50us
      delayMicroseconds (30); // determine the duration of the high level
      if (digitalRead (DHpin) == HIGH)
        data |= (1 << (7 - i)); // high front and low in the post
      while (digitalRead (DHpin) == HIGH); // data '1 ', wait for the next
    }
  }
  return data;
}

void start_test () {
  digitalWrite (DHpin, LOW); // bus down, send start signal
  delay (30); // delay greater than 18ms, so DHT11 start signal can bedetected
  digitalWrite (DHpin, HIGH);
  delayMicroseconds (40); // Wait for DHT11 response
  pinMode (DHpin, INPUT);
  while (digitalRead (DHpin) == HIGH);
  delayMicroseconds (80); // DHT11 response, pulled the bus 80us
  if (digitalRead (DHpin) == LOW);
  delayMicroseconds (80); // DHT11 80us after the bus pulled to start

  for (int i = 0; i < 4; i ++) // receive temperature and humidity data,the parity bit is not considered
    dat[i] = read_data ();
  pinMode (DHpin, OUTPUT);
  digitalWrite (DHpin, HIGH); // send data once after releasing the bus,wait for the host to open the next Start signal
}
