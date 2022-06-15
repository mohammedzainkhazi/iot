import RPi_GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(13,GPIO.OUT)

while True:
    let = int(input("Enter Key : "))
    if let == 1:
        GPIO.output(13,GPIO.HIGH)
    elif let == 0:
        GPIO.output(13,GPIO.LOW)
    else:
        break
GPIO.cleanup()