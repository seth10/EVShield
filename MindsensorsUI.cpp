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

#include "MindsensorsUI.h"

#include "EVShield.h" // for SH_Bank_A define


/** Constructor, you must call initI2C before use! */
MindsensorsUI::MindsensorsUI()
: i2c(SH_Bank_A)
, tft(D1,D4)
{
  ; // nothing needs to be done here besides the initializer list, but initI2C must be called later
}

void MindsensorsUI::initI2C(void * shield, SH_BankPort bp)
{
  i2c.init(shield, bp);
}

// Read the raw x-coordinate of the touchscreen press
uint16_t MindsensorsUI::RAW_X()
{
  return i2c.readInteger(SH_PS_RAWX);
}

// Read the raw y-coordinate of the touchscreen press
uint16_t MindsensorsUI::RAW_Y()
{
  return i2c.readInteger(SH_PS_RAWY);
}
