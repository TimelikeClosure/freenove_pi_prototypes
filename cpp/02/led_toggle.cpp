#include <wiringPi.h>
#include <iostream>

#define ledPin 0
#define buttonPin 1

int main(void){
	if (wiringPiSetup() == -1){
		std::cout << "wiringPi setup failed!" << std::endl;
		return EXIT_FAILURE;
	}

	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
	pinMode(buttonPin, INPUT);
	pullUpDnControl(buttonPin, PUD_UP);

	bool lastRead = 0,
	     currentRead,
	     ledStatus = 0;

	while(1){
		currentRead = digitalRead(buttonPin);
		if (currentRead != lastRead && currentRead == 0){
			ledStatus = !ledStatus;
			if (ledStatus){
				digitalWrite(ledPin, HIGH);
				std::cout << "led ON" << std::endl;
			} else {
				digitalWrite(ledPin, LOW);
				std::cout << "led OFF" << std::endl;
			}
			delay(50);
		}
		lastRead = currentRead;
	}
	return EXIT_SUCCESS;
}
