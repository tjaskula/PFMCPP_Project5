#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

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
    void renewBooks() const;
    void simulateBookCheckouts();

    JUCE_LEAK_DETECTOR(LibraryAccount)
};
