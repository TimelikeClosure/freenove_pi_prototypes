#include <wiringPi.h>
#include <iostream>

#define ledPin 0

int main() {
	if (wiringPiSetup() == -1){
		std::cout << "wiringPi setup failed!" << std::endl;
		return 1;
	}

	printf("wiringPi initialized successfully, GPIO %d(wiringPi pin)\n");

	pinMode(ledPin, OUTPUT);

	while(1){
		digitalWrite(ledPin, HIGH);
		std::cout << "LED On" << std::endl;
		delay(1000);
		digitalWrite(ledPin, LOW);
		std::cout << "LED Off" << std::endl;
		delay(1000);
	}

	return 0;
}
