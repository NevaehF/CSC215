// Allocation and deallocation of memory - Nevaeh Fernandez.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
    Nevaeh Fernandez 
    Missing Assignment Due: Nov.4th.2025
    nevferna@uat.edu
*/

#include <iostream>
#include <string>

// We need a class to demonstrate object creation on the heap
class ExampleObject {
public:
    std::string name;
    ExampleObject(std::string objName) : name(objName) {
        std::cout << "Object \"" << name << "\" has been created on the heap.\n";
    }
    ~ExampleObject() {
        std::cout << "Object \"" << name << "\" has been destroyed and memory has been deallocated.\n";
    }
    void display() const {
        std::cout << "This is a " << name << ".\n";
    }
};
int main() {
    // Introduction to the program
    std::cout << "Welcome to the Memory Allocation and Deallocation Program!\n";
    std::cout << "This program will demonstrate how to allocate and deallocate memory on the heap using the 'new' and 'delete' keywords.\n\n";
        // Demonstrate memory allocation for primitive data types
        std::cout << "Allocating memory on the heap for primitive data types...\n";
    int* intPtr = new int(42); // Allocating an integer
    float* floatPtr = new float(3.14f); // Allocating a float
    char* charPtr = new char('A'); // Allocating a character
    double* doublePtr = new double(9.81); // Allocating a double
    // Need to desplay the allocated values
    std::cout << "Integer allocated on the heap: " << *intPtr << "\n";
    std::cout << "Float allocated on the heap: " << *floatPtr << "\n";
    std::cout << "Character allocated on the heap: " << *charPtr << "\n";
    std::cout << "Double allocated on the heap: " << *doublePtr << "\n";
    // Deallocate the memory for primitive types
    std::cout << "Deallocating memory for the primitive data types...\n";
    delete intPtr;
    delete floatPtr;
    delete charPtr;
    delete doublePtr;
    std::cout << "Memory for primitive data types has been successfully deallocated.\n\n";
        // Demonstrate memory allocation for objects
        std::cout << "Now creating objects on the heap using the 'new' keyword...\n";
    // Creating specific example objects I chose to go with items found in a makeup Bag 
        ExampleObject* foundation = new ExampleObject("Foundation");
    ExampleObject* lipGloss = new ExampleObject("Lip Gloss");
    ExampleObject* primer = new ExampleObject("Primer");
    ExampleObject* mascara = new ExampleObject("Mascara");
    ExampleObject* blush = new ExampleObject("Blush");
    // Make sure the code is displaying the objects
    foundation->display();
    lipGloss->display();
    primer->display();
    mascara->display();
    blush->display();
    // Deallocate the memory for objects
    std::cout << "\nNow deallocating memory for the objects...\n";
    delete foundation;
    delete lipGloss;
    delete primer;
    delete mascara;
    delete blush;
    std::cout << "Memory for all objects has been successfully deallocated.\n";
    // End of our code
    std::cout << "\nThank you for using the Memory Allocation and Deallocation Program!\n";
        std::cout << "We hope you learned how to manage memory with the 'new' and 'delete' keywords.\n";
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
