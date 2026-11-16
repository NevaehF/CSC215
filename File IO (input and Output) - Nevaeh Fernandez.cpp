// File IO (input and Output) - Nevaeh Fernandez.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
    Nevaeh Fernandez
    Missing Assignment Due: Oct.7th.2025
    nevferna@uat.edu

    File I/O in C++
*/

/* CLASS EXAMPLE */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Example of writing into a file 
// Example of reading from a file 

int main()
{
    ifstream infile("test.txt"); // open file for reading 
    string line;
    if (!infile) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    while (getline(infile, line)) { // read by line 
        cout << line << endl;
    }
    infile.close();
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
