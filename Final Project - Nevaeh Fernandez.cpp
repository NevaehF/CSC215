// Final Project - Nevaeh Fernandez.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* Nevaeh Fernandez
    DUe Date: Dec.15.2025
    nevferna@uat.edu
*/
#include <iostream>
#include <string>
#include <vector> // I need to use this for my vectors 
#include <thread> // I need this for my Multithreading 
#include <chrono> // I need this for the time delays in my simulator  
using namespace std;

// I had to make this abstract so you can't make a plain "Drink" so its limited to Coffee, Latte, etc.
// Drink class - This is the parent class for all drinks
class Drink {
private:
    // I had to make these private in order for it to fit my encapsulation requirment. 
    string name;     
    double basePrice; 

public:
    // My constructor runs when I create a Drink
    Drink(string n, double p) : name(n), basePrice(p) {}

    // These are my getters. They let me access the private variables
    // This is also a part of my encapsulation requirment 
    string getName() { return name; }
    double getBasePrice() { return basePrice; }

    // This is my pure virtual function. The "= 0" means my child classes MUST write their own version
    // This covers my abstraction requirment I have to implement this if I inherit from my Drink class
    virtual double calculatePrice() = 0;

    // This is my vertual function and the child classes can override this if needed
   // This is meets my poly,orphism requirment 
    virtual void serve() {
        cout << "Serving " << name << endl;
    }
};

// My constructor calls my parent constructor with the Coffee's info
class Coffee : public Drink {
public:
    Coffee() : Drink("Coffee", 3.50) {}

    // Each drink calculates price differently
    double calculatePrice() override {
        return getBasePrice();
    }

    // I override serve() to make it unique for Coffee
    void serve() override {
        cout << "Brewing fresh " << getName() << "... Done!" << endl;
    }
};

// Latte class inherits from Drink
class Latte : public Drink {
public:
    Latte() : Drink("Latte", 4.50) {}

    // I override calculatePrice
    double calculatePrice() override {
        return getBasePrice();
    }

    // I override serve() with my Latte - specific message
    void serve() override {
        cout << "Steaming milk for " << getName() << "... Done!" << endl;
    }
};

// Cappuccino class inherits from Drink
class Cappuccino : public Drink {
public:
    Cappuccino() : Drink("Cappuccino", 5.00) {}

    // Overriding
    double calculatePrice() override {
        return getBasePrice();
    }

    void serve() override {
        cout << "Making foamy " << getName() << "... Done!" << endl;
    }
};


//My Customer class is used inorder to store the customer info
class Customer {
private:
    string name;       
    int orderNumber;    

public:
    // Constructor
    Customer(string n, int num) : name(n), orderNumber(num) {}

    // Public getters - encapsulation
    string getName() { return name; }
    int getOrderNumber() { return orderNumber; }
};


// Order class to store drink orders
class Order {
private:
    Customer* customer;  // Pointer to customer
    Drink* drink;        // Pointer to drink (polymorphism!)
    int orderNumber;     // Private member
    bool completed;      // Private member

public:
    // Constructor
    Order(Customer* c, Drink* d, int num) {
        customer = c;
        drink = d;
        orderNumber = num;
        completed = false;
    }

    // Public getters
    Customer* getCustomer() { return customer; }
    Drink* getDrink() { return drink; }
    int getOrderNumber() { return orderNumber; }
    bool isCompleted() { return completed; }

    // // I use this to mark my order as done
    void complete() { completed = true; }

    // I use this to print my order info for the user to see 
    void display() {
        cout << "Order #" << orderNumber << " - "
            << customer->getName() << " - "
            << drink->getName() << " - $"
            << drink->calculatePrice();

        if (completed) {
            cout << " [COMPLETED]";
        }
        else {
            cout << " [PENDING]";
        }
        cout << endl;
    }
};


//My Queue class using templates
// I used <typename T> so this works with any data type, making it easier 
template <typename T>
class Queue {
private:
    vector<T> items;   // I'm using VECTOR to store my items 

public:
   // I use this inorder to add items to my queue
    void add(T item) {
        items.push_back(item);
    }

