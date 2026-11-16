// Direct Recursionm - Nevaeh Fernandez.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
    Nevaeh Fernandez 
    Missing Assignment Due: Nov.20.2025
    nevferna@uat.edu
*/

// Start of Assignment Direct Recursion

#include <iostream>
#include <vector>
using namespace std;

// This Struct is here to hold maze cell information
struct Cell {
    char symbol;  // What character to display (# for wall, blank space for path)
};

// These are my Global variables
int width;
int height;
// This is how i print multiple rows in turn making it 2D 
vector<vector<Cell>> maze; // thr grid of cells 

// recursive function to fill the maze with patterns
// This is Direct Recursion - function calls itself
void fillMaze(int row, int col) {
    // Base case: this stops it if its out of bounds
    if (row >= height) {
        return;
    }
    if (col >= width) {
        // This makes it move to the next row
        fillMaze(row + 1, 0);
        return;
    }

    // this is creating a pattern. Alternating walls and paths
    if ((row + col) % 2 == 0) {
        maze[row][col].symbol = '#';  // My Wall
    }
    else {
        maze[row][col].symbol = ' ';  // My Path
    }

    // Recursive cell - move to next column
    fillMaze(row, col + 1);
}

// This is my function to display the maze
void displayMaze() {
    cout << "\n";

    // This prints the top boarder
    for (int i = 0; i < width + 2; i++) {
        cout << "-";
    }
    cout << endl;

    // This prints the rows of the maze 
    for (int row = 0; row < height; row++) {
        cout << "#";  // Left border
        for (int col = 0; col < width; col++) {
            cout << maze[row][col].symbol;
        }
        cout << "#" << endl;  // Right border
    }

    // This prints the bottom boarder
    for (int i = 0; i < width + 2; i++) {
        cout << "-";
    }
    cout << endl;
}

int main() {
    // My Introduction to my code 
    cout << "\n=== MAZE GENERATOR ===" << endl;
    cout << "Uses Direct Recursion to create mazes\n" << endl;

    // This gets the user input
    cout << "Enter maze width: ";
    cin >> width;

    cout << "Enter maze height: ";
    cin >> height;

    // Initialize maze vector
    maze.resize(height);
    for (int i = 0; i < height; i++) {
        maze[i].resize(width);
    }

    cout << "\nGenerating maze...\n" << endl;

    // Call recursive function to fill maze
    fillMaze(0, 0);

    // Display the maze
    displayMaze();

    cout << "\nMaze: " << width << " x " << height << endl;
    cout << "# = wall, space = path" << endl;

    return 0;
}

/* Class Example 1
    Structs and templates

#include <iostream>
using namespace std; 
struct Student {
    string name; 
    int age; 
    double gpa; 
};
struct Course {
    string name; 
    int cresits; 
    string instructor; 
};

int main() {
    
    Student student1; 
    student1.name = "Michael";
    student1.age = 25; 
    student1.gpa = 3.5;
    // Another way to create struct
    Student student2 = { "Maria", 20, 2.5 };
    Course course1; 
    course1.name = "Into To Programming";
    course1.cresits = 3;
    course1.instructor = "Dr. Smith";
    Course course2 = { "C++ 2", 3, "Dr Jill" };
    // Display some information 
    cout << "Information about student 1: " << endl; 
    cout << "Name: " << student1.name << endl; 
    cout << "Age: " << student1.age << endl; 
    cout << "Gpa: " << student1.gpa << endl; 
    cout << endl; 
    cout << "Information about course 1: " << endl; 
    cout << "Course name: " << course1.name << endl; 
    cout << "Credits: " << course1.cresits << endl; 
    cout << "Proffessor: " << course1.instructor << endl; 
}
*/

/* Class Example 2 

#include <iostream>
using namespace std; 

//double add(double a, double b);
//int add(int a, int b);
//float add(float a, float b);
template < typename T>
T add(T a, T b) {
    return a + b; 
}
template < typename T> 
T maximum(T a, T b) {
    return (a > b) ? a : b; 
}

int main(){
    cout << "Maximum for int: " << maximum(5, 10) << endl; 
    cout << "Maximum for double: " << maximum(1.5, 5.8) << endl; 
    cout << "Maximum for string: " << maximum("x", "X"); 

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
