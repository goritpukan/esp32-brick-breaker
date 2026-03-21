#pragma once
#include "display_manager.hpp"

class AboutScreen
{
private:
  DisplayManager &displayManager;
  const char *ABOUT_TEXT[10] = {
      "ESP32 Brick Breaker",
      "Version 1.0",
      "Author: Vadym Chunikhin",
      "Use buttons to scroll or exit",
      "This is Brick Breaker game",
      "implementation with statistics",
      "screen management and buttons handling.",
      "Build using basic OOP rules and PIO",
      "Please support GitHub repo:",
      "https://github.com/goritpukan/esp32-brick-breaker/tree/main"};
  const int ABOUT_LINES_COUNT = sizeof(ABOUT_TEXT) / sizeof(ABOUT_TEXT[0]);

public:
  AboutScreen(DisplayManager &displayManager) : displayManager(displayManager) {}
  void render();
  void scrollUp();
  void scrollDown();
};