    // I use this in order to get the number of items
    int size() {
        return items.size();
    }

    // I use this to check if my queue is empty
    bool isEmpty() {
        return items.empty();
    }

    // I use this to get an item at a specific index
    T get(int index) {
        return items[index];
    }

    // I use this to remove an item
    void remove(int index) {
        items.erase(items.begin() + index);
    }

    // I use this to get all of my items for my iterators requirement
    vector<T>& getAll() {
        return items;
    }
};

// I made this function call itself to add up add-on prices
double calculateWithAddons(double basePrice, int addonsCount) {
    // Base case: no more add-ons/stops my recurtion 
    if (addonsCount <= 0) {
        return basePrice;
    }

    //// I made each addon cost $0.50 to make it easier for myslef 
    return calculateWithAddons(basePrice + 0.50, addonsCount - 1);
}


// Function to simulate customer ordering (runs in thread)
void customerOrdering(string name) {
    cout << "\n *Thinkin* " << name << " is browsing the menu..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Yay" << name << " is ready to order!" << endl;
}


// Global variables for the shop
Queue<Order*> orderQueue;  // Template queue for orders
vector<Customer*> customers;  // Vector to store customers
int orderCounter = 1;  // Counter for order numbers
double totalEarnings = 0.0;  // Total money earned

// Multiple versions of createDrink function
Drink* createDrink(int choice) {
    if (choice == 1) return new Coffee();
    if (choice == 2) return new Latte();
    if (choice == 3) return new Cappuccino();
    return nullptr;
}

Drink* createDrink(string name) {
    if (name == "Coffee") return new Coffee();
    if (name == "Latte") return new Latte();
    if (name == "Cappuccino") return new Cappuccino();
    return nullptr;
}


//I use this to show my main menu
void displayOpeningScreen() {
    cout << "\n============================================" << endl;
    cout << "    WELCOME TO MY COFFEE SHOP SIMULATOR" << endl;
    cout << "==============================================" << endl;
    cout << "\nWelcome to Your Coffee Shop!" << endl;
    cout << "\nHOW TO PLAY:" << endl;
    cout << "1. Take orders from customers" << endl;
    cout << "2. Make their drinks" << endl;
    cout << "3. Earn money for each order" << endl;
    cout << "4. Try to serve as many customers as possible!" << endl;
    cout << "\nGOAL: Make customers happy and earn money!" << endl;
    cout << "============================================\n" << endl;
}

// This function is used to display the menu
void displayMenu() {
    cout << "\n===== COFFEE SHOP MENU =====" << endl;
    cout << "1. Take New Order" << endl;
    cout << "2. Make a Drink" << endl;
    cout << "3. View All Orders" << endl;
    cout << "4. Check Earnings" << endl;
    cout << "5. Exit" << endl;
    cout << "============================" << endl;
    cout << "Enter choice: ";
}

