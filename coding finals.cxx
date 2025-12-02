#include <iostream>
#include <iomanip>
using namespace std;

// This structure represents 1 item in the store.
struct Item {
    string name;   // Item name
    double price;  // Price per piece
    int stock;     // Available quantity
};

int main() {

    // List of items the shop sells
    Item items[3] = {
        {"Burger", 55.00, 20},
        {"Fries", 35.00, 30},
        {"Iced Tea", 25.00, 40}
    };

    double total = 0;   // Keeps track of total payment
    bool running = true;
    int choice, qty;

    // Display header
    cout << "========================================\n";
    cout << "             DEAN'S SHOP                \n";
    cout << "         ORDERING APPLICATION           \n";
    cout << "========================================\n";

    while (running) {

        // Show items
        cout << "\nAvailable Items\n";
        cout << left << setw(15) << "Item"
             << setw(10) << "Price"
             << setw(10) << "Stock" << endl;
        cout << "----------------------------------------\n";

        // Loop to print all items
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". "
                 << left << setw(12) << items[i].name
                 << setw(8) << items[i].price
                 << setw(8) << items[i].stock << endl;
        }

        cout << "4. Checkout\n";

        // Ask user what they want to order
        cout << "\nEnter your choice: ";
        cin >> choice;

        // If user selects an item (1–3)
        if (choice >= 1 && choice <= 3) {

            cout << "Enter quantity: ";
            cin >> qty;

            // Check if quantity is valid
            if (qty <= 0) {
                cout << "Invalid quantity!\n";
                continue;
            }

            // Check if stock is enough
            if (qty > items[choice - 1].stock) {
                cout << "Not enough stock!\n";
                continue;
            }

            // Calculate the cost and update totals
            double cost = qty * items[choice - 1].price;
            total += cost;
            items[choice - 1].stock -= qty;

            // Print mini-receipt
            cout << "\n=========== RECEIPT ===========\n";
            cout << "Item:      " << items[choice - 1].name << endl;
            cout << "Quantity:  " << qty << endl;
            cout << "Unit Price: " << items[choice - 1].price << " PHP\n";
            cout << "Subtotal:   " << cost << " PHP\n";
            cout << "-------------------------------\n";
            cout << "Running Total: " << total << " PHP\n";
            cout << "===============================\n";
        }
        // If user chooses 4 → end ordering
        else if (choice == 4) {
            running = false;
        }
        // Wrong menu option
        else {
            cout << "Invalid option!\n";
        }
    }

    // Final total after checkout
    cout << "\n========================================\n";
    cout << "         THANK YOU FOR ORDERING         \n";
    cout << "========================================\n";
    cout << "Total Amount Due: " << total << " PHP\n";
    cout << "========================================\n";

    return 0;
}
