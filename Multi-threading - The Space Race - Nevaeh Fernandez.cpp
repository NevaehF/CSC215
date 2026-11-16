// Multi-threading - The Space Race - Nevaeh Fernandez.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
    Nevaeh Fernandez 
    Missing Assignment Due: Dec.2nd.2025 
    nevferna@uat.edu

    Multithreading 
*/

// Multithreading Assignment 

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;

// This is the global variable to track who has control { True  = the Main Base and false = the Space Cadet 
bool mainBaseControl = true; 

// This stops all launches when true 
bool abortPressed = false; 

// This is my function to launch the rocket. Takes rocket number and who is launching it 
void launchRocket(int num, string who) {
    if (abortPressed) {
        cout << "Rocket " << num << " launch cancelled - ABORT ACTIVATED!!! \n " << endl; 
        return; 
}
// Displaying who is launching
    cout << "\n" << who << " launching Rocket " << num << endl;

    cout << "\n" << who << " launching Rocket " << num << endl;

    // The Countdown of 3-2-1
    cout << "3... ";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "2... ";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "1... ";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "TAKE OFF!\n" << endl;
}
// My function for the Main Base to launch Rocket 1
void mainBaseLaunch() {
    cout << "\nMain Base: Launching Rocket 1" << endl;
    this_thread::sleep_for(chrono::seconds(3));  // 3 second delay
    launchRocket(1, "MAIN BASE");
}

// My function for Space Cadet to launch rockets 2 through 10
void spaceCadetLaunch(int num) {
    // This is what waits until Main Base gives control
    while (mainBaseControl) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "\nSpace Cadet: Preparing Rocket " << num << endl;
    this_thread::sleep_for(chrono::seconds(3));  // 3 second delay
    launchRocket(num, "SPACE CADET ");
}

// My function that monitors for any imput to abort 
void monitorAbort() {
    cout << "\nMain Base Monitoring: Press 'a' + Enter to abort\n" << endl;
    char input;
    cin >> input;

    // This is so that if a is pressed at all it just aborts and doesnt need to be specific 
    if (input == 'a' || input == 'A') {
        cout << "\n*** ABORT PRESSED BY MAIN BASE ***\n" << endl;
        abortPressed = true;
    }
}

int main()
{
    // This is the Intro Display for my code. 
    cout << "\n=== Welcome to Rocker Launcher!! ===" << endl;
    cout << "10 Rockets will launch with 3 seconds between each\n" << endl;
    cout << "Main Base launches Rocket 1" << endl;
    cout << "Then control transfers to Space Cadet for Rockets 2-10" << endl;
    cout << "Main Base can abort at any time\n" << endl;

    cout << "Press Enter to start...";
    cin.get();

    // This vectors purpose is to hold all threads
    vector<thread> threads;

    // Start monitoring thread
    thread t0(monitorAbort);

    // The Main Base will launches Rocket 1
    thread t1(mainBaseLaunch);
    t1.join();  // Wait for Rocket 1 to finish

    // This transfer control to Space Cadet
    cout << "\n*** CONTROL TRANSFERRED TO SPACE CADET ***\n" << endl;
    mainBaseControl = false;

    // The Space Cadet launches Rockets 2-10
    for (int i = 2; i <= 10; i++) {
        threads.push_back(thread(spaceCadetLaunch, i));
    }

    // Wait for all rockets to finish
    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }

    // This helps to clean up the monitoring thread
    if (t0.joinable()) {
        t0.detach();
    }

    // This is the final summary
    cout << "\n=== MISSION COMPLETE ===" << endl;
    if (abortPressed) {
        cout << "Mission aborted by Main Base" << endl;
    }
    else {
        cout << "All 10 rockets launched successfully!" << endl;
    }

    return 0;
}



/* Class Example #1 

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std; 

// Simulated test function 
void task(string name, int duration) {
    cout << "Thread " << name << " started, will take " << duration << " seconds.\n" << endl;
    this_thread::sleep_for(chrono::seconds(duration));
    cout << "Thread " << name << " finished\n";
}

int main()
{
    cout << "Main threads are going to start....." << endl; 
    thread t1(task, "A", 2);
    thread t2(task, "B", 4);
    thread t3(task, "C", 1);
    thread t4(task, "D", 5);

    // Wait for all the threads to finish 
    t1.join();
    t2.join();
    t3.join();
    t4.join();
} */

/* Class Example #2 

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <string>
using namespace std;

// Function to increment elements of the array in a given range 
void increment(vector<int>& arr, int start, int end) {
    for (int i = start; i < end; ++i) {
        arr[i] += 1; //increment each element by 1
    }

}
int main()
{
    int n = 10; //Size of array 
    vector <int> numbers(n, 0); // initiaalize array with zeros
    cout << "Inital Array : ";
    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << " ";
        cout << endl; 
        }
    // Create two threads to increment the array 
    thread t1(increment, ref(numbers), 0, n / 2); 
    thread t2(increment, ref(numbers), n / 2, 0);
    // Wait till both threads to finish 
    t1.join(); 
    t2.join(); 
    cout << "Array after incrementing: "; 
    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << " ";
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
