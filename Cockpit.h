#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct Cockpit
{
    int numberOfControlPanels {4};
    std::string autopilotSystemType {"Advanced"};
    bool visibilityThroughWindshield {true};
    int numberOfSeats {2};
    int amountOfEmergencyEquipment {5};

    struct NavigationSystem
    {
        float gpsLatitude {0.0f};
        float gpsLongitude {0.0f};
        bool hasAutoPilotCapability {true};
        std::string currentFlightPlan {"N/A"};
        float altitude {10000.0f};

        NavigationSystem();
        ~NavigationSystem();

        void updateFlightPlan(const std::string& newFlightPlan);
        void changeAltitude(float newAltitude);
        void activateAutoPilot();
        void autoCorrectCourse(float targetLatitude, float targetLongitude);

        JUCE_LEAK_DETECTOR(NavigationSystem)
    };

    Cockpit();
    ~Cockpit();
    void navigateAirplane();
    void communicateWithATC(const std::string& message) const;
    void monitorSystems() const;
    void importNavigationSettings(const NavigationSystem& backupNavigationSystem);
    void performDiagnosticOnSystem(const NavigationSystem& systemToCheck) const;
    void simulateFlight(int hours);

    NavigationSystem navigationSystem;

    JUCE_LEAK_DETECTOR(Cockpit)
};
