#include "menu_screen.hpp"

void MenuScreen::render()
{
  displayManager.clear();
  displayManager.drawTextCentered("Brick Breaker", 0, 1);

  for (size_t i = 0; i < numItems; i++)
  {
    int y = 20 + i * 10;
    if (i == currentIndex)
    {
      displayManager.drawText(0, y, ">");
    }
    displayManager.drawText(10, y, items[i]);
  }
  displayManager.update();
}

void MenuScreen::selectNext()
{
  if (currentIndex >= numItems - 1)
  {
    currentIndex = 0;
  }
  else
  {
    currentIndex++;
  }
  render();
}

void MenuScreen::selectPrevious()
{
  if (currentIndex <= 0)
  {
    currentIndex = numItems - 1;
  }
  else
  {
    currentIndex--;
  }
  render();
}

void MenuScreen::selectCurrent()
{
  if (strcmp(items[currentIndex], "Start") == 0)
  {
    displayManager.clear();
    displayManager.drawTextCentered("Start", 20);
    displayManager.update();
  }
}