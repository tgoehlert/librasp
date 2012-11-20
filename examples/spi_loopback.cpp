#include <iostream>
#include <exception>
#include "../src/pi_spi.hpp"

using namespace RaspberryPi;
using namespace std;

int main()
{
    try{
        SPIDevice::Channel0()->Open();

        cout << "transfer string \""  <<  SPIDevice::Channel0()->Transfer(string("hello world"),0) << "\"" << endl;
        cout << "transfer byte  " <<  hex << (int)SPIDevice::Channel0()->Transfer(0xF1,0) << endl;
        cout << "transfer int   " <<  dec << SPIDevice::Channel0()->Transfer(1024,0) << endl;

        SPIDevice::Channel0()->Close();
    }catch(std::exception& e){
        cout << "ERROR: " <<  e.what() << endl; 
    }
    return 0;
}

