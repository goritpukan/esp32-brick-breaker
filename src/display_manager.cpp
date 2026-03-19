#include "display_manager.hpp"
#include <Arduino.h>
#include <Adafruit_SSD1306.h>

DisplayManager::DisplayManager(int displayWidth, int displayHeight, uint8_t displayAddress) : display(displayWidth, displayHeight, &Wire, -1), address(displayAddress){}

void DisplayManager::init(){
  if (!display.begin(SSD1306_SWITCHCAPVCC, address))
  {
    Serial.println("SSD1306 allocation failed");
    while (true)
      ;
  }
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
}

void DisplayManager::drawText(int x, int y, const char *text, int size){
  display.setTextSize(size);
  display.setCursor(x, y);
  display.print(text);
}

void DisplayManager::drawTextCentered(const char *text, int y, int size){
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, y, &x1, &y1, &w, &h);
  drawText((display.width() - w) / 2, y, text, size);
}
