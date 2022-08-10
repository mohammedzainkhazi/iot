import Rpi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(17,GPIO.OUT)

while True:
    let1 = int(input("Enter Key : \n"))
    if let1 == 1:
        GPIO.output(17,GPIO.HIGH)
    elif let1 == 0:
        GPIO.output(17,GPIO.LOW)
    else:
        break

GPIO.cleanup()