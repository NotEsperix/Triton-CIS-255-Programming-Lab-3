#include "laptop.h"
#include <iostream>
#include <vector>
#include <algorithm> // For transform function to handle case insensitivity
using namespace std;

// Global Variables
vector<Laptop> library;  // Library of laptops
vector<Laptop> cart;     // Shopping cart

// Function Prototypes
void showMenu();
void adminMenu();
void consumerMenu();
void showLibrary();
void addLaptop();
void removeLaptop();
void addToCart();
void removeFromCart();
void viewCart();
void checkoutCart();
void promptContinue();
string toLower(string str);  // Helper function for case-insensitive input
void initializeLibrary();    // Initialize the library with 3 laptops

// Main function
int main() {
    // Initialize the library with 3 laptops
    initializeLibrary();

    // Show the main menu
    showMenu();
    return 0;
}

// Function to initialize the library with 3 laptops
void initializeLibrary() {
    Laptop laptop1("Dell", "XPS 13", 999.99, 16, 512);  // Dell XPS 13 laptop
    Laptop laptop2("Apple", "MacBook Pro", 1999.99, 16, 1024);  // Apple MacBook Pro laptop
    Laptop laptop3("Lenovo", "ThinkPad X1 Carbon", 1299.99, 16, 256);  // Lenovo ThinkPad X1 Carbon laptop

    // Add laptops to the library
    library.push_back(laptop1);
    library.push_back(laptop2);
    library.push_back(laptop3);
}

// Function to display the main menu
void showMenu() {
    string option;
    do {
        cout << "\nAdmin Settings:\n";
        cout << "(1) Library: View computer list\n";
        cout << "(2) Catalog: Add new computer\n";
        cout << "(3) Void: Remove from list\n";
        cout << "(4) Quit: Exit\n";
        cout << "\nConsumer Options:\n";
        cout << "(a) Inventory: View computers\n";
        cout << "(b) Add: Add to shopping cart\n";
        cout << "(c) Remove: Remove from cart\n";
        cout << "(d) Cart: View cart\n";
        cout << "(e) Finished: Checkout and proceed\n";
        cout << "(f) Quit: Exit\n";
        cout << "\nPlease select an option: ";
        cin >> option;

        // Convert user input to lowercase for case-insensitivity
        option = toLower(option);

        // Handle input
        if (option == "1") showLibrary();
        else if (option == "2") addLaptop();
        else if (option == "3") removeLaptop();
        else if (option == "4" || option == "f") return;
        else if (option == "a") showLibrary();
        else if (option == "b") addToCart();
        else if (option == "c") removeFromCart();
        else if (option == "d") viewCart();
        else if (option == "e") checkoutCart();
        else cout << "\nInvalid option. Try again.\n";

    } while (true);
}

// Function to convert strings to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to display the library of laptops
void showLibrary() {
    if (library.empty()) {
        cout << "The library is currently empty.\n";
    }
    else {
        cout << "Library of Laptops:\n";
        for (const auto& laptop : library) {
            laptop.detailLine();
        }
    }
    promptContinue();
}

// Function to add a laptop to the library
void addLaptop() {
    Laptop laptop;
    laptop.getValues();
    library.push_back(laptop);
    cout << "Laptop added to the library.\n";
    promptContinue();
}

// Function to remove a laptop from the library
void removeLaptop() {
    int barcode;
    cout << "Enter the barcode of the laptop to remove: ";
    cin >> barcode;

    auto it = std::remove_if(library.begin(), library.end(), [barcode](Laptop& laptop) {
        return laptop.getBarcode() == barcode;
        });

    if (it != library.end()) {
        library.erase(it, library.end());
        cout << "Laptop removed from the library.\n";
    }
    else {
        cout << "Laptop with barcode " << barcode << " not found.\n";
    }
    promptContinue();
}

// Function to add a laptop to the shopping cart
void addToCart() {
    int barcode;
    cout << "Enter the barcode of the laptop to add to the cart: ";
    cin >> barcode;

    for (const auto& laptop : library) {
        if (laptop.getBarcode() == barcode) {
            cart.push_back(laptop);
            cout << "Laptop added to the cart.\n";
            promptContinue();
            return;
        }
    }
    cout << "Laptop not found in library.\n";
    promptContinue();
}

// Function to remove a laptop from the shopping cart
void removeFromCart() {
    int barcode;
    cout << "Enter the barcode of the laptop to remove from the cart: ";
    cin >> barcode;

    auto it = std::remove_if(cart.begin(), cart.end(), [barcode](Laptop& laptop) {
        return laptop.getBarcode() == barcode;
        });

    if (it != cart.end()) {
        cart.erase(it, cart.end());
        cout << "Laptop removed from the cart.\n";
    }
    else {
        cout << "Laptop with barcode " << barcode << " not found in the cart.\n";
    }
    promptContinue();
}

// Function to view the shopping cart
void viewCart() {
    if (cart.empty()) {
        cout << "Your cart is empty.\n";
    }
    else {
        cout << "Your Cart:\n";
        for (const auto& laptop : cart) {
            laptop.detailLine();
        }
    }
    promptContinue();
}

// Function to checkout the cart
void checkoutCart() {
    if (cart.empty()) {
        cout << "Your cart is empty.\n";
        promptContinue();
        return;
    }

    double total = 0;
    cout << "Checkout Cart:\n";
    for (const auto& laptop : cart) {
        laptop.detailLine();
        total += laptop.getPrice();
    }

    cout << "Total Price: $" << total << endl;
    promptContinue();
}

// Function to prompt continue or quit
void promptContinue() {
    string choice;
    cout << "Press 'Q' to quit or anyother key to continue: ";
    cin >> choice;

    // Convert choice to lowercase
    choice = toLower(choice);

    if (choice == "q") {
        cout << "Exiting the program. Goodbye!" << endl;
        exit(0);
    }
}
