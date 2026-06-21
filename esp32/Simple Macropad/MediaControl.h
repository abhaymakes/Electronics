#pragma once

#include "USBHIDConsumerControl.h"
#include "USBHIDKeyboard.h"

// void openNewTab(USBHIDKeyboard& keyboard);
// void previousTrack(USBHIDKeyboard& keyboard);
// void pauseTrack(USBHIDKeyboard& keyboard);
// void nextTrack(USBHIDKeyboard& keyboard);

void openNewTab(USBHIDKeyboard& keyboard);
void previousTrack(USBHIDConsumerControl& consumer);
void pauseTrack(USBHIDConsumerControl& consumer);
void nextTrack(USBHIDConsumerControl& consumer);