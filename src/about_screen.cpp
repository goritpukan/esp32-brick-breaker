#include "about_screen.hpp"
#include "display_manager.hpp"

void AboutScreen::render()
{
  displayManager.clear();
  int y = 0;
  for (int i = 0; i < ABOUT_LINES_COUNT; i++)
  {
    y = i * 10;
    displayManager.drawTextCentered(ABOUT_TEXT[i], y);
  }
  displayManager.update();
}

void AboutScreen::scrollDown()
{
}

void AboutScreen::scrollUp()
{
}