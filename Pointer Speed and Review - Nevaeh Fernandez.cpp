// Pointer Speed and Review - Nevaeh Fernandez.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
    Nevaeh Fernandez 
    Missing Assignment Due: Oct.21st.2025
    nevferna@uat.edu

        Raw Pointers 
*/

// Start Of Assignment Raw Pointers and Review 

#include <iostream>
#include <string>
using namespace std;

// The struct for a book
struct Book {
    string title;
    string author;
    double price;
    int pages;
};

// Function 1:This function allows the user to Input book data using pointer
// This Pointer allows the user to modify the original book
void inputBook(Book* b) {
    cout << "Enter book title: ";
    getline(cin, b->title);

    cout << "Enter author: ";
    getline(cin, b->author);

    cout << "Enter price: $";
    cin >> b->price;

    cout << "Enter pages: ";
    cin >> b->pages;
    cin.ignore();
}

// Function 2: This function displays the book using pointers
// Using the pointer to access data faster
void displayBook(Book* b) {
    cout << "\nTitle: " << b->title << endl;
    cout << "Author: " << b->author << endl;
    cout << "Price: $" << b->price << endl;
    cout << "Pages: " << b->pages << endl;
}

// Function 3: This function updates the price using pointer
// This Pointer lets us change the price directly
void updatePrice(Book* b, double* newPrice) {
    b->price = *newPrice;
}

// Function 4: This function calculates discounts using pointers
// Returns discounted price
double calculateDiscount(Book* b, double* percent) {
    return b->price - (b->price * (*percent / 100.0));
}

// Function 5: This function compares two books using pointers
// This returns pointer to more expensive book
Book* moreExpensive(Book* b1, Book* b2) {
    if (b1->price > b2->price) {
        return b1;
    }
    return b2;
}

// Function 6: This function calculats the total price using pointer array
// Pointer array speeds up processing
double totalPrice(Book* books[], int count) {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += books[i]->price;
    }
    return total;
}

int main() {
    cout << "\n=== Book Store System ===\n" << endl;

    // This will allows the user to create 3 books
    Book book1, book2, book3;

    // Input books using pointers
    cout << "Enter Book 1:\n";
    inputBook(&book1);

    cout << "\nEnter Book 2:\n";
    inputBook(&book2);

    cout << "\nEnter Book 3:\n";
    inputBook(&book3);

    // Displays the books
    cout << "\n\n--- Book 1 ---";
    displayBook(&book1);

    cout << "\n--- Book 2 ---";
    displayBook(&book2);

    cout << "\n--- Book 3 ---";
    displayBook(&book3);

    // This will update the price for book1
    double newPrice = 25.99;
    updatePrice(&book1, &newPrice);
    cout << "\n\nBook 1 price updated to $" << newPrice << endl;

    // This will calculate the discount for book2
    double discount = 20.0;
    double discountedPrice = calculateDiscount(&book2, &discount);
    cout << "Book 2 with 20% discount: $" << discountedPrice << endl;

    // This needs to compare book1 and book2
    Book* expensive = moreExpensive(&book1, &book2);
    cout << "\nMore expensive book: " << expensive->title << endl;

    // This needs to calculate the total price using an array
    Book* bookArray[3] = { &book1, &book2, &book3 };
    double total = totalPrice(bookArray, 3);
    cout << "Total price of all books: $" << total << endl;

    return 0;
}


/* Class Example 2 

#include <iostream>
#include <string>
using namespace std; 

class SmartTest {

private: 
    int data;

public: 
    SmartTest(int val) : data(val) {
        cout << "Constructing SmartTest with value: " << data << endl; 
    }
    ~SmartTest() { // Deconstructor 
        cout << "Deconstructing SmartTest with value: " << data << endl; 
    }
    void display() const {
        cout << "Value: " << data << endl;
    }
};

int main() {
    // Raw pointers example 
    SmartTest* rawPointers = new SmartTest(42);
    rawPointers->display();
    cout << endl; 
    // Smart Pointers example using unique_ptr
    unique_ptr<SmartTest> uniquePointer = make_unique<SmartTest>(99);
   // unique_ptr<SmartTest> uniquePointer2 = uniquePointer;
    uniquePointer->display();
    cout << endl; 
    // Smart pointer using shared_tr
    shared_ptr<SmartTest> sharedPointer1 = make_shared<SmartTest>(77);
    shared_ptr<SmartTest> sharedPointer2 = sharedPointer1; 
    sharedPointer1->display();
    sharedPointer2->display();
    cout << endl; 
    // no need to delete smart pointers manually 
    delete rawPointer;
}
*/


/* Class Example 1
Smart Pointers

#include <iostream>
#include <string>

// Application of student record system
using namespace std; 
struct Student {
    string name; 
    int age; 
    double grade; 
};

// FUnction to input data for one student using pointers
void inputStudent(Student* s) {
    cout << "Enter name: ";
    cin.ignore();
    cin >> s->name;
    cout << "Enter age: "; 
    cin >> s->age;
    cout << "Enter grade: ";
    cin >> s->grade; 
}
// function to display student information 
void displayStudent(const Student* s) {
    cout << "Name: " << s->name << ", Age: " << ", Grade: " << s->grade << endl; 
}
// function to calculate average grade 
double calculateAverage(Student* students[], int cout) {
    double total = 0; 
    for (int i = 0; i < count; i++) {
        total += students[i]->grade; 
    }
    return (cout > 0) ? total / cout : 0; 
}
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
