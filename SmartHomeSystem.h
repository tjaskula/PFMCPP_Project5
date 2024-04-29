#pragma once

#include "SmartThermostat.h"
#include "LibraryAccount.h"

struct SmartHomeSystem
{
    SmartThermostat thermostat;
    LibraryAccount libraryAccount;

    SmartHomeSystem();
    ~SmartHomeSystem();
    

    void adjustTemperatureForReading();
    void checkOutBookForWeekend();

    JUCE_LEAK_DETECTOR(SmartHomeSystem)
};
