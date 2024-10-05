# CIS255 Lab 3 & 4: Laptop Inventory with Linked Lists

## Project Overview
This project is an extension of the Laptop Inventory System developed in Lab 2. It introduces the use of **linked lists** to manage a collection of laptops, allowing for more dynamic handling of data. Users can interact with the system to add, delete, modify, and display laptop records, with changes saved to a file for persistence.

## Features
- **Linked List Integration**: Manage a dynamic collection of laptop objects.
- **Add, Modify, Delete Products**: Perform CRUD operations (Create, Read, Update, Delete) on laptop records.
- **CSV File Management**: Read and write laptop data to a CSV file, allowing updates to be saved across sessions.
- **Interactive Menu**: Navigate through the program using an interactive menu for administrative and consumer operations.

## Class Definitions
The project uses the following classes:
- **Laptop**: Represents individual laptop objects with attributes like brand, model, price, RAM, and storage.
- **Laptops (Linked List)**: A collection of `Laptop` objects managed as a linked list.

### Laptop Class
Attributes:
- `brand` (string)
- `model` (string)
- `price` (double)
- `ramSizeGB` (int)
- `storageSizeGB` (int)
- `barcode` (int)

Methods:
- Getters and setters for all attributes.
- Methods for adding, deleting, and modifying laptops.
- Method to display laptop details.

## Menu Options
- **Display All Products**: Show the complete list of laptops.
- **Filter by Fields**: Filter laptops by brand, price, or other fields.
- **Add New Product**: Add a new laptop to the list.
- **Delete Product**: Remove a laptop by barcode.
- **Modify Product**: Update a laptop’s attributes.
- **Save to CSV**: Export the laptop list to a CSV file.
- **Quit**: End the program.

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/NotEsperix/Triton-CIS-255-Programming-Lab-3-4.git
