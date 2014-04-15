#include "wiegandinterface.hpp"

#include <cstring>
#include <iostream> // FIXME Debug printing
#include <iomanip> // FIXME Debug printing

WiegandInterface::WiegandInterface()
:   _bitIdx(0)
{
    _hiGpio = 15; // FIXME Debug
    _loGpio = 18; // FIXME Debug
}

WiegandInterface::~WiegandInterface() {}

WiegandInterface::WiegandInterface(const WiegandInterface& /*other*/) {}

WiegandInterface& WiegandInterface::operator=(const WiegandInterface& /*other*/)
{
    return (*this);
}

void WiegandInterface::notify(int gpioNo)
{
    if (_bitIdx == DataBufferLen * 8) // Buffer overflow
        reset();

    if (gpioNo == _hiGpio)
       _buffer[_bitIdx / 8] |= 1 << (8 - _bitIdx % 8);
    ++_bitIdx;
}

void WiegandInterface::timeout()
{
    if (_bitIdx)
    {
        // TODO send message
        std::cout << "Read:";
        for (int i = DataBufferLen; i >= 0; --i)
            std::cout << std::hex << _buffer[i] << ' ';
        std::cout << std::endl;
        reset();
    }
}

void WiegandInterface::reset()
{
    ::memset(_buffer, 0, DataBufferLen);
    _bitIdx = 0;
}