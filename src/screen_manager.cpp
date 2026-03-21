#include "screen_manager.hpp"
#include "menu_screen.hpp"
#include "display_manager.hpp"
#include "button.hpp"
#include "screen_enum.hpp"

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
  delete aboutScreen;
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

  aboutScreen = new AboutScreen(displayManager);
}

void ScreenManager::handleLeftButton()
{
  switch (currentScreen)
  {
  case ScreenEnum::MENU:
    menuScreen->selectPrevious();
    break;
  case ScreenEnum::ABOUT:
    aboutScreen->scrollUp();
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
  case ScreenEnum::ABOUT:
    aboutScreen->scrollDown();
    break;
  }
}

void ScreenManager::handleAcceptButton()
{
  switch (currentScreen)
  {
  case ScreenEnum::MENU:
    setScreen(menuScreen->selectCurrent());
    break;
  case ScreenEnum::ABOUT:
    setScreen(ScreenEnum::MENU);
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

void ScreenManager::setScreen(ScreenEnum screen)
{
  if (!menuScreen)
    return;

  switch (screen)
  {
  case ScreenEnum::MENU:
    currentScreen = ScreenEnum::MENU;
    menuScreen->render();
    break;
  case ScreenEnum::ABOUT:
    currentScreen = ScreenEnum::ABOUT;
    aboutScreen->render();
  }
}