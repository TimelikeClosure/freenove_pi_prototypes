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
	     isUnstable = 0,
	     lastStableRead,
	     ledStatus = 0;
	long lastChange = 0,
	     debounceDelay = 50;

	while(1){
		currentRead = digitalRead(buttonPin);
		if (currentRead != lastRead){
			lastChange = millis();
			isUnstable = 1;
		}
		if (isUnstable){
			if (millis() >= lastChange + debounceDelay){
				isUnstable = 0;
				if (currentRead != lastStableRead){
					lastStableRead = currentRead;
					if (currentRead == LOW){
						ledStatus = !ledStatus;
						if (ledStatus){
							digitalWrite(ledPin, HIGH);
							std::cout << "led ON" << std::endl;
						} else {
							digitalWrite(ledPin, LOW);
							std::cout << "led OFF" << std::endl;
						}
					}
				}
			}
		}
		lastRead = currentRead;
	}
	return EXIT_SUCCESS;
}
