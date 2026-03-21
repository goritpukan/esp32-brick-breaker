#pragma once

#include "display_manager.hpp"

class MenuScreen{
  private:
    DisplayManager &displayManager;
    uint8_t currentIndex = 0;
    const char *items[3] = {"Start", "Statistics", "About"};
    static constexpr size_t numItems = sizeof(items) / sizeof(items[0]);

  public:
    MenuScreen(DisplayManager &displayManager) : displayManager(displayManager) {}
    void render();
    void selectNext();
    void selectPrevious();
    void selectCurrent();
};
