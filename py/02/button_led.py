import RPi.GPIO as GPIO

ledPin = 11
buttonPin = 12

def setup():
    print('Program loading...')
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

def loop():
    while True:
        if GPIO.input(buttonPin) == GPIO.LOW:
            GPIO.output(ledPin, GPIO.HIGH)
            print('led ON')
        else:
            GPIO.output(ledPin, GPIO.LOW)
            print('led OFF')

def destroy():
    GPIO.output(ledPin, GPIO.LOW)
    GPIO.cleanup()

if __name__ == '__main__':
    setup()
    try:
        loop()
    except KeyboardInterrupt:
        destroy()
