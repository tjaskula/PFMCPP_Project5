#include "FlightControlSystem.h"

FlightControlSystem::FlightControlSystem()
{
    std::cout << "Constructing FlightControlSystem\n";
}

FlightControlSystem::~FlightControlSystem()
{
    std::cout << "Destructing FlightControlSystem\n";
    this->cockpit.simulateFlight(5);  // calling a member function during destruction for some cleanup logic
}

void FlightControlSystem::prepareForFlight(const std::string& flightPlan)
{
    this->cockpit.navigationSystem.updateFlightPlan(flightPlan);
    std::cout << "Flight plan prepared: " << flightPlan << "\n";
}

void FlightControlSystem::startAutoPilot()
{
    this->cockpit.navigationSystem.activateAutoPilot();
    std::cout << "Autopilot started\n";
}
