#ifndef LAPTOP_H
#define LAPTOP_H

#include <string>
using namespace std;

class Laptop {
private:
    string brand;
    string model;
    double price;
    int ramSizeGB;
    int storageSizeGB;
    int barcode; // 4-digit barcode

    // Helper function to generate a random 4-digit code
    int generateBarcode();

public:
    // Constructors
    Laptop();
    Laptop(string brand, string model, double price, int ramSizeGB, int storageSizeGB);

    // Getters and Setters
    string getBrand() const;
    void setBrand(const string& brand);

    string getModel() const;
    void setModel(const string& model);

    double getPrice() const;
    void setPrice(double price);

    int getRamSizeGB() const;
    void setRamSizeGB(int ramSizeGB);

    int getStorageSizeGB() const;
    void setStorageSizeGB(int storageSizeGB);

    int getBarcode() const; // Getter for barcode

    // Member functions
    void showValues() const;         // Display values vertically
    void detailLine() const;         // Display values in a single line
    void getValues();                // Input values interactively
};

#endif
