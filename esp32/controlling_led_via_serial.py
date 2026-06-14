import serial
import time
import json
import requests
import threading

esp32 = serial.Serial('COM3', 9600, timeout=1)
time.sleep(2)

def reader():
    while True:
        if esp32.in_waiting:
            print(esp32.readline().decode(errors="ignore").strip())

threading.Thread(target=reader, daemon=True).start()

while True:
    command = input("Enter command: ")
    command += '\n'
    esp32.write(command.encode())
    time.sleep(1)