#pragma once

#include "Cockpit.h"

struct FlightControlSystem
{
    Cockpit cockpit;

    FlightControlSystem();
    ~FlightControlSystem();

    void prepareForFlight(const std::string& flightPlan);
    void startAutoPilot();

    JUCE_LEAK_DETECTOR(FlightControlSystem)
};
