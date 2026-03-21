#include <Arduino.h>
#include "display_manager.hpp"
#include "menu_screen.hpp"
#include "button.hpp"

#define SCREEN_ADDR 0x3C
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64

DisplayManager displayManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, SCREEN_ADDR);
MenuScreen menuScreen(displayManager);
Button *leftButton = nullptr;
Button *rightButton = nullptr;
Button *acceptButton = nullptr;

void setup()
{
  Serial.begin(115200);
  delay(250);

  Wire.begin();
  displayManager.init();
  menuScreen.render();

  static Button leftBtn(19, [&]()
                        { menuScreen.selectNext(); });
  leftButton = &leftBtn;

  static Button rightBtn(23, [&]()
                         { menuScreen.selectPrevious(); });
  rightButton = &rightBtn;

  static Button acceptBtn(18, [&]()
                          { menuScreen.selectCurrent(); });
  acceptButton = &acceptBtn;
}

void loop()
{
  if (leftButton && rightButton && acceptButton)
  {
    leftButton->update();
    rightButton->update();
    acceptButton->update();
  }
  delay(50);
}
