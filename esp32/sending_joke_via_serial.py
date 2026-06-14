# import serial
# import time
# import json
# import requests
# import threading

# esp32 = serial.Serial('COM3', 9600, timeout=1)
# time.sleep(2)

# def reader():
#     while True:
#         if esp32.in_waiting:
#             print("ESP32:", esp32.readline().decode(errors="ignore").strip())

# threading.Thread(target=reader, daemon=True).start()

# def fetch_joke():
#     response = requests.get('https://official-joke-api.appspot.com/random_joke')

#     return response.json()

# while True:
#     joke = json.dumps(fetch_joke()) + '\n'
#     esp32.write(joke.encode())
#     time.sleep(2)




import requests
import time

URL = "http://localhost:8085/data.json"

def find_sensors(node, stats):
    if isinstance(node, dict):
        text = node.get("Text", "")
        value = node.get("Value", "")

        # CPU Usage
        if text == "CPU Total":
            stats["cpu"] = value

        # CPU Temperature
        elif text == "CPU" and "°C" in value:
            stats["cpu_temp"] = value

        # RAM Usage (first Memory percentage encountered)
        elif text == "Memory" and "%" in value and stats["ram"] == "N/A":
            stats["ram"] = value

        # GPU Temperature
        elif text == "GPU Core" and "°C" in value:
            stats["gpu_temp"] = value

        # GPU Usage
        elif text == "GPU Core" and "%" in value:
            stats["gpu"] = value

        for child in node.get("Children", []):
            find_sensors(child, stats)

while True:
    try:
        data = requests.get(URL).json()

        stats = {
            "cpu": "N/A",
            "cpu_temp": "N/A",
            "ram": "N/A",
            "gpu": "N/A",
            "gpu_temp": "N/A"
        }

        find_sensors(data, stats)

        print(
            f"CPU {stats['cpu']} | "
            f"CPU TEMP {stats['cpu_temp']} | "
            f"RAM {stats['ram']} | "
            f"GPU {stats['gpu']} | "
            f"GPU TEMP {stats['gpu_temp']}",
            end="\r"
        )

    except Exception as e:
        print("Error:", e)

    time.sleep(1)