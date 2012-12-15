/*  libraspberry I2C implementation
 *
 *  !!UNFINISHED!!
 *
 */

#include "pi_i2c.hpp"
#include <stdexcept>

#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace RaspberryPi;

I2CDevice* I2CDevice::_channel0 = new I2CDevice("/dev/i2c-0");
I2CDevice* I2CDevice::_channel1 = new I2CDevice("/dev/i2c-1");

I2CDevice* I2CDevice::Channel0()
{
    if(_channel0 == NULL) _channel0 = new I2CDevice("/dev/i2c-0");
        return _channel0;         
}

I2CDevice* I2CDevice::Channel1()
{
    if(_channel1 == NULL) _channel1 = new I2CDevice("/dev/i2c-1");
        return _channel1; 
}

I2CDevice::I2CDevice()
{
    this->m_isopen = false;
}

I2CDevice::I2CDevice(string device)
{
    this->m_device      = device;
    this->m_isopen      = false;
}

I2CDevice::~I2CDevice()
{
    this->Close();
}


int I2CDevice::Open()
{
    if((this->m_fd = open(this->m_device.c_str(), O_RDWR)) < 0){
        throw std::runtime_error("could not open I2C device");
    }
    
    if (ioctl (this->m_fd, I2C_SLAVE, this->m_slave_address) < 0) 
        throw std::runtime_error("could not set I2C slave address");

    this->m_isopen = true;    
    return 0;
}

int I2CDevice::Open(string device, u16 slave_address)
{
    this->m_slave_address = slave_address;
    this->m_device = device;
    return this->Open();
}

int I2CDevice::Open(string device)
{
    this->m_device = device;
    return this->Open();
}

int I2CDevice::Close()
{
    close(this->m_fd);
    this->m_fd = 0;
    this->m_isopen = false;
    return 0;
}

u16 I2CDevice::SlaveAddress()
{
    return this->m_slave_address;
}

u16 I2CDevice::SlaveAddress(u16 addr)
{
    if(this->m_isopen){
        if (ioctl (this->m_fd, I2C_SLAVE, addr) < 0) 
            throw std::runtime_error("could not set slave address");      
    }

    return (this->m_slave_address = addr);
}

u8 I2CDevice::Read()
{
    u8 recvbuff = 0x00;
    if(read(this->m_fd,(void*)&recvbuff,1) != 1)
        throw std::runtime_error("error receiving byte");
    return recvbuff;
}

int I2CDevice::Read(u8* recvbuff,int len)
{
    int len_returned = 0;
    if(recvbuff == NULL)
        throw std::runtime_error("buffer is null");
    if((len_returned = read(this->m_fd,(void*)&recvbuff,len)) != len)
        throw std::runtime_error("error receiving buffer");  

    return len_returned;
}

int I2CDevice::Write(u8 buff,u8 command)
{
    u8 tmp_buff[3] = {(this->m_slave_address & 0xFF),
                      (this->m_slave_address >> 8) & 0xFF,
                      command};

    int result = write(this->m_fd, &tmp_buff, 3);
    if(result < 0)
        throw std::runtime_error("error sending byte");

    return result;
}

int I2CDevice::Write(u8 *buff,int len, u8 command)
{
   //TODO: needs to be implemented
   return 0;
}
