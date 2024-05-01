#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct SmartThermostat
{
    float currentRoomTemperature {20.0f};
    float desiredTemperature;
    float energyConsumptionKWh {3.5f};
    std::string mode {"Auto"};
    bool isWifiConnected;

    SmartThermostat(float initDesiredTemperature = 22.0f, bool initWifiConnected = true);
    ~SmartThermostat();

    void adjustTemperature(float newTemperature);
    void switchMode(const std::string& newMode);
    float sendEnergyUsageReport() const;
    void simulateDayPassing();

    JUCE_LEAK_DETECTOR(SmartThermostat)
};
