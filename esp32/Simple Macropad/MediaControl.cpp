#include "esp32-hal.h"
#include "USBHIDConsumerControl.h"
#include "USBHIDKeyboard.h"
#include <Arduino.h>
#include "MediaControl.h"

// void openNewTab(USBHIDKeyboard& keyboard) {
//   keyboard.press(KEY_LEFT_CTRL);
//   keyboard.press('t');
//   delay(100);
//   keyboard.releaseAll();
// }

// void previousTrack(USBHIDKeyboard& keyboard) {
//   keyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
// }

// void pauseTrack(USBHIDKeyboard& keyboard){
//     keyboard.write(KEY_MEDIA_PLAY_PAUSE);
// }

// void nextTrack(USBHIDKeyboard& keyboard){
//     keyboard.write(KEY_MEDIA_NEXT_TRACK);
// }

void openNewTab(USBHIDKeyboard& keyboard) {
  keyboard.press(KEY_LEFT_CTRL);
  keyboard.press('t');
  delay(100);
  keyboard.releaseAll();
}

void previousTrack(USBHIDConsumerControl& consumer) {
  consumer.press(CONSUMER_CONTROL_SCAN_PREVIOUS);
  delay(100);
  consumer.release();
}

void pauseTrack(USBHIDConsumerControl& consumer) {
  consumer.press(CONSUMER_CONTROL_PLAY_PAUSE);
  delay(100);
  consumer.release();
}

void nextTrack(USBHIDConsumerControl& consumer) {
  consumer.press(CONSUMER_CONTROL_SCAN_NEXT);
  delay(100);
  consumer.release();
}
