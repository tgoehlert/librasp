/*
 * rpi_spidev.hpp
 *
 *      Created on: 13.11.2012
 *      Author: Tino Goehlert
 *      Company: Mechlab engineering
 */

#ifndef RPI_SPIDEV_HPP_
#define RPI_SPIDEV_HPP_

#include <string>
#include <linux/spi/spidev.h>

using namespace std;

namespace RaspberryPi
{

#define SPI_DEFAULT_MODE  		 SPI_MODE_0
#define SPI_DEFAULT_MAX_SPEED 	 1000000
#define SPI_DEFAULT_BITS_WORD	 8

	typedef enum __SpiMode_e
    {
		SpiMode0 = SPI_MODE_0,
		SpiMode1 = SPI_MODE_1,
		SpiMode2 = SPI_MODE_2,
		SpiMode3 = SPI_MODE_3
	}SpiMode_t;

	class SPIDevice
    {
	public:
        static SPIDevice* Channel0();
        static SPIDevice* Channel1();
        int Open();
        int Open(string device);
		int Open(string device,
		         SpiMode_t mode,
		         int bits_per_word,
		         long max_speed);
        int Close();
        int Speed();
        int Speed(long new_speed);
        int Mode();
        int Mode(int new_mode);
        string Transfer(string data, int usec);
        char   Transfer(char data, int usec);
        char*  Transfer(char* data, int usec);
        int    Transfer(int data, int usec);
        long   Transfer(long data, int usec);
	protected:
        SPIDevice(string device);
		SPIDevice();
		~SPIDevice();
        static SPIDevice* _channel0;
        static SPIDevice* _channel1;
    private:
        int       _transfer(char* buff_wr, int len, int usec);
        int       m_fd;
		int       m_mode;
		int		  m_bitsperword;
		int		  m_maxspeed;
        string    m_device;
        bool      m_isopen;
	};
}

#endif /* RPI_SPIDEV_HPP_ */
