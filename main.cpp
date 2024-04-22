/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <iostream>
/*
 copied UDT 1:
 */

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

        void updateFlightPlan(const std::string& newFlightPlan);
        void changeAltitude(float newAltitude);
        void activateAutoPilot();
        void autoCorrectCourse(float targetLatitude, float targetLongitude);
    };

    Cockpit();
    void navigateAirplane();
    void communicateWithATC(const std::string& message);
    void monitorSystems();
    void importNavigationSettings(NavigationSystem backupNavigationSystem);
    void performDiagnosticOnSystem(NavigationSystem systemToCheck);
    void simulateFlight(int hours);

    NavigationSystem navigationSystem;
};

Cockpit::NavigationSystem::NavigationSystem()
{
    std::cout << "Constructing NavigationSystem\n";
}

void Cockpit::NavigationSystem::updateFlightPlan(const std::string& newFlightPlan)
{
    currentFlightPlan = newFlightPlan;
    std::cout << "Updated flight plan to " << newFlightPlan << "\n";
}

void Cockpit::NavigationSystem::changeAltitude(float newAltitude)
{
    altitude = newAltitude;
    std::cout << "Changed altitude to " << newAltitude << "\n";
}

void Cockpit::NavigationSystem::activateAutoPilot()
{
    hasAutoPilotCapability = true;
    std::cout << "Autopilot activated\n";
}

void Cockpit::NavigationSystem::autoCorrectCourse(float targetLatitude, float targetLongitude)
{
    std::cout << "Starting auto-correction for course...\n";
    const float threshold = 0.1f;
    while (std::abs(gpsLatitude - targetLatitude) > threshold || std::abs(gpsLongitude - targetLongitude) > threshold)
    {
        if (gpsLatitude < targetLatitude)
        {
            gpsLatitude += 0.05f;
        }
        else if (gpsLatitude > targetLatitude)
        {
            gpsLatitude -= 0.05f;
        }

        if (gpsLongitude < targetLongitude)
        {
            gpsLongitude += 0.05f;
        }
        else if (gpsLongitude > targetLongitude)
        {
            gpsLongitude -= 0.05f;
        }

        std::cout << "Correcting to Latitude: " << gpsLatitude << ", Longitude: " << gpsLongitude << "\n";

        if (std::abs(gpsLatitude - targetLatitude) <= threshold && std::abs(gpsLongitude - targetLongitude) <= threshold)
        {
            std::cout << "Course corrected to within acceptable thresholds.\n";
            break;
        }
    }
}

Cockpit::Cockpit()
{
    std::cout << "Constructing Cockpit\n";
}

void Cockpit::navigateAirplane()
{
    std::cout << "Navigating airplane with autopilot system type: " << autopilotSystemType << "\n";
}

void Cockpit::communicateWithATC(const std::string& message)
{
    std::cout << "Communicating with ATC: " << message << "\n";
}

void Cockpit::monitorSystems()
{
    std::cout << "Monitoring airplane systems\n";
}

void Cockpit::importNavigationSettings(Cockpit::NavigationSystem backupNavigationSystem)
{
    navigationSystem = backupNavigationSystem;
    std::cout << "Imported navigation settings from backup\n";
}

void Cockpit::performDiagnosticOnSystem(Cockpit::NavigationSystem systemToCheck)
{
    std::cout << "Performing diagnostic check on navigation system.\n";
    const float epsilon = 0.001f;
    if (std::abs(navigationSystem.altitude - systemToCheck.altitude) > epsilon)
    {
        std::cout << "Altitude discrepancy detected. Current: " << navigationSystem.altitude
                  << ", Checked: " << systemToCheck.altitude << "\n";
    }
    if (navigationSystem.hasAutoPilotCapability != systemToCheck.hasAutoPilotCapability)
    {
        std::cout << "Autopilot capability mismatch. Current: "
                  << (navigationSystem.hasAutoPilotCapability ? "Enabled" : "Disabled")
                  << ", Checked: " << (systemToCheck.hasAutoPilotCapability ? "Enabled" : "Disabled") << "\n";
    }
}

