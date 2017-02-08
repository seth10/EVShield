#include <EVShield.h>

EVShield ev;
Adafruit_GFX_Button btn;

void setup() {
    Serial.begin(115200);
    ev.init();
    
    // draw a white button (rectangle) 55 pixels from the left and 20 pixels from the top
    // with a width of 150 pixels and a height of 75 pixels
    ev.screen.fillRect(55, 20, 150, 75, ILI9341_WHITE);
    // grey outline, white fill, black text color, "Press me!" label, font size 2 (standard, 1 is very tiny)
    btn.initButton(&ev.screen, 55, 20, 150, 75, ILI9341_DARKGREY, ILI9341_WHITE, ILI9341_BLACK, "Press me!", 2);
    //btn.drawButton();
    
    // we will have a square indicator 225 pixels from the left and 20 from the top
    // with a side length of 75 (this draws a white outline around that box)
    ev.screen.drawRect(225-1, 20-1, 75+2, 75+2, ILI9341_WHITE);
}

void loop() {
  uint16_t x, y;
  ev.screen.getTouchscreenValues(&x, &y);
  if (btn.contains(x, y))
      btn.press(true);
  else
      btn.press(false);
  
  if (btn.justPressed())
      ev.screen.fillRect(225, 20, 75, 75, ILI9341_WHITE);
  else if (btn.justReleased())
      ev.screen.fillRect(225, 20, 75, 75, ILI9341_BLACK);
  
  Serial.print(x); Serial.print(", "); Serial.println(y);
  //if (btn.isPressed())    Serial.println("isPressed");
  if (btn.justPressed())  Serial.println("justPressed");
  if (btn.justReleased()) Serial.println("justReleased");
  
  delay(10);
}