// I use this function to take a new order from a customer
void takeNewOrder() {
    try {
        string customerName;
        int drinkChoice;
        int addons;

        cout << "\n--- Take New Order ---" << endl;
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, customerName);

        // Check for empty name / exception handling
        if (customerName.empty()) {
            throw invalid_argument("Customer name cannot be empty!");
        }

        // I have to start the thread to simulate customer browsing
        thread customerThread(customerOrdering, customerName);
        customerThread.join();  // Wait for customer to finish browsing

        cout << "\nDrink Menu:" << endl;
        cout << "1. Coffee - $3.50" << endl;
        cout << "2. Latte - $4.50" << endl;
        cout << "3. Cappuccino - $5.00" << endl;
        cout << "Enter drink choice (1-3): ";
        cin >> drinkChoice;

        // This Validates drink choice 
        if (drinkChoice < 1 || drinkChoice > 3) {
            throw out_of_range("Invalid drink choice! Must be 1-3.");
        }

        cout << "How many add-ons? (0-3): ";
        cin >> addons;

        // This Validates add-ons 
        if (addons < 0 || addons > 3) {
            throw out_of_range("Invalid add-ons! Must be 0-3.");
        }

        // Create customer and drink 
        Customer* newCustomer = new Customer(customerName, orderCounter);
        Drink* drink = createDrink(drinkChoice);  

        // Create order
        Order* newOrder = new Order(newCustomer, drink, orderCounter);

        // Add to my ordering queue 
        orderQueue.add(newOrder);
        customers.push_back(newCustomer);

        // Calculate final price with add-ons
        double finalPrice = calculateWithAddons(drink->getBasePrice(), addons);

        cout << "\n? Order #" << orderCounter << " created!" << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Drink: " << drink->getName() << endl;
        cout << "Add-ons: " << addons << endl;
        cout << "Total Price: $" << finalPrice << endl;

        orderCounter++;
    }
    catch (const invalid_argument& e) {
        cout << "\nError: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "\nError: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "\nUnexpected error: " << e.what() << endl;
    }
}

// This is my function to make a drink
void makeDrink() {
    try {
        if (orderQueue.isEmpty()) {
            throw runtime_error("No orders to make!");
        }

        cout << "\n--- Make a Drink ---" << endl;
        cout << "Pending orders:" << endl;

        // Loop through orders using iterator
        int index = 0;
        for (auto it = orderQueue.getAll().begin(); it != orderQueue.getAll().end(); it++) {
            if (!(*it)->isCompleted()) {
                cout << index + 1 << ". ";
                (*it)->display();
            }
            index++;
        }

        int choice;
        cout << "Which order to make? (1-" << orderQueue.size() << "): ";
        cin >> choice;

        if (choice < 1 || choice > orderQueue.size()) {
            throw out_of_range("Invalid order number!");
        }

        Order* order = orderQueue.get(choice - 1);

        if (order->isCompleted()) {
            throw runtime_error("This order is already completed!");
        }

        cout << "\nMaking " << order->getDrink()->getName()
            << " for " << order->getCustomer()->getName() << "..." << endl;

        // serve() is called differently based on drink type
        order->getDrink()->serve();

        order->complete();
        double price = order->getDrink()->calculatePrice();
        totalEarnings += price;

        cout << "? Order completed! Earned $" << price << endl;
    }
    catch (const runtime_error& e) {
        cout << "\nError: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "\nError: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "\nUnexpected error: " << e.what() << endl;
    }
}


// this is my function to view all orders
void viewAllOrders() {
    if (orderQueue.isEmpty()) {
        cout << "\nNo orders yet!" << endl;
        return;
    }

    cout << "\n--- All Orders ---" << endl;

    // Use iterator to loop through vector
    int count = 1;
    for (auto it = orderQueue.getAll().begin(); it != orderQueue.getAll().end(); it++) {
        cout << count << ". ";
        (*it)->display();
        count++;
    }
}

// this is my function to check earnings
void checkEarnings() {
    cout << "\n--- Shop Statistics ---" << endl;
    cout << "Total Customers Served: " << customers.size() << endl;
    cout << "Total Orders: " << orderQueue.size() << endl;
    cout << "Total Earnings: $" << totalEarnings << endl;
    cout << "-----------------------" << endl;
}

int main() {
    // This displayes my opening screen
    displayOpeningScreen();

    cout << "Press Enter to start your shift...";
    cin.get();

    int choice;

    // This is the loop fpr my main menu
    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            takeNewOrder();
        }
        else if (choice == 2) {
            makeDrink();
        }
        else if (choice == 3) {
            viewAllOrders();
        }
        else if (choice == 4) {
            checkEarnings();
        }
        else if (choice == 5) {
            cout << "\nClosing shop..." << endl;
            cout << "Final earnings: $" << totalEarnings << endl;
            cout << "Thanks for playing! ?" << endl;
        }
        else {
            cout << "\nInvalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
