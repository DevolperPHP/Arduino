const int pingPin = 12;   

int inPin = 11;    

int safeZone = 95;

int tonepin=10;


int redPin= A7;

int purplePin = A5;

int bluePin = A3;




#include <Servo.h>

Servo  servo1;

Servo servo2;

Servo servo3;

Servo servo4;

Servo  servo5;

Servo servo6;

Servo servo7;

Servo servo8;



void setup() {  

  Serial.begin(9600);

  pinMode(redPin, OUTPUT);

  pinMode(purplePin, OUTPUT);

  pinMode(bluePin, OUTPUT);


servo1.attach(2);

  servo2.attach(3);

  servo3.attach(4);

  servo4.attach(5);

  servo5.attach(6);

  servo6.attach(7);

  servo7.attach(8);

  servo8.attach(9);

 


}

void loop() {

  sit();

  delay (1000);

  stand ();

  delay (1000);

   walk ();

   walk ();

   walk ();

   walk ();

   walk ();

   walk ();

   walk ();

   walk ();

  delay (500);

  }

void stand (){


  servo1.write(90);

 servo2.write(90);

 servo3.write(90);

 servo4.write(70);




 


}




void sit (){


 servo1.write(0);

 servo2.write(180);

 servo3.write(180);

 servo4.write(0);


}




void walk (){

 


delay (300);

 servo1.write(90);

 servo2.write(90);

 servo3.write(140);

 servo4.write(40);

delay (300);

 servo3.write(90);

 servo4.write(70);

  servo1.write(140);

 servo2.write(50);

}


void left (){

 

delay (150);


  servo1.write(150);

 servo3.write(150);

 servo2.write(150);

 servo4.write(150);

delay (150);


  servo1.write(130);

 servo2.write(130);

 servo4.write(130);

 servo3.write(130);

} 
