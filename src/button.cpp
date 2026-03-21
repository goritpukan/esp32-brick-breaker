#include "button.hpp"

Button::Button(uint8_t pin, std::function<void()> callback) : pin(pin), callback(callback)
{
  pinMode(pin, INPUT_PULLUP);
  attachInterruptArg(digitalPinToInterrupt(pin), isr, this, FALLING);
}

void IRAM_ATTR Button::isr(void *arg)
{
  Button *self = static_cast<Button *>(arg);
  uint32_t now = millis();
  if (now - self->lastTime > DEBOUNCE_DELAY)
  {
    self->triggered = true;
    self->lastTime = now;
  }
}

void Button::update()
{
  if (!triggered)
  {
    return;
  }
  triggered = false;
  callback();
}