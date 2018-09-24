#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>

#define ledPinRed 0
#define ledPinGreen 1
#define ledPinBlue 2

void ledInit(){
	softPwmCreate(ledPinRed, 0, 100);
	softPwmCreate(ledPinGreen, 0, 100);
	softPwmCreate(ledPinBlue, 0, 100);
}

void ledColorSet(int r_val, int g_val, int b_val){
	softPwmWrite(ledPinRed, r_val);
	softPwmWrite(ledPinGreen, g_val);
	softPwmWrite(ledPinBlue, b_val);
}

int setup(){
	if (wiringPiSetup() == -1){
		std::cout << "setup wiringPi failed!" << std::endl;
		return 1;
	}
	ledInit();
	std::cout << "Program started successfully" << std::endl;
	return 0;
}

void loop(){
	int r, g, b;
	while(1){
		r = random() % 100;
		g = random() % 100;
		b = random() % 100;
		ledColorSet(r, g, b);
		printf("r=%d, g=%d, b=%d \n", r, g, b);
		delay(300);
	}
}

int main(){
	if (setup()){
		return 1;
	}

	loop();
	return 0;
}

