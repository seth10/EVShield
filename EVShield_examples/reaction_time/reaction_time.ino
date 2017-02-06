
/*
 * --- EXTENSIONS ---
 * 1. Try using the GO button instead of a touch sensor.
 * 2. Make it a race! Plug in two touch sensors and see whether you
 *    or your friend has a faster reaction time. Try to show each player's time,
 *    not just who won.
 * 3. Use a different sensor. Maybe use a light sensor, have a color palette
 *    on paper and use the screen show you what color to move the sensor over.
 * 4. Keep track of high scores! Use EEPROM or SPIFFS to save the high score.
 */

#include <EVShield.h>
#include <EVs_NXTTouch.h>

const long minTime = 1000;
const long maxTime = 5000;

EVShield ev;
EVs_NXTTouch touch;

void waitForPress(bool reversed = false) {
    if (!reversed) {
        while (!touch.isPressed()) delay(10); // wait until the touch sensor is pressed
        while (touch.isPressed()) delay(10); // wait until it is released
    } else {
        while (touch.isPressed()) delay(10); // wait until it is released
        while (!touch.isPressed()) delay(10); // wait until the touch sensor is pressed
    }
}

void setup() {
    ev.init();
    touch.init(&ev, SH_BAS1);
    ev.ledSetRGB(0,0,0); // turn off both LEDs
    randomSeed(analogRead(0));
    
    ev.screen.setTextSize(4); // large for title
    ev.screen.println("Ready?");
    
    ev.screen.setTextSize(2); // default (1 is very small)
    // prepend a newline to put some space between the title and this text
    // this text will automatically be wrapped to the next line on screen
    ev.screen.println("\nAttach a touch sensor to  BAS1 and press to begin.");
    waitForPress();
    
    ev.screen.println("\nWait for the red box to   appear, then press!");
    waitForPress();
    
    ev.screen.clearScreen();
}

void loop() {
    long waitTime = random(minTime,maxTime);
    delay(waitTime);
    //ev.screen.fillScreen(ILI9341_RED);
    //ev.screen.getWidth()*0.4
    ev.screen.fillRect(120, 90, 80, 60, ILI9341_RED);
    
    long start = millis();
    // make sure you can't just hold it down (wait for the button to be
    // not pressed, then wait for a press)
    waitForPress(true);
    long end = millis();
    
    ev.screen.setCursor(0,0); // print the result at the top of the screen
    ev.screen.print("You reacted in ");
    ev.screen.print(end - start);
    ev.screen.println(" ms!");
    
    // the button is already held down, wait for it to be released first
    while (touch.isPressed()) delay(10); // wait until it is released
    while (!touch.isPressed()) { // flash LEDs until it is pressed to continue
        ev.bank_a.ledSetRGB(255,0,0);
        ev.bank_b.ledSetRGB(0,255,0);
        delay(400);
        ev.bank_a.ledSetRGB(0,255,0);
        ev.bank_b.ledSetRGB(255,0,0);
        delay(400);
    }
    
    ev.ledSetRGB(0,0,0); // turn off both LEDs
    ev.screen.clearScreen();
}

/*
 * --- HINTS ---
 * 1. ev.screen.isKeyPressed()
 */
