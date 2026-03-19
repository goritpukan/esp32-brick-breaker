#include <Arduino.h>
#include <Adafruit_SSD1306.h>

class DisplayManager{
  private:
    Adafruit_SSD1306 display;
    int address;

  public:
    DisplayManager(int displayWidth, int displayHeight, int displayAddress);
    void init();
    inline void clear() { display.clearDisplay(); }
    inline void update() { display.display(); }
    void drawText(int x, int y, const char *text, int size = 1);
    void drawTextCentered(const char *text, int y, int size = 1);
};