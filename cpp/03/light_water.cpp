#include <wiringPi.h>
#include <iostream>

const unsigned short ledCount = 10;

void setLed(short led, bool on){
	on ? digitalWrite(led, LOW) : digitalWrite(led, HIGH);
}

int setup(){
	if (wiringPiSetup() == -1){
		std::cout << "Error: wiringPi initialization failed" << std::endl;
		return 1;
	}
	for (short i = 0; i < ledCount; i++){
		pinMode(i, OUTPUT);
		setLed(i, 0);
	}
	return 0;
}

int loop(){
	while (1){
		std::cout << "New wave" << std::endl;
		for (short led = 0; led < ledCount; led++){
			std::cout << "led # " << led << std::endl;
			setLed(led, 1);
			delay(100);
			setLed(led, 0);
		}
		for (short led = ledCount - 1; led >= 0; led--){
			std::cout << "led # " << led << std::endl;
			setLed(led, 1);
			delay(100);
			setLed(led, 0);
		}
	}
}

int main(){
	int statusCode;
	statusCode = setup();
	if (statusCode) { return statusCode; }
	try {
		loop();
	} catch (std::exception error){
		return 2;
	}
	return 0;
}

