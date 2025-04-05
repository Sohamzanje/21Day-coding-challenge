#include <iostream>
#include <string>

using namespace std;

class InvalidAgeException {
public:
    const char* what() const {
        return "Invalid age entered. Age cannot be negative.";
    }
};

class NotEligibleToVoteException {
public:
    const char* what() const {
        return "Not eligible to vote";
    }
};

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    try {
        if (age < 0) {
            throw InvalidAgeException();
        }
        else if (age < 18) {
            throw NotEligibleToVoteException();
        }
        else {
            cout << "Eligible to vote" << endl;
        }
    }
    catch (const InvalidAgeException& e) {
        cout << e.what() << endl;
    }
    catch (const NotEligibleToVoteException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
