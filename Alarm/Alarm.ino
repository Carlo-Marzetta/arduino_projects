#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

int counter=0;
String msg = "DIS NIBBA EATIN BEANS AT 3 Am";
String output = "";
bool poop = true;
void setup() {
// put your setup code here, to run once:
Timer1.initialize();
MFS.initialize(&Timer1); // initialize multi-function shield library
}


char* string2char(String cmd)
{
  Serial.print(cmd);
  if(cmd.length()!=0)
  {
    char *p = const_cast<char*>(cmd.c_str());
    return p;
  }
}


byte ended = false;
//Page 6 of 30Hackatronics – Using an Arduino Multi-function Shield cohesivecomputing.co.uk
void loop() {

if(poop)
{
 String lol = msg;
msg = "";
for(int i = 0; i < 4; i++)
{
  msg += " ";
}
msg += lol;
poop = false;
}
Serial.println(msg);
if(counter < msg.length())
{
  counter ++;
}
else
{
  counter = 0;
}

output = "";

output += msg.charAt(counter);
output += msg.charAt(counter + 1);
output += msg.charAt(counter + 2);
output += msg.charAt(counter + 3);

MFS.write(string2char(output));

delay(250);
}
