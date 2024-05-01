#include "LibraryAccount.h"

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

void LibraryAccount::renewBooks() const
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
