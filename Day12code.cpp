#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Train {
public:
    int trainNumber;
    string trainName;
    int availableSeats;
    float fare;

    Train(int number, string name, int seats, float fare) {
        trainNumber = number;
        trainName = name;
        availableSeats = seats;
        this->fare = fare;
    }

    void displayTrainDetails() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Available Seats: " << availableSeats << endl;
        cout << "Fare: $" << fare << endl;
    }

    bool bookTicket() {
        if (availableSeats > 0) {
            availableSeats--;
            return true;
        }
        return false;
    }

    void cancelTicket() {
        availableSeats++;
    }
};

class RailwayReservationSystem {
private:
    vector<Train> trains;

public:
    // Add a train to the system
    void addTrain(int number, string name, int seats, float fare) {
        trains.push_back(Train(number, name, seats, fare));
    }

    // View available trains
    void viewAvailableTrains() const {
        for (const Train& train : trains) {
            train.displayTrainDetails(); // Now works with const Train object
            cout << "--------------------------" << endl;
        }
    }

    // Book a ticket
    void bookTicket() {
        int trainNumber;
        cout << "Enter Train Number to Book: ";
        cin >> trainNumber;

        for (Train& train : trains) {
            if (train.trainNumber == trainNumber) {
                if (train.bookTicket()) {
                    cout << "Ticket booked successfully!" << endl;
                } else {
                    cout << "No available seats on this train!" << endl;
                }
                return;
            }
        }
        cout << "Invalid Train Number!" << endl;
    }

    // Cancel a ticket
    void cancelTicket() {
        int trainNumber;
        cout << "Enter Train Number to Cancel: ";
        cin >> trainNumber;

        for (Train& train : trains) {
            if (train.trainNumber == trainNumber) {
                train.cancelTicket();
                cout << "Ticket cancelled successfully!" << endl;
                return;
            }
        }
        cout << "Invalid Train Number!" << endl;
    }
};

int main() {
    RailwayReservationSystem system;

    system.addTrain(101, "Express 1", 10, 50.0);
    system.addTrain(102, "Express 2", 5, 40.0);
    system.addTrain(103, "Express 3", 8, 60.0);

    int choice;
    do {
        cout << "\nRailway Reservation System" << endl;
        cout << "1. View Available Trains" << endl;
        cout << "2. Book a Ticket" << endl;
        cout << "3. Cancel a Ticket" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.viewAvailableTrains();
                break;
            case 2:
                system.bookTicket();
                break;
            case 3:
                system.cancelTicket();
                break;
            case 4:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}