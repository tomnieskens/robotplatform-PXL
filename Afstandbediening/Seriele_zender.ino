#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
int joyFB = A1 ; //joystick forward and backward
 int joyLR = A2 ; //joystick left and right
 int valueFB = 500; //variable value forward backward
 int valueLR = 500; //variable value left right
void setup()
{
  Serial.begin(115200);
  pinMode(joyFB,INPUT);
  pinMode(joyLR,INPUT);

  mySerial.begin(115200);
  
}

void loop()
{
valueFB = analogRead(joyFB);
valueLR = analogRead(joyLR);

Serial.println(1066);
mySerial.println(1066);
Serial.println (valueFB); // send valueFB to rx arduino
mySerial.println(valueFB);
delay(80);
Serial.println(1065);
mySerial.println(1065);
Serial.println (valueLR); // send valueLR to rx arduino
mySerial.println(valueLR);
delay(80);
Serial.println("AT+AB SPPConnect 00043e26120c");
delay(80);
}
