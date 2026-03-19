#include "menu_screen.hpp"

void MenuScreen::render(){
  displayManager.clear();
  displayManager.drawTextCentered("Brick Breaker", 20, 1);

  for (size_t i = 0; i < numItems; i++)
  {
    int y = 40 + i * 10;
    if (i == currentIndex){
      displayManager.drawText(0, y, ">");
    }
    displayManager.drawText(10, y, items[i]);
  }
  displayManager.update();
}