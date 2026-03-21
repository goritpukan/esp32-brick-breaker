#pragma once
#include "button.hpp"
#include "menu_screen.hpp"
#include "display_manager.hpp"

enum ScreenEnum
{
  GAME,
  MENU,
  PAUSE
};

class ScreenManager
{
private:
  Button *leftButton = nullptr;
  Button *rightButton = nullptr;
  Button *acceptButton = nullptr;
  MenuScreen *menuScreen = nullptr;
  ScreenEnum currentScreen;
  void handleLeftButton();
  void handleRightButton();
  void handleAcceptButton();

public:
  ScreenManager();
  ~ScreenManager();
  void init(DisplayManager &displayManager);
  void update();
};
