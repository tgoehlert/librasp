/*
 * pi_i2cdevice.hpp
 *
 *      Created on: 13.11.2012
 *      Author: Tino Goehlert
 *      Company: Mechlab engineering
 */

#ifndef RPI_I2CDEV_HPP_
#define RPI_I2CDEV_HPP_

#include <string>
#include "types.h"

// importing the kernel space i2c functions



using namespace std;

namespace RaspberryPi
{

	class I2CDevice
    {
	public:
        static   I2CDevice* Channel0();
        static   I2CDevice* Channel1();
        int      Open();
        int      Open(string device, u16 slave_address);
        int      Open(string device);
        int      Close();
        u16      SlaveAddress();
        u16      SlaveAddress(u16 addr);
        u8       Read();
        int      Read(u8* recvbuff, int len);
        int      Write(u8 buff, u8 command);
        int      Write(u8* buff, int len, u8 command);
	protected:
        I2CDevice(string device);
		I2CDevice();
		~I2CDevice();
        static I2CDevice* _channel0;
        static I2CDevice* _channel1;
    private:
        int       m_fd;
        u16       m_slave_address;
        string    m_device;
        bool      m_isopen;
	};
}

#endif /* RPI_I2CDEV_HPP */
