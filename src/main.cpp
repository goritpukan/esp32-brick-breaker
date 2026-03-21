#include <Arduino.h>
#include "display_manager.hpp"
#include "screen_manager.hpp"

#define SCREEN_ADDR 0x3C
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64

DisplayManager displayManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, SCREEN_ADDR);
ScreenManager screenManager;

void setup()
{
  Serial.begin(115200);
  delay(250);

  Wire.begin();
  displayManager.init();
  screenManager.init(displayManager);
}

void loop()
{
  screenManager.update();
}
