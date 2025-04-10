# 🚗 Vehicle Inventory & Sales Management System

This is a **C++ console-based application** that manages a company's vehicle inventory, sales transactions, and employee records. It utilizes **Object-Oriented Programming (OOP)** principles, **binary file handling**, and **modular programming** to ensure efficient data storage and manipulation.

---

## 📌 Features

### 🔐 Authentication
- User must **log in or register** before accessing the system.
- Login credentials are stored securely in a binary file (`acc.bin`).

### 🚘 Vehicle Management
- **Add new vehicles** to inventory.
- **Display all vehicles** in a structured table format.
- **Search for a vehicle** by ID.
- **Modify vehicle information** (individual fields or full re-entry).
- **Delete vehicles** by ID.
- **Sort vehicles** (e.g., by price or ID).

### 💰 Sales Management
- **Sell vehicles** by transferring them to `sellvehicles.bin`.
- Generates a **receipt** that includes:
  - Company name
  - Buyer’s name
  - Cashier’s name
  - Final price
- Records **sales history** and displays a full list of sold vehicles.

### 👨‍🔧 Employee Management
- Displays predefined employee records.
- Allows users to **add more employees** and save them in `employees.bin`.

### ⚙️ Utilities
- Clear all stored data (vehicles, sales, employees).
- Log out to the login/register screen.
- Exit the program safely.

---

## 🧱 File Structure

- `main.cpp` - The core application with the `main()` function and logic handling.
- `Vehicle.h / Vehicle.cpp` - Vehicle class implementation (attributes, methods, I/O).
- `Employee.h / Employee.cpp` - Employee class with details and record handling.
- `auth.h / auth.cpp` - Handles user authentication.
- `acc.bin` - Stores user login credentials.
- `vehicles.bin` - Stores vehicle data.
- `sellvehicles.bin` - Stores sold vehicle data.
- `employees.bin` - Stores additional employee data added by the user.

---

## 💡 How It Works

1. **User logs in or registers.**
2. **Main menu** appears with 12 options:
   - Add, view, search, modify, delete, sort vehicles.
   - Sell vehicles and generate a receipt.
   - View sales and employee records.
   - Add new employees.
   - Clear all data, log out, or exit.

Each operation directly reads/writes to binary files to ensure data persistence between runs.

---

## 🛠️ Requirements

- C++ Compiler (e.g., g++, Visual C++).
- Terminal or command prompt to run the executable.

---

## 🚀 How to Run

1. Clone the repository or copy the source files.
2. Compile the source code:
   ```bash
   g++ main.cpp Vehicle.cpp Employee.cpp auth.cpp -o vehicle_manager
