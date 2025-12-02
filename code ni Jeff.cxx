#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string items[] = {"Ballpen", "Notebook", "Yellow Pad", "Pencil", "Bond Paper (10 pcs)"};
    int stocks[]   = {20, 15, 10, 25, 30};
    int prices[]   = {10, 35, 20, 8, 15};

    int choice, itemNo, qty;

    do {
        cout << "\n==============================\n";
        cout << "   SCHOOL SUPPLIES STORE\n";
        cout << "==============================\n";
        cout << "1. View Available Items\n";
        cout << "2. Order Items\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n--- AVAILABLE ITEMS ---\n";
            for (int i = 0; i < 5; i++) {
                cout << i+1 << ". " 
                     << items[i] 
                     << " | Price: ₱" << prices[i]
                     << " | Stock: " << stocks[i]
                     << endl;
            }

        } else if (choice == 2) {
            cout << "\nEnter Item Number (1-5): ";
            cin >> itemNo;

            if (itemNo < 1 || itemNo > 5) {
                cout << "Invalid item number.\n";
                continue;
            }

            cout << "Enter Quantity: ";
            cin >> qty;

            int index = itemNo - 1;

            if (qty > stocks[index]) {
                cout << "Not enough stock available.\n";
            } else {
                int total = qty * prices[index];
                stocks[index] -= qty;

                cout << "\nOrder Successful!\n";
                cout << "Item: " << items[index] << endl;
                cout << "Quantity: " << qty << endl;
                cout << "Total Price: ₱" << total << endl;
                cout << "Remaining Stock: " << stocks[index] << endl;
            }

        } else if (choice == 3) {
            cout << "\nThank you for visiting!\n";

        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}