#include "SmartHomeSystem.h"

SmartHomeSystem::SmartHomeSystem() 
: thermostat(21.0f, true), libraryAccount(15, 30)
{
    std::cout << "Constructing SmartHomeSystem\n";
}

SmartHomeSystem::~SmartHomeSystem()
{
    std::cout << "Destructing SmartHomeSystem\n";
    this->thermostat.adjustTemperature(19.0f);  // Lower the temperature upon system shutdown
}

void SmartHomeSystem::adjustTemperatureForReading()
{
    this->thermostat.adjustTemperature(22.0f);  // Set a comfortable temperature for reading
    std::cout << "Adjusted temperature for optimal reading comfort\n";
}

void SmartHomeSystem::checkOutBookForWeekend()
{
    this->libraryAccount.checkOutBooks(2);  // Assume checking out 2 books for the weekend
    std::cout << "Checked out books for a relaxing weekend\n";
}
