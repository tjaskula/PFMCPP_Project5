#include "Cockpit.h"

Cockpit::Cockpit()
{
    std::cout << "Constructing Cockpit\n";
}

Cockpit::~Cockpit()
{
    std::cout << "Destructing Cockpit\n";
}

void Cockpit::navigateAirplane()
{
    std::cout << "Navigating airplane with autopilot system type: " << this->autopilotSystemType << "\n";
}

void Cockpit::communicateWithATC(const std::string& message) const
{
    std::cout << "Communicating with ATC: " << message << "\n";
}

void Cockpit::monitorSystems() const
{
    std::cout << "Monitoring airplane systems\n";
}

void Cockpit::importNavigationSettings(const Cockpit::NavigationSystem& backupNavigationSystem)
{
    this->navigationSystem = backupNavigationSystem;
    std::cout << "Imported navigation settings from backup\n";
}

void Cockpit::performDiagnosticOnSystem(const Cockpit::NavigationSystem& systemToCheck) const
{
    std::cout << "Performing diagnostic check on navigation system.\n";
    const float epsilon = 0.001f;
    if (std::abs(this->navigationSystem.altitude - systemToCheck.altitude) > epsilon)
    {
        std::cout << "Altitude discrepancy detected. Current: " << this->navigationSystem.altitude
                  << ", Checked: " << systemToCheck.altitude << "\n";
    }
    if (this->navigationSystem.hasAutoPilotCapability != systemToCheck.hasAutoPilotCapability)
    {
        std::cout << "Autopilot capability mismatch. Current: "
                  << (this->navigationSystem.hasAutoPilotCapability ? "Enabled" : "Disabled")
                  << ", Checked: " << (systemToCheck.hasAutoPilotCapability ? "Enabled" : "Disabled") << "\n";
    }
}

void Cockpit::simulateFlight(int hours)
{
    for (int hour = 1; hour <= hours; ++hour)
    {
        navigationSystem.changeAltitude(this->navigationSystem.altitude + 500.0f);
        std::cout << "Hour " << hour << ": Altitude adjusted to " << this->navigationSystem.altitude << " feet.\n";
        if (this->navigationSystem.altitude >= 15000.0f)
        {
            std::cout << "Cruising altitude reached.\n";
            break;
        }
    }
}

Cockpit::NavigationSystem::NavigationSystem()
{
    std::cout << "Constructing NavigationSystem\n";
}

Cockpit::NavigationSystem::~NavigationSystem()
{
    std::cout << "Destructing NavigationSystem\n";
}

void Cockpit::NavigationSystem::updateFlightPlan(const std::string& newFlightPlan)
{
    this->currentFlightPlan = newFlightPlan;
    std::cout << "Updated flight plan to " << newFlightPlan << "\n";
}

void Cockpit::NavigationSystem::changeAltitude(float newAltitude)
{
    this->altitude = newAltitude;
    std::cout << "Changed altitude to " << newAltitude << "\n";
}

void Cockpit::NavigationSystem::activateAutoPilot()
{
    this->hasAutoPilotCapability = true;
    std::cout << "Autopilot activated\n";
}

void Cockpit::NavigationSystem::autoCorrectCourse(float targetLatitude, float targetLongitude)
{
    std::cout << "Starting auto-correction for course...\n";
    const float threshold = 0.1f;
    while (std::abs(this->gpsLatitude - targetLatitude) > threshold || std::abs(this->gpsLongitude - targetLongitude) > threshold)
    {
        if (this->gpsLatitude < targetLatitude)
        {
            this->gpsLatitude += 0.05f;
        }
        else if (this->gpsLatitude > targetLatitude)
        {
            this->gpsLatitude -= 0.05f;
        }

        if (this->gpsLongitude < targetLongitude)
        {
            this->gpsLongitude += 0.05f;
        }
        else if (this->gpsLongitude > targetLongitude)
        {
            this->gpsLongitude -= 0.05f;
        }

        std::cout << "Correcting to Latitude: " << this->gpsLatitude << ", Longitude: " << this->gpsLongitude << "\n";

        if (std::abs(this->gpsLatitude - targetLatitude) <= threshold && std::abs(this->gpsLongitude - targetLongitude) <= threshold)
        {
            std::cout << "Course corrected to within acceptable thresholds.\n";
            break;
        }
    }
}
