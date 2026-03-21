#pragma once

#include <Arduino.h>

#define DEBOUNCE_DELAY 200

class Button{
  private:
    uint8_t pin;
    volatile bool triggered = false;
    volatile uint32_t lastTime = 0;
    static void IRAM_ATTR isr(void *arg);

  public:
    std::function<void()> callback;
    Button(uint8_t pin, std::function<void()> callback);
    void update();
};