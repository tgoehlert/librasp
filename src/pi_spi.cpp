/*
 *
 */

#include "pi_spidevice.hpp"
#include <stdexcept>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace RaspberryPi;

SPIDevice* SPIDevice::_channel0 = new SPIDevice("/dev/spidev0.0");
SPIDevice* SPIDevice::_channel1 = new SPIDevice("/dev/spidev0.1");


SPIDevice* SPIDevice::Channel0()
{
    if(_channel0 == NULL) _channel0 = new SPIDevice("/dev/spidev0.0");
        return _channel0;         
}

SPIDevice* SPIDevice::Channel1()
{
    if(_channel1 == NULL) _channel1 = new SPIDevice("/dev/spidev0.1");
        return _channel1; 
}

SPIDevice::SPIDevice()
{
    this->m_mode        = SPI_DEFAULT_MODE;
    this->m_maxspeed    = SPI_DEFAULT_MAX_SPEED;
    this->m_bitsperword = SPI_DEFAULT_BITS_WORD;
    this->m_isopen      = false;
}

SPIDevice::SPIDevice(string device)
{
    this->m_mode        = SPI_DEFAULT_MODE;
    this->m_maxspeed    = SPI_DEFAULT_MAX_SPEED;
    this->m_bitsperword = SPI_DEFAULT_BITS_WORD;
    this->m_device      = device;
    this->m_isopen      = false;
}

SPIDevice::~SPIDevice()
{

}

int SPIDevice::Open()
{
    if((this->m_fd = open(this->m_device.c_str(), O_RDWR)) < 0){
        throw std::runtime_error("could not open SPI device");
    }
    
    if (ioctl (this->m_fd, SPI_IOC_WR_MODE, &this->m_mode) < 0) 
        throw std::runtime_error("could not set SPI mode");

    if (ioctl (this->m_fd, SPI_IOC_WR_BITS_PER_WORD, &this->m_bitsperword) < 0) 
        throw std::runtime_error("corrupt bits per word value");

    if (ioctl (this->m_fd, SPI_IOC_WR_MAX_SPEED_HZ, &this->m_maxspeed) < 0) 
        throw std::runtime_error("could not set maximal speed");

    this->m_isopen = true;    
    return 0;
}


int SPIDevice::Open(string device)
{
    this->m_device = device;
    this->Open();
}

int SPIDevice::Open(string device, SpiMode_t mode, int bits_per_word, long max_speed)
{
    this->m_device = device;
    this->m_mode   = mode;
    this->m_bitsperword = bits_per_word;
    this->m_maxspeed = max_speed;
    this->Open();
}

int SPIDevice::Close()
{
    close(this->m_fd);
    this->m_fd = 0;
    this->m_isopen = false;
}

int SPIDevice::Speed()
{
    return this->m_maxspeed;
}

int SPIDevice::Speed(long new_speed)
{
    if(this->m_isopen){
        if (ioctl (this->m_fd, SPI_IOC_WR_MAX_SPEED_HZ, this->m_maxspeed) < 0) 
            throw std::runtime_error("could not set maximal speed");      
    }

    return (this->m_maxspeed = new_speed);
}

int SPIDevice::_transfer(char* buff_wr, int len, int usec)
{
    struct spi_ioc_transfer spi_s;
    spi_s.tx_buf = (unsigned long)buff_wr;
    spi_s.rx_buf = (unsigned long)buff_wr;
    spi_s.len    = len;
    
    if(ioctl(this->m_fd, SPI_IOC_MESSAGE(1), &spi_s) < 0){
        throw std::runtime_error("error during transfer");
    }
 
}

string SPIDevice::Transfer(string data, int delay_usec)
{
    char* buff_wr = new char[data.length()+1];
    if(buff_wr == NULL){
        throw std::runtime_error("can't allocate enough memory.");
    }
    
    this->_transfer(buff_wr,data.length(),delay_usec);

    data.copy(buff_wr, data.length());
    string ret_str = string(buff_wr);
    delete(buff_wr);
    return ret_str;
}

int SPIDevice::Transfer(int data, int usec)
{
   int buff_wr = data;
   this->_transfer((char*)&buff_wr,sizeof(int),usec);
   return buff_wr;
}

long SPIDevice::Transfer(long data, int usec)
{
   long buff_wr = data;
   this->_transfer((char*)&buff_wr,sizeof(long),usec);
   return buff_wr;
}

char SPIDevice::Transfer(char data, int delay_usec)
{
    char buff_wr = data;
    _transfer(&buff_wr,1,delay_usec);
    return buff_wr;
}
