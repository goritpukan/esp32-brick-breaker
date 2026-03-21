#include "screen_manager.hpp"
#include "menu_screen.hpp"
#include "display_manager.hpp"
#include "button.hpp"

ScreenManager::ScreenManager()
    : currentScreen(ScreenEnum::MENU)
{
}

ScreenManager::~ScreenManager()
{
  delete leftButton;
  delete rightButton;
  delete acceptButton;
  delete menuScreen;
}

// Should be initialized after display!
void ScreenManager::init(DisplayManager &displayManager)
{
  if (menuScreen)
    return;

  menuScreen = new MenuScreen(displayManager);
  menuScreen->render();

  leftButton = new Button(23, [this]()
                          { handleLeftButton(); });
  rightButton = new Button(19, [this]()
                           { handleRightButton(); });
  acceptButton = new Button(18, [this]()
                            { handleAcceptButton(); });
}

void ScreenManager::handleLeftButton()
{
  switch (currentScreen)
  {
  case ScreenEnum::MENU:
    menuScreen->selectPrevious();
    break;
  }
}

void ScreenManager::handleRightButton()
{
  switch (currentScreen)
  {
  case ScreenEnum::MENU:
    menuScreen->selectNext();
    break;
  }
}

void ScreenManager::handleAcceptButton()
{
  switch (currentScreen)
  {
  case ScreenEnum::MENU:
    menuScreen->selectCurrent();
    break;
  }
}

void ScreenManager::update()
{
  if (!leftButton || !rightButton || !acceptButton)
    return;
  leftButton->update();
  rightButton->update();
  acceptButton->update();
}