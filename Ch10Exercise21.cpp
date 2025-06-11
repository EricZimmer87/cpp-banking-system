/*
Student's Name: Eric Zimmer
Course:         CS310-T301 Programming with C++
Assignment:     M8: Assignment
Professor:      Dr. Robert Flowers
Date:           05/01/2025
File Name:      Ch10Exercise21.cpp
Description:    Defines a 'bankAccount' class to manage 10 customer accounts. Account number
is automatically assigned. Class is demonstrated with a program that gets account information
and uses the class's methods to deposit, withdraw, and apply interest rates.

Developed and tested in Visual Studio 2022 (Windows 11).
Compiled with Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810.
*/

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

using namespace std;

class bankAccount;
inline string trim(const string& s);
void getAccountsInfo(bankAccount accounts[]);
void printAllAccountsInfo(bankAccount accounts[]);

// Global variable for number of accounts. Must be >= 2 for deposit & withdrawal demonstration.
// Set to 10 to meet assignment requirements. Lower for faster testing.
constexpr int MAX_ACCOUNTS = 2;

class bankAccount {
private:
    // Attributes
    string name;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;
   
    static int nextAccountNumber; // Static class member

public:
    // Default constructor
    bankAccount() {
        name = "";
        accountNumber = 0;
        accountType = "";
        balance = 0.0;
        interestRate = 0.0;
    }

    // Constructor
    bankAccount(const string& name, const string& accountType, const double& balance, const double& interestRate) {
        this->name = name;
        this->accountNumber = nextAccountNumber++; // Increment the account number for each object
        this->accountType = accountType;
        this->balance = balance;
        this->interestRate = interestRate;
    }

    // Getters
    string getName() const {
        return name;
    }
    int getAccountNumber() const {
        return accountNumber;
    }
    string getAccountType() const {
        return accountType;
    }
    double getBalance() const {
        return balance;
    }
    double getInterestRate() const {
        return interestRate;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Withdrawal method
    bool withdrawal(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Apply interest
    void applyInterest() {
        balance *= (1 + interestRate);
    }

    // Print account info
    void print() const {
        cout << "Account holder's name: " << name << "\n"
            << "Account number: " << accountNumber << "\n"
            << "Account type: " << accountType << "\n"
            << fixed << setprecision(2) << "Account balance: $" << balance << "\n"
            << "Account interest rate: " << interestRate << endl;
    }
};

// First bank account number - increments by 1 hereafter
int bankAccount::nextAccountNumber = 100000;

int main() {
    // Get info for accounts and store in an array
    bankAccount accounts[MAX_ACCOUNTS];
    getAccountsInfo(accounts);

    // Print all account info
    printAllAccountsInfo(accounts);

    // Deposit $50 into the first account
    cout << "Depositing $50 into " << accounts[0].getName() << "'s account...\n" << endl;
    accounts[0].deposit(50.0);

    // Withdraw $100 from the second account
    cout << "Withdrawing $100 from " << accounts[1].getName() << "'s account..." << endl;
    if (!accounts[1].withdrawal(100.0)) {
        cout << "Withdrawal failed: Insufficient funds.\n" << endl;
    }
    else {
        cout << "Withdrawal successful.\n" << endl;
    }

    // Apply interest to first and second account
    cout << "Applying interest to " << accounts[0].getName() << "'s and " << accounts[1].getName() << "'s accounts...\n" << endl;
    accounts[0].applyInterest();
    accounts[1].applyInterest();
    
    // Print updated amounts for first and second accounts
    cout << "Updated account information for " << accounts[0].getName() << "'s and " << accounts[1].getName() << "'s accounts:" << endl;
    accounts[0].print();
    cout << endl;
    accounts[1].print();

    return 0;
}

inline string trim(const string& s) {
    /*
    This is a helper function that trims leading and trailing whitespace from a string.
    */
    // Whitespace includes: space, tab, carriage return, line feed, form feed, or vertical tab.
    const char* whitespace = " \t\n\r\f\v";
    size_t begin = s.find_first_not_of(whitespace);
    if (begin == string::npos) {
        return string{};
    }
    size_t end = s.find_last_not_of(whitespace);
    return string{ s.substr(begin, end - begin + 1) };
}

void getAccountsInfo(bankAccount accounts[]) {
    /*
    This function gets account information from the user for the set amount of accounts.
    */
    const int MAX_NAME_LENGTH = 50;
    const int MAX_TYPE_LENGTH = 20;
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        // Get account name
        string accountName = "";
        while (true) {
            // Print message
            cout << "Enter account holder's name for account " << i + 1 << ": ";

            // Get input
            getline(cin, accountName);

            // Trim leading and trailing whitespace
            accountName = trim(accountName);

            // Check for empty input
            if (accountName.empty()) {
                cout << "Invalid input: Empty string." << endl;
                continue;
            }

            // Name cannot be greater than set length
            if (accountName.size() > MAX_NAME_LENGTH) {
                cout << "Invalid input: Name is too long. Please limit the name's length to " << MAX_NAME_LENGTH << " characters." << endl;
                continue;
            }

            // Valid input
            break;
        }

        // Get account type
        string accountType = "";
        while (true) {
            // Print message
            cout << "Enter account type for account " << i + 1 << ": ";

            // Get input
            getline(cin, accountType);

            // Trim leading and trailing whitespace
            accountType = trim(accountType);

            // Check for empty input
            if (accountType.empty()) {
                cout << "Invalid input: Empty string." << endl;
                continue;
            }

            // Type cannot be greater than set length
            if (accountType.size() > MAX_TYPE_LENGTH) {
                cout << "Invalid input: Account type is too long. Please limit the account type's length to " << MAX_TYPE_LENGTH << " characters." << endl;
                continue;
            }

            // Valid input
            break;
        }

        // Get account balance
        double balance = 0.0;
        cout << "Enter account balance: ";
        while (!(cin >> balance)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a valid number." << endl;
        }

        // Get interest rate
        double interestRate = 0.0;
        cout << "Enter interest rate (as a decimal between 0 and 1): ";
        while (!(cin >> interestRate) || interestRate < 0 || interestRate > 1) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a valid number greater than 0 and less than 1." << endl;
        }
        // Clear cin contents
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Print blank line to separate accounts
        cout << "\n";

        accounts[i] = bankAccount(accountName, accountType, balance, interestRate);
        // Confirmation message
        cout << "Stored " << accountName << "'s " << accountType << " account with a balance of $"
            << balance << " and an interest rate of " << interestRate << ".\n" << endl;
    }
}

void printAllAccountsInfo(bankAccount accounts[]) {
    /*
    This function prints all the account info for all of the accounts.
    */
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        cout << "Account " << i + 1 << endl;
        accounts[i].print();
        cout << endl;
    }
}

