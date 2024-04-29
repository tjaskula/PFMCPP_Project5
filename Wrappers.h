#pragma once

#include "FlightControlSystem.h"
#include "SmartHomeSystem.h"

struct WrapperCockpit
{
    WrapperCockpit(Cockpit* cockpitptr);
    ~WrapperCockpit();

    Cockpit* pointerToCockpit = nullptr;
};

struct WrapperNavigationSystem
{
    WrapperNavigationSystem(Cockpit::NavigationSystem* navsysptr);
    ~WrapperNavigationSystem();

    Cockpit::NavigationSystem* pointerToNavSys = nullptr;
};

struct WrapperSmartThermostat
{
    WrapperSmartThermostat(SmartThermostat* smartThptr);
    ~WrapperSmartThermostat();

    SmartThermostat* pointerToSmartTh = nullptr;
};

struct WrapperLibraryAccount
{
    WrapperLibraryAccount(LibraryAccount* libaccptr);
    ~WrapperLibraryAccount();

    LibraryAccount* pointerToLibAcc = nullptr;
};

struct WrapperFlightControlSystem
{
    WrapperFlightControlSystem(FlightControlSystem* flightCtrlSysptr);
    ~WrapperFlightControlSystem();

    FlightControlSystem* pointerToFlightCtrlSys = nullptr;
};

struct WrapperSmartHomeSystem
{
    WrapperSmartHomeSystem(SmartHomeSystem* smarthomesysptr);
    ~WrapperSmartHomeSystem();

    SmartHomeSystem* pointerToSmartHomeSys = nullptr;
};
