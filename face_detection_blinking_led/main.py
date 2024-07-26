import cv2
import serial
import time

# Initialize serial communication with Arduino
arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=.1)

# Function to send command to Arduino
def send_command(command):
    arduino.write(bytes(command, 'utf-8'))
    time.sleep(0.05)

# Load the pre-trained face detection model
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Start video capture
cap = cv2.VideoCapture(0)

# Variable to keep track of the LED state
led_on = False

while True:
    ret, frame = cap.read()
    if not ret:
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.1, 4)

    # Check if any faces are detected
    if len(faces) > 0:
        if not led_on:
            send_command('H')  # Send command to turn LED on
            led_on = True
    else:
        if led_on:
            send_command('L')  # Send command to turn LED off
            led_on = False

    # Draw rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)

    # Display the output
    cv2.imshow('img', frame)

    # Break the loop if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture object
cap.release()
cv2.destroyAllWindows()