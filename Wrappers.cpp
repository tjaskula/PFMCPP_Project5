#include "Wrappers.h"
#include "SmartHomeSystem.h"
#include "FlightControlSystem.h"

WrapperCockpit::WrapperCockpit(Cockpit* cockpitptr) : pointerToCockpit(cockpitptr) {}
WrapperCockpit::~WrapperCockpit()
{
    delete pointerToCockpit;
}

WrapperNavigationSystem::WrapperNavigationSystem(Cockpit::NavigationSystem* navsysptr) : pointerToNavSys(navsysptr) {}
WrapperNavigationSystem::~WrapperNavigationSystem()
{
    delete pointerToNavSys;
}

WrapperSmartThermostat::WrapperSmartThermostat(SmartThermostat* smartThptr) : pointerToSmartTh(smartThptr) {}
WrapperSmartThermostat::~WrapperSmartThermostat()
{
    delete pointerToSmartTh;
}

WrapperLibraryAccount::WrapperLibraryAccount(LibraryAccount* libaccptr) : pointerToLibAcc(libaccptr) {}
WrapperLibraryAccount::~WrapperLibraryAccount()
{
    delete pointerToLibAcc;
}

WrapperFlightControlSystem::WrapperFlightControlSystem(FlightControlSystem* flightCtrlSysptr) :     pointerToFlightCtrlSys(flightCtrlSysptr) {}
WrapperFlightControlSystem::~WrapperFlightControlSystem()
{
    delete pointerToFlightCtrlSys;
}

WrapperSmartHomeSystem::WrapperSmartHomeSystem(SmartHomeSystem* smarthomesysptr) :     pointerToSmartHomeSys(smarthomesysptr) {}
WrapperSmartHomeSystem::~WrapperSmartHomeSystem()
{
    delete pointerToSmartHomeSys;
}
