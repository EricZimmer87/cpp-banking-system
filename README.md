# C++ Banking System Simulator

This is a command-line banking system written in C++ that manages multiple customer accounts. It was originally developed as a school assignment for a C++ programming course, but I went the extra mile to simulate a real-world scenario with user input validation, interest application, account number generation, and more.

## Features

- Manages up to 10 bank accounts
- Automatically assigns unique account numbers
- Collects customer name, account type, balance, and interest rate
- Validates all user input (e.g., non-empty names, numeric fields, valid interest rate range)
- Supports:
  - Deposits
  - Withdrawals (with insufficient funds protection)
  - Interest application
- Cleanly displays all account information
- Modular design with helper functions and class encapsulation

## Concepts Demonstrated

- Object-Oriented Programming (OOP)
  - Class encapsulation
  - Static members (nextAccountNumber)
- Procedural input/output handling
- Input validation with cin fail-state checking
- Array usage to manage multiple objects
- Modular code organization

## How It Works

1. The user is prompted to enter details for 10 different bank accounts.
2. Each account is created with an auto-assigned account number.
3. A deposit is made to the first account, a withdrawal attempt is made from the second.
4. Interest is applied to both the first and second account.
5. All account information is displayed before and after modifications.

### Sample Output (trimmed for brevity):

Enter account holder's name for account 1: John Smith
Enter account type for account 1: Savings
Enter account balance: 1000
Enter interest rate (as a decimal between 0 and 1): 0.03

Stored John Smith's Savings account with a balance of $1000 and an interest rate of 0.03.

...

Account 1
Account holder's name: John Smith
Account number: 100000
Account type: Savings
Account balance: $1000.00
Account interest rate: 0.03

...

Depositing $50 into John Smith's account...

Withdrawing $100 from Jane Doe's account...
Withdrawal successful.

Applying interest to John Smith's and Jane Doe's accounts...

Updated account information for John Smith's and Jane Doe's accounts:
Account holder's name: John Smith
Account number: 100000
Account type: Savings
Account balance: $1081.50
Account interest rate: 0.03

...
