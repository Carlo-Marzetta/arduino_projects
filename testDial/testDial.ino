void setup() {
  pinMode(7, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(read(7));
}
