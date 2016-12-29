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
#define SH_PS_RAWX  0xE7
// Touchscreen Y-axis Raw Register.
#define SH_PS_RAWY  0xE9

/**
  @brief This class provides basic functions for the PiStorms hardware touchscreen LCD
  */
class MindsensorsUI {

private:
  EVShieldI2C i2c;
  Adafruit_ILI9341 tft;

public:
  /** Constructor, you must call initI2C before use! */
  MindsensorsUI();
  
  void initI2C(void * shield, SH_BankPort bp);
  
  /** read the raw x-coordinate of the touchscreen press */
  uint16_t RAW_X();
  
  /** read the raw x-coordinate of the touchscreen press */
  uint16_t RAW_Y();

};

#endif //MINDSENSORSUI_H
