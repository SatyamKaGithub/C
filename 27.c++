// Write CLASS program to enter and display the detail of 3 customer in a restaurant with customer id, customer name, customer address, customer bill

#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    int customerId;
    string customerName;
    string customerAddress;
    double customerBill;

    void enterDetails() {
        cout << "Enter Customer ID: ";
        cin >> customerId;
        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, customerName);
        cout << "Enter Customer Address: ";
        getline(cin, customerAddress);
        cout << "Enter Customer Bill: ";
        cin >> customerBill;
    }

    void displayDetails() {
        cout << "Customer ID: " << customerId << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Customer Address: " << customerAddress << endl;
        cout << "Customer Bill: $" << customerBill << endl;
    }
};

int main() {
    Customer customers[1];

    cout << "Enter details of 1 customers:" << endl;

    for (int i = 0; i < 1; i++) {
        cout << "\nCustomer " << i + 1 << ":\n";
        customers[i].enterDetails();
    }

    cout << "\nDisplaying customer details:\n";
    for (int i = 0; i < 1; i++) {
        cout << "\nCustomer " << i + 1 << ":\n";
        customers[i].displayDetails();
    }

    return 0;
}
