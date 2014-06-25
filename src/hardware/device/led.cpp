/**
 * \file led.cpp
 * \author Thibault Schueller <ryp.sqrt@gmail.com>
 * \brief Led class implementation
 */

#include "led.hpp"

#include <thread>

#include "hardware/device/gpio/gpio.hpp"
#include "exception/deviceexception.hpp"

Led::Led(const std::string& name, IGPIOProvider& gpioProvider)
:   AGpioDevice(name, gpioProvider)
{}

void Led::serialize(ptree& node)
{
    AGpioDevice::serialize(node);
}

void Led::deserialize(const ptree& node)
{
    AGpioDevice::deserialize(node);
}

void Led::blink()
{
    _gpio->setValue(true);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    _gpio->setValue(false);
}