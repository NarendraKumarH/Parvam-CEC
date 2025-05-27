#include <iostream>

#include <string>

using namespace std;

// ======================= ABSTRACT CLASS ======================

class Booking {

public:

    string customerName;

    int seats;

    Booking(string name = "", int s = 1) : customerName(name), seats(s) {}

    

    // Pure virtual function

    virtual void bookTicket() = 0;

    // Virtual destructor

    virtual ~Booking() {}

};

// ======================= FLIGHT BOOKING ======================

class FlightBooking : public Booking {

public:

    FlightBooking(string name, int s) : Booking(name, s) {}

    void bookTicket() override {

        cout << "Flight ticket booked for " << customerName

             << " with " << seats << " seat(s)." << endl;

    }

};

// ======================= TRAIN BOOKING ======================

class TrainBooking : public Booking {

public:

    TrainBooking(string name, int s) : Booking(name, s) {}

    void bookTicket() override {

        cout << "Train ticket booked for " << customerName

             << " with " << seats << " seat(s)." << endl;

    }

};

// ======================= BUS BOOKING ======================

class BusBooking : public Booking {

public:

    BusBooking(string name, int s) : Booking(name, s) {}

    void bookTicket() override {

        cout << "Bus ticket booked for " << customerName

             << " with " << seats << " seat(s)." << endl;

    }

};

// ======================= FUNCTION OVERLOADING ======================

class BookingManager {

public:

    void confirmBooking(string name) {

        cout << "Booking confirmed for: " << name << endl;

    }

    void confirmBooking(string name, int seats) {

        cout << "Booking confirmed for: " << name << " with " << seats << " seat(s)." << endl;

    }

    void confirmBooking(string name, int seats, string date) {

        cout << "Booking confirmed for: " << name

             << " | Seats: " << seats

             << " | Date: " << date << endl;

    }

};

// ======================= OPERATOR OVERLOADING ======================

class GroupBooking {

public:

    int totalSeats;

    GroupBooking(int seats = 0) : totalSeats(seats) {}

    GroupBooking operator+(const GroupBooking& other) {

        return GroupBooking(this->totalSeats + other.totalSeats);

    }

    void display() {

        cout << "Total group seats booked: " << totalSeats << endl;

    }

};

// ======================= MAIN ======================

int main() {

    // Abstract Class & Run-time Polymorphism

    Booking* booking1 = new FlightBooking("Alice", 2);

    Booking* booking2 = new TrainBooking("Bob", 3);

    Booking* booking3 = new BusBooking("Charlie", 1);

    cout << "=== Runtime Polymorphism ===" << endl;

    booking1->bookTicket();

    booking2->bookTicket();

    booking3->bookTicket();

    // Function Overloading

    cout << "\n=== Function Overloading ===" << endl;

    BookingManager manager;

    manager.confirmBooking("David");

    manager.confirmBooking("Emma", 4);

    manager.confirmBooking("Frank", 5, "2025-06-01");

    // Operator Overloading

    cout << "\n=== Operator Overloading ===" << endl;

    GroupBooking group1(4);

    GroupBooking group2(6);

    GroupBooking totalGroup = group1 + group2;

    totalGroup.display();

    // Clean up

    delete booking1;

    delete booking2;

    delete booking3;

    return 0;

}