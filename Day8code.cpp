#include <iostream>
using namespace std;

class Employee
{
public:
    int employeeId;
    string name;
    double basicSalary;

    Employee(int id, string n, double salary)
    {
        employeeId = id;
        name = n;
        basicSalary = salary;
    }

    virtual void calculateSalary() = 0; // Pure virtual function

    friend void display(Employee &E);
};

void display(Employee &E) // Definition of the friend function
{
    cout << "ID: " << E.employeeId << endl;
    cout << "Name: " << E.name << endl;
    cout << "Base salary: " << E.basicSalary << endl;
}

class Manager : public Employee
{
public:
    Manager(int id, string n, double salary) : Employee(id, n, salary) {}

    void calculateSalary() override // Overriding calculateSalary for Manager
    {
        double bonus;
        cout << "Enter the bonus amount for manager: ";
        cin >> bonus;
        basicSalary += bonus;
        cout << "After bonus, the salary is: " << basicSalary << endl;
    }

    friend void display(Manager &M);
};

void display(Manager &M)
{
    cout << "Manager Details:" << endl;
    cout << "ID: " << M.employeeId << endl;
    cout << "Name: " << M.name << endl;
    cout << "Base salary: " << M.basicSalary << endl;
}

class Developer : public Employee
{
public:
    Developer(int id, string n, double salary) : Employee(id, n, salary) {}

    void calculateSalary() override
    {
        double projectIncentive;
        cout << "Enter the project incentive for developer: ";
        cin >> projectIncentive;
        basicSalary += projectIncentive;
        cout << "After project incentive, the salary is: " << basicSalary << endl;
    }

    friend void display(Developer &D);
};

void display(Developer &D)
{
    cout << "Developer Details:" << endl;
    cout << "ID: " << D.employeeId << endl;
    cout << "Name: " << D.name << endl;
    cout << "Base salary: " << D.basicSalary << endl;
}

int main()
{
    Manager m(101, "Tanu", 10000);
    m.calculateSalary();
    display(m);

    cout << endl;

    Developer d(102, "Raj", 8000);
    d.calculateSalary();
    display(d);

    return 0;
}
