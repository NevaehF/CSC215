// Exceptions -Nevaeh Fernandez.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
    Nevaeh Fernandez 
    Missing Assignment Due: Oct.2nd.2025 
    nevferna@uat.edu
*/

// Assignemnt Starts Here : My Coffee Shop 

#include <iostream>
using namespace std; 

void validateTemperature(int temp) {
    // The temperature can't be negative (nothing below zero)
    if (temp < 0) {
        throw invalid_argument("Error: Temperature cannot be negative!");
    }
    // Temperature of 0 would mean frozen and no heat was applied so we can't seel that 
    else if (temp == 0) {
        throw runtime_error("Error: Coffee cannot be served frozen!");
    }
    /* Sorry I'm not too sure how to add the degrees symbol in my code. 
       Temperature above 200 degrees (F) is dangerously hot and could cause burns so we also can't sell that */
    else if (temp > 200) {
        throw out_of_range("Error: Temperature is dangerously high! Maximum safe temp is 200°F!");
    }
    // This shows when the temperature the user input is within safe range (1-200 degrees (F))
    else {
        cout << "Your Chosen Temperature is safe! Your coffee will be ready shortly  Thank you!." << endl;
    }
}

int main()
{
    // This is here to display a description of my program and how to use it for the user when the application starts   
    cout << "\n===== COFFEE SHOP TEMPERATURE VALIDATOR =====" << endl;
    cout << "This program helps to ensure your coffee is served at safe temperatures." << endl;
    cout << "\nSafety Guidelines:" << endl;
    cout << "- The temperature must be positive (above 0 degrees(F)" << endl;
    cout << "- We cannot serve frozen coffee (0 degrees(F)" << endl;
    cout << "- The maximum safe temperature: 200 degreese(F)" << endl;
    cout << "=============================================\n" << endl;

    // This is my variable to store the temperature input
    int temperature;

    // Prompt user to enter desired coffee temperature
    cout << "Enter your desired coffee temperature please (Num): ";
    cin >> temperature;
    
    
    // Try to validate the temperature
    try {
        validateTemperature(temperature);
    }
    // Catch block for the invalid_argument exception (negative temperature)
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    // Catch block for the runtime_error exception (frozen coffee)
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    // Catch block for the out_of_range exception (too hot)
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}

/* 

CLASS EXAPMLE: 

#include <iostream>
using namespace std; 
void testExceptions(int value) {
    if (value < 0) {
        throw invalid_argument("Error: Negative numbers are not allowed!");
    }
    else if (value == 0) {
        throw runtime_error("Error: Division by zero is not allowed!");
    }
    else if (value > 100) {
        throw out_of_range("Error: value is out of allowed range!");
    }
    else {
        cout << "Value is valid!";
    }
}

int main()
{
    int input; 
    cout << "Enter a value: "; 
    cin >> input; 
    try {
        testExceptions(input);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl; 
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl; 
    }
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
