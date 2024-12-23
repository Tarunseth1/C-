
#include <iostream>
#include <string>
using namespace std;


struct Seat {
    bool isBooked;
    Seat() : isBooked(false) {} 
};


struct Compartment {
    int compID;
    Seat* seats;
    int numSeats;
    Compartment* next;

    Compartment(int id, int seatCount) : compID(id), numSeats(seatCount), next(nullptr) {
        seats = new Seat[seatCount];  
    }

    ~Compartment() {
        delete[] seats;  
    }

  
    bool checkAvailability(int seatNumber) {
        if (seatNumber < 0 || seatNumber >= numSeats) {
            cout << "Invalid seat number!" << endl;
            return false;
        }
        return !seats[seatNumber].isBooked;
    }

    bool bookSeat(int seatNumber) {
        if (checkAvailability(seatNumber)) {
            seats[seatNumber].isBooked = true;
            cout << "Seat " << seatNumber << " successfully booked!" << endl;
            return true;
        }
        cout << "Seat " << seatNumber << " is already booked." << endl;
        return false;
    }

   
    bool cancelSeat(int seatNumber) {
        if (seatNumber < 0 || seatNumber >= numSeats) {
            cout << "Invalid seat number!" << endl;
            return false;
        }
        if (!seats[seatNumber].isBooked) {
            cout << "Seat " << seatNumber << " is not booked." << endl;
            return false;
        }
        seats[seatNumber].isBooked = false;
        cout << "Booking for seat " << seatNumber << " canceled!" << endl;
        return true;
    }

   
    void printCompartment() {
        cout << "Compartment ID: " << compID << "\nSeats: ";
        for (int i = 0; i < numSeats; i++) {
            cout << (seats[i].isBooked ? "Booked " : "Available ") << " ";
        }
        cout << endl;
    }
};


struct Train {
    int trainID;
    string trainName;
    Compartment* compartments;

    Train(int id, string name) : trainID(id), trainName(name), compartments(nullptr) {}

 
    void addCompartment(int compID, int numSeats) {
        Compartment* newCompartment = new Compartment(compID, numSeats);
        newCompartment->next = compartments;
        compartments = newCompartment;
    }

   
    Compartment* findCompartment(int compID) {
        Compartment* temp = compartments;
        while (temp) {
            if (temp->compID == compID) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; 
    }

   
    void displayTrainInfo() {
        cout << "Train ID: " << trainID << ", Train Name: " << trainName << endl;
        Compartment* temp = compartments;
        while (temp) {
            temp->printCompartment();
            temp = temp->next;
        }
    }
};

int main() {
    Train train1(101, "Express Train");

   
    train1.addCompartment(1, 5);  
    train1.addCompartment(2, 4);  

    
    train1.displayTrainInfo();

   
    Compartment* comp = train1.findCompartment(1);
    if (comp) {
        comp->bookSeat(2);  
    }

    
    if (comp) {
        comp->bookSeat(2);  
    }

   
    if (comp) {
        comp->cancelSeat(2);  
    }

   
    train1.displayTrainInfo();

  
    if (comp) {
        if (comp->checkAvailability(2)) {
            cout << "Seat 2 is available for booking." << endl;
        } else {
            cout << "Seat 2 is not available." << endl;
        }
    }

    return 0;
}