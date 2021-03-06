/*
Arduino Library for SyRen Simplified Serial
Copyright (c) 2012-2013 Dimension Engineering LLC
http://www.dimensionengineering.com/arduino

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE
USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef SyRenSimplified_h
#define SyRenSimplified_h   

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#if defined(USBCON)
#define SabertoothTXPinSerial Serial1 // Arduino Leonardo has TX->1 on Serial1, not Serial.
#else
#define SabertoothTXPinSerial Serial
#endif
#define SyRenTXPinSerial SabertoothTXPinSerial

/*!
\class SyRenSimplified
\brief Controls a %SyRen motor driver running in Simplified Serial mode.
*/
class SyRenSimplified
{
public:
  /*!
  Initializes a new instance of the SyRenSimplified class.
  The Arduino TX serial port is used.
  */
  SyRenSimplified();
  
  /*!
  Initializes a new instance of the SyRenSimplified class.
  The specified serial port is used.
  \param port The port to use.
  */
  SyRenSimplified(Print& port);

public:
  /*!
  Sets the power of the motor.
  \param power The power, between -127 and 127.
  */
  void motor(int power);
  
  /*!
  Sets the power of the specified motor.
  \param motor The motor number, 1.
  \param power The power, between -127 and 127.
  */
  void motor(byte motor, int power); 
  
  /*!
  Stops.
  */ 
  void stop();
  
private:
  Print& _port;
};

#endif
