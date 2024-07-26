import serial
import time

# Replace 'COM3' with your Arduino's serial port
arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)

def write_read(command):
    arduino.write(bytes(command, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

while True:
    command = input("Enter command (H to turn ON, L to turn OFF, Q to quit): ")
    if command == 'Q':
        break
    if command in ['H', 'L']:
        value = write_read(command)
        print(value)
    else:
        print("Invalid command. Please enter 'H', 'L', or 'Q'.")
