#include <iostream>
#include <exception>
#include "rpi_spidevice.hpp"

int main()
{
    try{
        RaspberryPi::SPIDevice::Channel0()->Open();
    }catch(std::exception& e){
        std::cout << e.what() << std::endl; 
    }
    return 0;
}
