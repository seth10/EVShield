/*
 * This file is part of the Arduino SoftI2cMaster Library
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Arduino SoftI2cMaster Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef MINDSENSORSUI_H
#define MINDSENSORSUI_H

#include "EVShieldI2C.h"
#include "Adafruit_ILI9341.h"

// Touchscreen X-axis Raw Register.
#define SH_PS_TS_RAWX  0xE7
// Touchscreen Y-axis Raw Register.
#define SH_PS_TS_RAWY  0xE9

// Touchscreen calibration
#define SH_PS_TS_CALIBRATION_DATA_READY 0x70
#define SH_PS_TS_CALIBRATION_DATA 0x71

// I2C commands for manipulating touchscreen calibration values
#define SH_PS_TS_w 0x77
#define SH_PS_TS_l 0x6C


/**
  @brief This class provides basic functions for the PiStorms hardware touchscreen LCD
  */
class MindsensorsUI {

private:
  EVShieldI2C i2c;
  Adafruit_ILI9341 tft;
  
  /** touchscreen configuration values */
  uint16_t x1, y1, x2, y2, x3, y3, x4, y4;
  
  /** how close two consecutive touchscreen readings must be to be considered accurate */
  const uint8_t tolerance;
  
  /** read the raw x-coordinate of the touchscreen press */
  uint16_t RAW_X();
  
  /** read the raw x-coordinate of the touchscreen press */
  uint16_t RAW_Y();
  
  /** get raw touchscreen values, do some math using the config values, and write to the output parameters
    @param[out] x x-value of touchscreen press is written to this variable
    @param[out] y y-value of touchscreen press is written to this variable
  */
  void getReading(uint16_t *x, uint16_t *y);

public:
  /** Constructor, needs these parameters to initialize I2C */
  MindsensorsUI(void * shield, SH_BankPort bp);

  /** read the touchscreen press and write the coordinates to the output parameters
    @param[out] x x-value of touchscreen press is written to this variable
    @param[out] y y-value of touchscreen press is written to this variable
  */
  void getTouchscreenValues(uint16_t *x, uint16_t *y);
  
  /** reads the x-coordinate of the touchscreen press */
  uint16_t TS_X();
  
  /** reads the y-coordinate of the touchscreen press */
  uint16_t TS_Y();
  
  /** detect touchscreen presses and prevents false positives */
  bool isTouched();
  
  /** clear the LCD screen to defualt black */
  void clearScreen();
  
  /** asdf */
  void fillScreen(uint16_t color);
  
  // old MindsensorsUI functions:
  //void fillCircle(uint16_t x, uint16_t y, uint16_t radius, uint16_t fill);
  //void fillBmp(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const char *path);
  //void fillImgArray(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t *image);
  //void rotateRight();
  //void rotateLeft();
  //void drawAutoText(const char *text, uint16_t x, uint16_t y, uint16_t fill, uint8_t size, bool align);
  //void termGotoLine(uint8_t lineno);
  //void termPrintAt(uint8_t lineno, const char *text);
  //void termPrint(const char *text);
  //void termPrintln(const char *text);
  //void termReplaceLastLine(const char *text);
  //void refreshLine(uint8_t lineNum);
  //void drawButton(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const char *prefix, const char *text, bool align);
  //void refresh();
  //void checkButton(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
  //void askQuestion();
  //void askYesOrNoQuestion();
  //void showMessage();
  //void drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t width, uint16_t fill);
  //void drawPolyLine();

};

#endif //MINDSENSORSUI_H