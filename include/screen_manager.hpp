#pragma once
#include "button.hpp"
#include "menu_screen.hpp"
#include "display_manager.hpp"
#include "about_screen.hpp"
#include "screen_enum.hpp"

class ScreenManager
{
private:
  Button *leftButton = nullptr;
  Button *rightButton = nullptr;
  Button *acceptButton = nullptr;
  MenuScreen *menuScreen = nullptr;
  AboutScreen *aboutScreen = nullptr;

  ScreenEnum currentScreen;

  void handleLeftButton();
  void handleRightButton();
  void handleAcceptButton();

public:
  ScreenManager();
  ~ScreenManager();

  void init(DisplayManager &displayManager);
  void update();
  void setScreen(ScreenEnum screen);
};
