#include <wiringPi.h>
#include <iostream>

#define buzzerPin 0
#define buttonPin 1

int main(void){
	if (wiringPiSetup() == -1){
		std::cout << "setup wiringPi failed." << std::endl;
		return 1;
	}

	pinMode(buzzerPin, OUTPUT);
	pinMode(buttonPin, INPUT);

	pullUpDnControl(buttonPin, PUD_UP);
	while(1){
		if (digitalRead(buttonPin) == LOW){
			digitalWrite(buzzerPin, LOW);
		} else {
			digitalWrite(buzzerPin, HIGH);
		}
	}

	return 0;
}

