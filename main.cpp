/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




/*

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
        ~NavigationSystem();

        void updateFlightPlan(const std::string& newFlightPlan);
        void changeAltitude(float newAltitude);
        void activateAutoPilot();
        void autoCorrectCourse(float targetLatitude, float targetLongitude);
    };

    Cockpit();
    ~Cockpit();
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
    this->navigationSystem = backupNavigationSystem;
    std::cout << "Imported navigation settings from backup\n";
}

void Cockpit::performDiagnosticOnSystem(Cockpit::NavigationSystem systemToCheck)
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
    ~SmartThermostat();

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

float SmartThermostat::sendEnergyUsageReport()
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
    ~LibraryAccount();

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

LibraryAccount::~LibraryAccount()
{
    std::cout << "Destructing LibraryAccount\n";
}

void LibraryAccount::checkOutBooks(int numberOfBooks)
{
    this->booksCheckedOut += numberOfBooks;
    std::cout << "Checked out " << numberOfBooks << " books. Total checked out: " << this->booksCheckedOut << "\n";
}

void LibraryAccount::payFines(double amount)
{
    this->fineAmountDue -= amount;
    std::cout << "Paid fine. Remaining fine amount: $" << this->fineAmountDue << "\n";
}

void LibraryAccount::renewBooks()
{
    std::cout << "Books renewed. No fines due\n";
}

void LibraryAccount::simulateBookCheckouts()
{
    int days = 0;
    while (this->booksCheckedOut < this->totalBooksAllowed)
    {
        ++this->booksCheckedOut;
        ++days;
        std::cout << "Checked out one more book, total: " << this->booksCheckedOut << "\n";
        if (this->booksCheckedOut == this->totalBooksAllowed)
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

struct FlightControlSystem
{
    Cockpit cockpit;

    FlightControlSystem()
    {
        std::cout << "Constructing FlightControlSystem\n";
    }

    ~FlightControlSystem()
    {
        std::cout << "Destructing FlightControlSystem\n";
        this->cockpit.simulateFlight(5);  // calling a member function during destruction for some cleanup logic
    }

    void prepareForFlight(const std::string& flightPlan)
    {
        this->cockpit.navigationSystem.updateFlightPlan(flightPlan);
        std::cout << "Flight plan prepared: " << flightPlan << "\n";
    }

    void startAutoPilot()
    {
        this->cockpit.navigationSystem.activateAutoPilot();
        std::cout << "Autopilot started\n";
    }
};

/*
 new UDT 5:
 with 2 member functions
 */
struct SmartHomeSystem
{
    SmartThermostat thermostat;
    LibraryAccount libraryAccount;

    SmartHomeSystem() 
    : thermostat(21.0f, true), libraryAccount(15, 30)
    {
        std::cout << "Constructing SmartHomeSystem\n";
    }

    ~SmartHomeSystem()
    {
        std::cout << "Destructing SmartHomeSystem\n";
        this->thermostat.adjustTemperature(19.0f);  // Lower the temperature upon system shutdown
    }

    void adjustTemperatureForReading()
    {
        this->thermostat.adjustTemperature(22.0f);  // Set a comfortable temperature for reading
        std::cout << "Adjusted temperature for optimal reading comfort\n";
    }

    void checkOutBookForWeekend()
    {
        this->libraryAccount.checkOutBooks(2);  // Assume checking out 2 books for the weekend
        std::cout << "Checked out books for a relaxing weekend\n";
    }
};
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
    SmartThermostat thermostat1, thermostat2;
    LibraryAccount libraryAccount1, libraryAccount2;
    Cockpit cockpit1, cockpit2;
    FlightControlSystem flightControlSystem1, flightControlSystem2;
    SmartHomeSystem smartHomeSystem1, smartHomeSystem2;

    // Call member functions
    thermostat1.adjustTemperature(25.0f);
    thermostat1.switchMode("Heat");
    thermostat2.sendEnergyUsageReport();
    thermostat2.simulateDayPassing();

    libraryAccount1.checkOutBooks(5);
    libraryAccount1.payFines(20.0);
    libraryAccount2.renewBooks();
    libraryAccount2.simulateBookCheckouts();

    cockpit1.navigateAirplane();
    cockpit1.communicateWithATC("Ascending to 15000 feet.");
    cockpit2.monitorSystems();
    cockpit2.simulateFlight(5);

    flightControlSystem1.prepareForFlight("Los Angeles");
    flightControlSystem1.startAutoPilot();
    flightControlSystem2.prepareForFlight("Paris");
    flightControlSystem2.startAutoPilot();

    smartHomeSystem1.adjustTemperatureForReading();
    smartHomeSystem1.checkOutBookForWeekend();
    smartHomeSystem2.adjustTemperatureForReading();
    smartHomeSystem2.checkOutBookForWeekend();

    std::cout << "Thermostat thermostat1.sendEnergyUsageReport: " <<  thermostat1.sendEnergyUsageReport() << " and thermostat1.currentRoomTemperature:" << thermostat1.currentRoomTemperature << std::endl;
    std::cout << "Library account books checked out: " << libraryAccount1.booksCheckedOut << std::endl;
    std::cout << "Cockpit current altitude: " << cockpit1.navigationSystem.altitude << " feet" << std::endl;
    std::cout << "Cockpit number of control panels: " << flightControlSystem1.cockpit.numberOfControlPanels << std::endl;
    std::cout << "Smart home system desired temperature: " << smartHomeSystem1.thermostat.desiredTemperature << std::endl;

    
    std::cout << "good to go!" << std::endl;
}
