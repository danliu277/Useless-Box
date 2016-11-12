#include <Servo.h>

const int buttonPin = 2;
int buttonState = 0;

Servo myServo;

int pos;
long timeDelay;

void setup(){
	pinMode(buttonPin, INPUT);
	myServo.Attach(9);
}

void loop(){
	buttonState = digitalRead(buttonPin);
	if(buttonState == HIGH){
		for(pos = myServo.read(); pos >= 20; --pos){
			myServo.write(pos);
			timeDelay = random(15, 30);
			delay(15);
		}
	}
	else{
		timeDelay = random(1, 4);
		for(pos = myServo.read(); pos <= 90; pos += timeDelay){
			myServo.write(pos);
			delay(15);
		}
	}
}