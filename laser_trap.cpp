
// These constants won't change:
const int analogPin = A0;   // pin that the Solar panel is attached to
const int ledPin = 13;      // pin that the Alarm is attached to
const int threshold = 130;   // The threshold level that is between the solar value readings when the laser is in contact vs when the laser is off.
                           // change threshold value to calabrate alarm system

void setup() {
 // initialize the LED(alarm) pin as an output: 
 pinMode(ledPin, OUTPUT);
 // initialize serial communications:
 Serial.begin(9600);

}
void loop() {
 // read the value of the potentiometer: 
 int analogValue = analogRead(analogPin);

 // if the analog value is high enough, turn on the LED(alarm): 
 if (analogValue < threshold) {
 digitalWrite(ledPin, HIGH);
 }
 // print the analog value:
 Serial.println(analogValue);
 delay(1);       // delay in between reads for stability
}
