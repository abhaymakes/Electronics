\# ESP32-S2 Touch Media Controller



A small USB HID device built with an ESP32-S2.



The device uses capacitive touch pads to control media playback and browser shortcuts. It connects over USB and shows up as a standard HID device, so no drivers are needed.



\## Features



\* Open a new browser tab

\* Previous track

\* Play / Pause

\* Next track

\* Capacitive touch input

\* USB HID support



\## Hardware



Tested on the Flipper WiFi Dev Board (ESP32-S2), but it should work on other ESP32-S2 boards with touch-capable GPIOs.



Current touch pin mapping:



| Function       | GPIO   |

| -------------- | ------ |

| New Tab        | GPIO1  |

| Previous Track | GPIO13 |

| Play/Pause     | GPIO12 |

| Next Track     | GPIO10 |



\## How it works



The ESP32 continuously monitors the touch pins. When a touch is detected, it sends the corresponding HID command over USB.



Browser actions use the keyboard HID interface, while media controls use consumer control HID commands.



\## Building



Open the project in Arduino IDE and install the ESP32 board package.



Required libraries are included with the ESP32 Arduino core:



\* USB

\* USBHIDKeyboard

\* USBHIDConsumerControl



Select your ESP32-S2 board and upload.



\## Notes



Touch values vary between boards and setups. You may need to adjust the touch threshold for reliable detection.



Current threshold:



```cpp

const int TOUCH\_THRESHOLD = 30000;

```



Use Serial output to monitor touch readings and tune the value if needed.



\## Future Ideas



\* OLED menu

\* Volume controls

\* More browser shortcuts

\* Touch calibration

\* Profiles and macros



