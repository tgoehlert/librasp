/* i2c_eeprom
 *
 * Author: Tino Goehlert
 * 
 * Description:
 *   I2C example program for libraspberry.
 *
 */

#include <iostream>
#include <exception>
#include "../src/pi_i2c.hpp"

using namespace RaspberryPi;
using namespace std;

int main()
{
    try{
        I2CDevice::Channel0()->SlaveAddress(0x20);
        I2CDevice::Channel0()->Open();
        I2CDevice::Channel0()->Write(0x00,0x00);
    }catch(exception& e){
        cout << e.what() << std::endl; 
    }
    return 0;
}
