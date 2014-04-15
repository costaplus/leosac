#ifndef WIEGANDINTERFACE_HPP
#define WIEGANDINTERFACE_HPP

#include <map>

#include "gpio/igpiolistener.hpp"
#include "tools/bufferutils.hpp"

/* NOTE This class is very likely to be created by the main thread,
 * but controlled by the polling thread
 */

class WiegandInterface : public IGPIOListener
{
    static const int    DataBufferLen = 64;
public:
    WiegandInterface();
    ~WiegandInterface();

private:
    WiegandInterface(const WiegandInterface& other);
    WiegandInterface& operator=(const WiegandInterface& other);

public:
    void    notify(int gpioNo);
    void    timeout();

private:
    void    reset();

public:
    Byte        _buffer[DataBufferLen];
    std::size_t _bitIdx;
    int         _hiGpio;
    int         _loGpio;
};

#endif // WIEGANDINTERFACE_HPP