/*
 * pi_gpio.hpp
 *
 *      Created on: 13.11.2012
 *      Author: Tino Goehlert
 *      Company: Mechlab engineering
 */

#ifndef RPI_GPIO_HPP_
#define RPI_GPIO_HPP_

#include <string>
#include <vector>
#include "pi_gpio_def.hpp"
#include "types.h"

using namespace std;

/*
static int pinToGpioR1 [64] =
{
  17, 18, 21, 22, 23, 24, 25, 4,	// From the Original Wiki - GPIO 0 through 7
   0,  1,				// I2C  - SDA0, SCL0
   8,  7,				// SPI  - CE1, CE0
  10,  9, 11, 				// SPI  - MOSI, MISO, SCLK
  14, 15,				// UART - Tx, Rx

// Padding:

      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 31
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 47
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 63
} ;

static int pinToGpioR2 [64] =
{
  17, 18, 27, 22, 23, 24, 25, 4,	// From the Original Wiki - GPIO 0 through 7:	wpi  0 -  7
   2,  3,				// I2C  - SDA0, SCL0				wpi  8 -  9
   8,  7,				// SPI  - CE1, CE0				wpi 10 - 11
  10,  9, 11, 				// SPI  - MOSI, MISO, SCLK			wpi 12 - 14
  14, 15,				// UART - Tx, Rx				wpi 15 - 16
  28, 29, 30, 31,			// New GPIOs 8 though 11			wpi 17 - 20

// Padding:

                      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 31
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 47
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// ... 63
} ;
*/

namespace RaspberryPi
{
    

    class IOPin
    {
     public:
        IOPin();
        IOPin(u8 number);
        ~IOPin();
     protected:
        u8 m_pin_nr;
    };

    class PWMPin : public IOPin
    {
     public:
         PWMPin(u8 number);
        ~PWMPin();
     private:
        
    };

    class PinList
    {
     public:
        static int Setup();
        static IOPin* Pin(u8 number);
     private:
        static vector<IOPin> _pinvec_r1;
        static vector<IOPin> _pinvec_r2;
    };

    class IOPort
    {
     public:
         IOPort();
        ~IOPort();
     private:
        static int   Init();
        static bool  _is_init;

    };
};

#endif
