#include <Servo.h>
// servo and hc-05
Servo servo;
char open_trash = 'i';
char Incoming_value = 'i';
bool cloes = 0;
bool Open = 0;
int ang = 0;
// ultrasonic wtih buzzer
const int trigPin = 10;
const int echoPin = 9;
const int buzzer = 11;
long duration;
int distance;
int safetyDistance;
void setup() {
  Serial.begin(9600);
  servo.attach(3);
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  safetyDistance = distance;
  if (safetyDistance <= 5) {
    digitalWrite(buzzer, HIGH);

  } else {
    digitalWrite(buzzer, LOW);
  }
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
    Serial.println(Incoming_value);
  }
  if (Incoming_value == 'O' || Incoming_value == 'C') {
    open_trash = Incoming_value;
  }
  if (open_trash != 'O' || Open) {
    Open = 1;
    cloes = 0;
    if (ang < 160) {
      ang++;
      servo.write(ang);
    }
    servo.write(ang);
  }
  if (open_trash != 'C' || cloes) {
    Open = 0;
    cloes = 1;
    if (ang > 5) {
      ang--;
      servo.write(ang);
    }
  }
}
