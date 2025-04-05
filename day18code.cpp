#include <iostream>
#include <string>

using namespace std;

class InsufficientFundsException {
public:
    const char* what() const {
        return "Insufficient funds for the withdrawal.";
    }
};

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, string accountHolderName, double initialBalance)
        : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
            cout << "Current balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be greater than zero." << endl;
        }
    }

    void withdraw(double amount) {
        try {
            if (amount > balance) {
                throw InsufficientFundsException();
            } else {
                balance -= amount;
                cout << "Withdrawal successful" << endl;
                cout << "Remaining balance: $" << balance << endl;
            }
        }
        catch (const InsufficientFundsException& e) {
            cout << e.what() << endl;
        }
    }

    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    // Create a bank account with an initial balance of $500
    BankAccount account(12345, "bhupendra jogi", 500.0);

    // Display initial account details
    account.displayAccountDetails();
    cout << endl;

    account.deposit(200.0);
    cout << endl;

    account.withdraw(600.0);  // Insufficient funds
    cout << endl;

    account.withdraw(300.0);  // Successful withdrawal
    cout << endl;

    account.displayAccountDetails();

    return 0;
}
