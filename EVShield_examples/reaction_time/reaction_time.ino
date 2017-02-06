#include <EVShield.h>
#include <EVs_NXTTouch.h>

const long minTime = 1000;
const long maxTime = 5000;

EVShield ev;
EVs_NXTTouch touch;

void setup() {
    ev.init();
    touch.init(&ev, SH_BAS1);
    randomSeed(analogRead(0));
    
    ev.screen.setTextSize(4); // large for title
    ev.screen.println("Ready?");
    ev.screen.setTextSize(2); // default (1 is very small)
    // prepend a newline to put some space between the title and this text
    // this text will automatically be wrapped to the next line on screen
    ev.screen.println("\nAttach a touch sensor to  BAS1 and press to begin.");
    
    while (!touch.isPressed()) delay(10); // wait until the touch sensor is pressed
    while (touch.isPressed()) delay(10); // wait until it is released
    
    ev.screen.println("\nWait for the screen to turn red, then press!");
    delay(4000);
    
    ev.screen.clearScreen();
}

void loop() {
    long waitTime = random(minTime,maxTime);
    delay(waitTime);
    //ev.screen.fillScreen(ILI9341_RED);
    //ev.screen.getWidth()*0.4
    ev.screen.fillRect(120, 90, 80, 60, ILI9341_RED);
    
    long start = millis();
    while (touch.isPressed()) delay(10); // make sure you can't just holding it down
    while (!touch.isPressed()) delay(10);
    long end = millis();
    
    ev.screen.print("You reacted in ");
    ev.screen.print(end - start);
    ev.screen.println(" milliseconds!");
    
    delay(5000);
    ev.screen.clearScreen();
    
    // ev.screen.setCursor(0,0);
    // ev.screen.print(touch.readRaw());
    // ev.screen.print("    ");
    
    // if (touch.isPressed())
    //     ev.screen.fillRect(10, 10, 20, 10, ILI9341_RED);
    // else
    //     ev.screen.fillRect(10, 10, 20, 10, ILI9341_WHITE);
}
