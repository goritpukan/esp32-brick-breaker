#include <Arduino.h>
#include "display_manager.hpp"

#define SCREEN_ADDR 0x3C
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64

DisplayManager displayManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, SCREEN_ADDR);

void setup() {
  Serial.begin(115200);
  delay(250);

  Wire.begin();
  displayManager.init();
  displayManager.drawTextCentered("Hello ESP", 20, 1);
  displayManager.update();
}

void loop() {
}