void Cockpit::simulateFlight(int hours)
{
    for (int hour = 1; hour <= hours; ++hour)
    {
        navigationSystem.changeAltitude(navigationSystem.altitude + 500.0f);
        std::cout << "Hour " << hour << ": Altitude adjusted to " << navigationSystem.altitude << " feet.\n";
        if (navigationSystem.altitude >= 15000.0f)
        {
            std::cout << "Cruising altitude reached.\n";
            break;
        }
    }
}

/*
 copied UDT 2:
 */

struct SmartThermostat
{
    float currentRoomTemperature {20.0f};
    float desiredTemperature;
    float energyConsumptionKWh {3.5f};
    std::string mode {"Auto"};
    bool isWifiConnected;

    SmartThermostat(float initDesiredTemperature = 22.0f, bool initWifiConnected = true);

    void adjustTemperature(float newTemperature);
    void switchMode(const std::string& newMode);
    float sendEnergyUsageReport();
    void simulateDayPassing();
};

SmartThermostat::SmartThermostat(float initDesiredTemperature, bool initWifiConnected) 
: desiredTemperature(initDesiredTemperature), isWifiConnected(initWifiConnected)
{
    std::cout << "Constructing SmartThermostat\n";
}

void SmartThermostat::adjustTemperature(float newTemperature) 
{
    desiredTemperature = newTemperature;
    std::cout << "Adjusted desired temperature to " << newTemperature << "\n";
}

void SmartThermostat::switchMode(const std::string& newMode)
{
    mode = newMode;
    std::cout << "Switched mode to " << newMode << "\n";
}

float SmartThermostat::sendEnergyUsageReport()
{
    std::cout << "Sending energy usage report. Total consumption: " << energyConsumptionKWh << " kWh\n";
    return energyConsumptionKWh;
}

void SmartThermostat::simulateDayPassing()
{
    for (int day = 1; day <= 7; ++day)
    {
        currentRoomTemperature += 0.5f; // simulate temperature rise
        std::cout << "Day " << day << ": Room temperature is now " << currentRoomTemperature << "°C\n";
        if (currentRoomTemperature >= desiredTemperature)
        {
            std::cout << "Desired temperature reached or exceeded.\n";
            break;
        }
    }
}

/*
 copied UDT 3:
 */

struct LibraryAccount
{
    int booksCheckedOut {0};
    int totalBooksAllowed;
    double fineAmountDue {0.0};
    std::string accountStatus {"active"};
    int daysUntilReturnDue;

    LibraryAccount(int allowed = 10, int daysUntilDue = 14);

    void checkOutBooks(int numberOfBooks);
    void payFines(double amount);
    void renewBooks();
    void simulateBookCheckouts();
};

LibraryAccount::LibraryAccount(int allowed, int daysUntilDue)
: totalBooksAllowed(allowed), daysUntilReturnDue(daysUntilDue)
{
    std::cout << "Constructing LibraryAccount\n";
}

void LibraryAccount::checkOutBooks(int numberOfBooks)
{
    booksCheckedOut += numberOfBooks;
    std::cout << "Checked out " << numberOfBooks << " books. Total checked out: " << booksCheckedOut << "\n";
}

void LibraryAccount::payFines(double amount)
{
    fineAmountDue -= amount;
    std::cout << "Paid fine. Remaining fine amount: $" << fineAmountDue << "\n";
}

void LibraryAccount::renewBooks()
{
    std::cout << "Books renewed. No fines due\n";
}

void LibraryAccount::simulateBookCheckouts()
{
    int days = 0;
    while (booksCheckedOut < totalBooksAllowed)
    {
        ++booksCheckedOut;
        ++days;
        std::cout << "Checked out one more book, total: " << booksCheckedOut << "\n";
        if (booksCheckedOut == totalBooksAllowed)
        {
            std::cout << "Reached max books allowed after " << days << " days.\n";
            break;
        }
    }
}

/*
 new UDT 4:
 with 2 member functions
 */

/*
 new UDT 5:
 with 2 member functions
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
