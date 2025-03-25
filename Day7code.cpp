#include <iostream>
using namespace std;

class Account
{
protected:
    int accountNumber;
    string holderName;
    double balance = 10000;

public:
    Account(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit successful!\nNew balance = " << balance << endl;
    }

    virtual void withdraw(double wd)
    {
        balance -= wd;
        cout << "Withdraw Successful!\nNew Balance = " << balance << endl;
    }

    void display()
    {
        cout << "Account number: " << accountNumber << endl;
        cout << "Holder name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingAccount : public Account
{
protected:
    int interestRate;

public:
    SavingAccount(int accNo, string name, double bal, int interest)
        : Account(accNo, name, bal)
    {
        interestRate = interest;
    }

    void interest()
    {
        double afterInterest = (balance * interestRate) / 100;
        balance += afterInterest;
        cout << "After interest, the balance is " << balance << endl;
    }

    void withdraw(double wd) override
    {
        balance -= wd;
        cout << "Withdraw Successful!\nNew Balance = " << balance << endl;
    }
};

class CurrentAccount : public Account
{
protected:
    int minValue;

public:
    CurrentAccount(int accNo, string name, double bal, int min)
        : Account(accNo, name, bal)  
    {
        minValue = min;
    }

    void withdraw(double wd)
    {
        if (balance - wd < minValue)
        {
            cout << "You cannot withdraw the amount as it would go below the minimum balance.\n";
        }
        else
        {
            balance -= wd;
            cout << "Withdraw Successful!\nNew Balance = " << balance << endl;
        }
    }
};

int main()
{
    SavingAccount s(101, "dhanu", 10000, 5);
    s.display();
    s.interest();
    s.deposit(5000);
    s.withdraw(300);
    cout<<endl<<endl;

    CurrentAccount c(102, "soham", 2300, 1300);
    c.display();
    c.deposit(500);
    c.withdraw(7000);

    return 0;
}
