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
            print("ESP32:", esp32.readline().decode(errors="ignore").strip())

threading.Thread(target=reader, daemon=True).start()

def fetch_joke():
    response = requests.get('https://official-joke-api.appspot.com/random_joke')

    return response.json()

while True:
    joke = json.dumps(fetch_joke()) + '\n'
    esp32.write(joke.encode())
    time.sleep(2)