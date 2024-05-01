#include "SmartThermostat.h"

SmartThermostat::SmartThermostat(float initDesiredTemperature, bool initWifiConnected)
: desiredTemperature(initDesiredTemperature), isWifiConnected(initWifiConnected)
{
    std::cout << "Constructing SmartThermostat\n";
}

SmartThermostat::~SmartThermostat()
{
    std::cout << "Destructing SmartThermostat\n";
}

void SmartThermostat::adjustTemperature(float newTemperature)
{
    this->desiredTemperature = newTemperature;
    std::cout << "Adjusted desired temperature to " << newTemperature << "\n";
}

void SmartThermostat::switchMode(const std::string& newMode)
{
    this->mode = newMode;
    std::cout << "Switched mode to " << newMode << "\n";
}

float SmartThermostat::sendEnergyUsageReport() const
{
    std::cout << "Sending energy usage report. Total consumption: " << this->energyConsumptionKWh << " kWh\n";
    return this->energyConsumptionKWh;
}

void SmartThermostat::simulateDayPassing()
{
    for (int day = 1; day <= 7; ++day)
    {
        this->currentRoomTemperature += 0.5f; // simulate temperature rise
        std::cout << "Day " << day << ": Room temperature is now " << this->currentRoomTemperature << "°C\n";
        if (this->currentRoomTemperature >= this->desiredTemperature)
        {
            std::cout << "Desired temperature reached or exceeded.\n";
            break;
        }
    }
}
