#include <iostream>
#include <vector>
#include <string>

class Flight {
public:
    Flight(const std::string& flightNumber, const std::string& source, const std::string& destination, int capacity)
        : flightNumber(flightNumber), source(source), destination(destination), capacity(capacity) {
        availableSeats = capacity;
    }

    bool bookSeat(int numSeats) {
        if (availableSeats >= numSeats) {
            availableSeats -= numSeats;
            return true;
        } else {
            return false;
        }
    }

    std::string getFlightNumber() const {
        return flightNumber;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    void display() const {
        std::cout << "Flight Number: " << flightNumber << std::endl;
        std::cout << "Source: " << source << std::endl;
        std::cout << "Destination: " << destination << std::endl;
        std::cout << "Available Seats: " << availableSeats << std::endl;
    }

private:
    std::string flightNumber;
    std::string source;
    std::string destination;
    int capacity;
    int availableSeats;
};

int main() {
    std::vector<Flight> flights;

    flights.push_back(Flight("AA101", "Delhi", "Mumbai", 94));
    flights.push_back(Flight("UA202", "Ranchi", "Chennai", 146));
    flights.push_back(Flight("DL303", "Delhi", "Dubai", 76));
    flights.push_back(Flight("VR101", "Bhubaneshwar", "Delhi", 56));

    int choice;
    std::string flightNumber;
    bool booked = false;  

    do {
        std::cout << "Welcome to CVRCE Airline Reservation System" << std::endl;
        std::cout << "How can we help you today! " << std::endl;
        std::cout << "1. Display available flights" << std::endl;
        std::cout << "2. Book a ticket" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Available Flights:" << std::endl;
                for (const Flight& flight : flights) {
                    flight.display();
                    std::cout << std::endl;
                }
                break;
            case 2:
                int numSeats;
                std::cout << "Enter the flight number: ";
                std::cin >> flightNumber;
                std::cout << "Enter the number of seats to book: ";
                std::cin >> numSeats;
                booked = false;  
                for (Flight& flight : flights) {
                    if (flight.getFlightNumber() == flightNumber) {
                        booked = flight.bookSeat(numSeats);
                        break;
                    }
                }
                if (booked) {
                    std::cout << "Ticket booked successfully!" << std::endl;
                } else {
                    std::cout << "Unable to book a ticket. Please check the flight number or seat availability." << std::endl;
                }
                break;
            case 3:
                std::cout << "Thank you for using the Airline Reservation System." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

