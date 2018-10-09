#include <wiringPi.h>
#include <iostream>
#include <softTone.h>
#include <math.h>

#define buzzerPin 0
#define buttonPin 1

int alertor(int pin){
	int x;
	double sinVal, toneVal;

	for (x = 0; x < 360 ; x++){
		sinVal = sin(x * (M_PI / 180));
		toneVal = 2000 + sinVal * 500;
		softToneWrite(pin, toneVal);
		delay(1);
	}
}

void stopAlertor(int pin){
	softToneWrite(pin, 0);
}

int main(void){
	if (wiringPiSetup() == -1){
		std::cout << "wiringPi setup failed!" << std::endl;
		return 1;
	}
	pinMode(buzzerPin, OUTPUT);
	pinMode(buttonPin, INPUT);
	softToneCreate(buzzerPin);
	pullUpDnControl(buttonPin, PUD_UP);
	while(1){
		if(digitalRead(buttonPin) == LOW){
			alertor(buzzerPin);
			std::cout << "alertor on..." << std::flush;
		} else {
			stopAlertor(buzzerPin);
			std::cout << "buzzer cancelled" << std::endl;
		}
	}
	return 0;
}

