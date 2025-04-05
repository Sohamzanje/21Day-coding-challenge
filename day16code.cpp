#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string designation;
    double salary;

public:
    // Default Constructor
    Employee() : Employee(0, "Unknown", "Intern", 0.0) {
        // Default values for id, name, designation, and salary
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized Constructor (2 parameters)
    Employee(int id, string name) : Employee(id, name, "Intern", 0.0) {
        // Default designation = "Intern" and salary = 0.0
        cout << "Parameterized Constructor (2 parameters) Called" << endl;
    }

    // Parameterized Constructor (4 parameters)
    Employee(int id, string name, string designation, double salary) {
        this->id = id;
        this->name = name;
        this->designation = designation;
        this->salary = salary;
        cout << "Parameterized Constructor (4 parameters) Called" << endl;
    }

    void displayDetails() const {
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    cout << "Creating Employee 1 using Default Constructor:" << endl;
    Employee emp1;
    emp1.displayDetails();
    cout << endl;

    cout << "Creating Employee 2 using Parameterized Constructor (2 parameters):" << endl;
    Employee emp2(101, "Alice");
    emp2.displayDetails();
}
