#include "USB.h"
#include "USBHIDKeyboard.h"
#include "USBHIDConsumerControl.h"
#include "MediaControl.h"

const uint8_t NEW_TAB_TOUCH_PIN = 1;
const uint8_t PREVIOUS_TRACK_PIN = 13;
const uint8_t PAUSE_TRACK_PIN = 12;
const uint8_t NEXT_TRACK_PIN = 10;

USBHIDKeyboard Keyboard;
USBHIDConsumerControl Consumer;

bool newTabWasTouched = false;
bool previousTrackWasTouched = false;
bool pauseTrackWasTouched = false;
bool nextTrackWasTouched = false;

const int TOUCH_THRESHOLD = 30000;

bool isPinTouched(uint8_t touchPin) {
  bool isTouched = touchRead(touchPin) > TOUCH_THRESHOLD;
  return isTouched;
}

void setup() {

  USB.begin();
  Keyboard.begin();
  Consumer.begin();

  delay(2000);
}

void loop() {

  bool newTabTouched = isPinTouched(NEW_TAB_TOUCH_PIN);
  bool previousTrackTouched = isPinTouched(PREVIOUS_TRACK_PIN);
  bool pauseTrackTouched = isPinTouched(PAUSE_TRACK_PIN);
  bool nextTrackTouched = isPinTouched(NEXT_TRACK_PIN);


  if (newTabTouched && !newTabWasTouched) {
    openNewTab(Keyboard);
  }

  if (previousTrackTouched && !previousTrackWasTouched) {
    previousTrack(Consumer);
  }

  if (pauseTrackTouched && !pauseTrackWasTouched) {
    pauseTrack(Consumer);
  }

  if (nextTrackTouched && !nextTrackWasTouched) {
    nextTrack(Consumer);
  }

  newTabWasTouched = isPinTouched(NEW_TAB_TOUCH_PIN);
  previousTrackWasTouched = isPinTouched(PREVIOUS_TRACK_PIN);
  pauseTrackWasTouched = isPinTouched(PAUSE_TRACK_PIN);
  nextTrackWasTouched = isPinTouched(NEXT_TRACK_PIN);

  delay(50);
}
