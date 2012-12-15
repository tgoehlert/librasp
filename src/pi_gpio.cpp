/*  libraspberry GPIO
 *
 *  !!UNFINISHED!!
 *
 */

#include "pi_gpio.hpp"
#include <stdexcept>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace RaspberryPi;

vector<IOPin> PinList::_pinvec_r1 = vector<IOPin>(17);
vector<IOPin> PinList::_pinvec_r2 = vector<IOPin>(21);

// TODO: add support for revision 1
int PinList::Setup()
{
    _pinvec_r2.push_back(IOPin(17));
    _pinvec_r2.push_back(IOPin(18));
    _pinvec_r2.push_back(IOPin(27));
    _pinvec_r2.push_back(IOPin(22));
    _pinvec_r2.push_back(IOPin(23));
    _pinvec_r2.push_back(IOPin(24));
    _pinvec_r2.push_back(IOPin(25));
    _pinvec_r2.push_back(IOPin(4));
    _pinvec_r2.push_back(IOPin(28));
    _pinvec_r2.push_back(IOPin(29));
    _pinvec_r2.push_back(IOPin(30));
    _pinvec_r2.push_back(IOPin(31));
    return 0;
}

IOPin* PinList::Pin(u8 number){
    if(number >= _pinvec_r2.size()){
        return NULL;
    }else{
        return _pinvec_r2[number];
    }
}

IOPin::IOPin()
{}

IOPin::~IOPin()
{}

IOPin::IOPin(u8 number)
{
    this->m_pin_nr = number;
}
