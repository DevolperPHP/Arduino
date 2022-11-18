#include<Servo.h>
Servo servo;
char open_trash = 'i';
char Incoming_value = 'i';
bool cloes = 0;
bool Open = 0;
int ang = 0;
void setup()
{
  Serial.begin(9600);
  servo.attach(3);
}
void loop()
{
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
    Serial.println(Incoming_value);
  } 
  if(Incoming_value == 'O' || Incoming_value == 'C' ){
      open_trash = Incoming_value;
  }
  if (open_trash != 'O'  || Open ){
      Open = 1;
      cloes = 0;
      if(ang < 160){
        ang++;
        servo.write(ang);
      }
      servo.write(ang);
    }
  if (open_trash != 'C' || cloes ){
      Open = 0;
      cloes = 1;
      if(ang > 5){
        ang--;
        servo.write(ang);
      }
    }
  }
