# ESP32-S2 Touch Media Controller

A compact USB HID media controller built with the ESP32-S2. The device uses capacitive touch inputs to trigger media controls and browser shortcuts, appearing as a standard USB HID device without requiring any additional drivers.

## Features

- Open a new browser tab (`Ctrl + T`)
- Previous track
- Play / Pause
- Next track
- Capacitive touch controls
- USB HID support
- Driverless operation on modern operating systems

## Hardware

The project was tested on the **Flipper WiFi Dev Board (ESP32-S2)**, but it should work with most ESP32-S2 boards that support capacitive touch input.

### Touch Pin Mapping

| Function | GPIO |
|----------|------|
| New Tab | GPIO1 |
| Previous Track | GPIO13 |
| Play / Pause | GPIO12 |
| Next Track | GPIO10 |

## How It Works

The ESP32-S2 continuously monitors the configured touch pins.

When a touch event is detected:

- **New Tab** sends a keyboard shortcut (`Ctrl + T`) using the USB keyboard HID interface.
- **Media controls** use the USB Consumer Control HID interface to send media key commands such as Play/Pause and Track Navigation.

Because the device uses standard USB HID protocols, it is recognized automatically by Windows, Linux, and macOS.

## Building

### Requirements

- Arduino IDE
- ESP32 Arduino Core
- ESP32-S2 development board

### Libraries

The following libraries are included with the ESP32 Arduino Core:

- `USB`
- `USBHIDKeyboard`
- `USBHIDConsumerControl`

### Flashing

1. Open the project in Arduino IDE.
2. Select your ESP32-S2 board.
3. Compile and upload the sketch.
4. Connect the board via USB.

The device should be detected automatically as a USB HID controller.

## Touch Calibration

Capacitive touch values can vary depending on:

- Board model
- Power source
- Wiring
- Environmental conditions

The default threshold is:

```cpp
const int TOUCH_THRESHOLD = 30000;
```

If touch detection is unreliable, use the Serial Monitor to observe touch readings and adjust the threshold accordingly.

## Future Improvements

- OLED status display
- Volume controls
- Additional browser shortcuts
- Automatic touch calibration
- User-configurable profiles
- Macro support
- Touch feedback indicators

## License

This project is provided as-is for educational and personal use. Feel free to modify and adapt it to your needs.
