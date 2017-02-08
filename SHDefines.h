/** \file SHDefines.h
* SHDefines.h defines global definitions and constants used by EVShield library.
*/

/*
 * EVShield interface library
 * Copyright (C) 2015 mindsensors.com
 *
 * This file is part of EVShield interface library.
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef SHDEFINES_H
#define SHDEFINES_H


/**
  \enum SH_BankPort for the sensor bank ports
*/
typedef enum {
  SH_BAS1 = 0x01,  /*!<  Bank A Sensor Port 1 */
  SH_BAS2 = 0x02,  /*!<  Bank A Sensor Port 2 */
  SH_BBS1 = 0x03,  /*!<  Bank B Sensor Port 1 */
  SH_BBS2 = 0x04   /*!<  Bank B Sensor Port 2 */
} SH_BankPort;

//! Protocols supported by EVShield.
/**
  \enum SH_Protocols Protocol enums - to initialize your EVShield with appropriate protocol.
*/
typedef enum {
  SH_HardwareI2C  = 0,  /*!< It's best to use hardware i2c as it is faster, (but it does not work with Ultrasonic Sensor). */
  SH_SoftwareI2C,  /*!< Software I2C is slower, and designed to work with Ultrasonic sensor.  */
} SH_Protocols;

#endif
