/*

Fist practice example
Nevaeh Fernandez
Sep.09.2025
nevferna@uat.edu

*/

//Example of classes 
#include <iostream>
using namespace std;

// Class Definition 
class Rectangle {
private:        // Attribute - Data numbers 
    double length;
    double width;

public:
    Rectangle() { // Constructor 
        length = 0;
        width = 0;
    }
    // Method to set the dementions of the rectangle 
    void setDimentions(double len, double wid) {
        if (len > 0 && wid > 0) {
            length = len;
            width = wid;
        }
        else {
            cout << "Invalid dimentions. Both must be positive" << endl;

        }
    }
    //Method to calculate the area
    double calculateArea() {
        return length * width;

    }
    // Method to display the rectangles infermation
    void display() {
        cout << "Rectangle dimentions: " << length << " * " << width << endl;
        cout << "Area: " << calculateArea() << endl;

    }
};

int main()
{
    // Create an object of Rectangle 
    Rectangle rect;
    // Set dementions of the rectangle
    rect.setDimentions(5.0, 3.0);
    // Display rectangle information 
    rect.display();
    // Create another object
    Rectangle rect2;
    rect2.setDimentions(7.0, 3.0);
    rect2.display();
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
