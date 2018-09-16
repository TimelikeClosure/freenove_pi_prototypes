#include <wiringPi.h>
#include <iostream>

#define ledPin 1
#define pwmMin 0
#define pwmMax 1023

void setLed(short led, int brightness){
	pwmWrite(ledPin, brightness);
}

int setup(){
	if (wiringPiSetup() == -1){
		std::cout << "Error: wiringPi initialization failed" << std::endl;
		return 1;
	}
	pinMode(ledPin, PWM_OUTPUT);
	setLed(ledPin, 0);
	return 0;
}

int loop(){
	while (1){
		std::cout << "Inhale..." << std::flush;
		for (int brightness = pwmMin; brightness <= pwmMax; brightness++){
			setLed(ledPin, brightness);
			delay(2);
		}
		std::cout << std::endl;
		delay(pwmMax - pwmMin);
		std::cout << "Exhale..." << std::flush;
		for (int brightness = pwmMax; brightness >= pwmMin; brightness--){
			setLed(ledPin, brightness);
			delay(2);
		}
		std::cout << std::endl;
		delay(pwmMax - pwmMin);
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

