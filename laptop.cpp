#include "laptop.h"
#include <iostream>
#include <random>
using namespace std;

// Helper function to generate a 4-digit random barcode
int Laptop::generateBarcode() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 9999);
    return dis(gen);
}

// Default constructor
Laptop::Laptop() : brand("Unknown"), model("Unknown"), price(0.0), ramSizeGB(0), storageSizeGB(0), barcode(generateBarcode()) {}

// Parameterized constructor
Laptop::Laptop(string brand, string model, double price, int ramSizeGB, int storageSizeGB)
    : brand(brand), model(model), price(price), ramSizeGB(ramSizeGB), storageSizeGB(storageSizeGB), barcode(generateBarcode()) {}

// Getters and Setters
string Laptop::getBrand() const { return brand; }
void Laptop::setBrand(const string& brand) { this->brand = brand; }

string Laptop::getModel() const { return model; }
void Laptop::setModel(const string& model) { this->model = model; }

double Laptop::getPrice() const { return price; }
void Laptop::setPrice(double price) { this->price = price; }

int Laptop::getRamSizeGB() const { return ramSizeGB; }
void Laptop::setRamSizeGB(int ramSizeGB) { this->ramSizeGB = ramSizeGB; }

int Laptop::getStorageSizeGB() const { return storageSizeGB; }
void Laptop::setStorageSizeGB(int storageSizeGB) { this->storageSizeGB = storageSizeGB; }

int Laptop::getBarcode() const { return barcode; }

// Function to display laptop details vertically
void Laptop::showValues() const {
    cout << "Laptop Details:\n";
    cout << "Barcode: " << barcode << "\n";
    cout << "Brand: " << brand << "\n";
    cout << "Model: " << model << "\n";
    cout << "Price: $" << price << "\n";
    cout << "RAM Size: " << ramSizeGB << " GB\n";
    cout << "Storage Size: " << storageSizeGB << " GB\n";
}

// Function to display laptop details in a single line
void Laptop::detailLine() const {
    cout << "Barcode: " << barcode << " | " << brand << " | " << model << " | $" << price
        << " | RAM: " << ramSizeGB << " GB | Storage: " << storageSizeGB << " GB\n";
}

// Function to input laptop details interactively
void Laptop::getValues() {
    cout << "Enter brand: ";
    cin >> brand;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter RAM size (GB): ";
    cin >> ramSizeGB;
    cout << "Enter storage size (GB): ";
    cin >> storageSizeGB;
    barcode = generateBarcode(); // Generate a new barcode
}
