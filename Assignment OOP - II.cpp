/*
Assignment: Object Oriented Programming II ( Also Using code from OOP I ) 
Nevaeh Fernandez
19.Sep.2025
nevferna@uat.edu
*/

// I've tried again to organize by requirmnt to better help the motion of my code and so i can follow along 

#include <iostream>
#include <string>

using namespace std; 

// Requirment #1: We have to make a class called GameStructure 
class GameStructure {
public: 
    // Requirment #2: Next we have to create a pure virtual method called Help in the "GameStructure class". (Abstraction)
    virtual void Help() = 0; 

    };

// Now we have to use code from OOP I. Our "characterClass" superclass needs to inherit from the "GameStructure" class
class characterClass : public GameStructure {
public: 
    string Name; // This public property is going to store the names of the characters. 

    // Requirment #3: We need a contructor to initialie the names and the health of the characters 
    characterClass(string name, int health) : Name(name), Health(health) { }

    // Requirment #4: This is our getter (getHealth) for the private Health property (Abstraction) 
    int getHealth() {
        return Health; 
    }

    // Requirment #4 : Setter (setHealth) for the private Health property with Health validation (Abstraction) 
    void setHealth(int h) {
        if (h < 0) {
            Health = 0; // This makes it so that if the health falls below zero, set to zero
            // A messgae needs to display if one of the characters lose the battle 
            cout << Name << ": Character has died..." << endl; 
        }
        else {
            Health = h; 
        }
    }

    // Requirment #5: We need a method to simulate the charcters talking (Polymorphism - Overloading) 
    void Talk() {
        cout << Name << " says: Hello!" << endl; 
    }

    // Requirment #6: Overloaded speak method (Polymorphism - Overloading) [void Talk(string name, string stuffToSay)]
    void Talk(string name, string stuffToSay) {
        cout << Name << " says: " << stuffToSay << endl; 
    }

    // Requirment #7: Virtual attack method (Polymorphism - Overriding)
    virtual int Attack() {
        return 10;  // Base attack value for Character
    }


    // Requirment #8: Virtual attack method (Polymorphism - Overloading)
    void Help() override {
        // Empty implementation in the Character superclass
    }

protected:
    // Protected method to decrease Health
    void decreaseHealth(int amount) {
        setHealth(Health - amount);
    }

    // Protected method to increase Health
    void increaseHealth(int amount) {
        setHealth(Health + amount);
    }

private:
    int Health;  // Encapsulated Health property
};

// Ninja class inherits from our characterClass
class Ninja : public characterClass{
public:
    // Constructor to initialize Name and Health in the Ninja subclass
    Ninja(string name, int health) : characterClass(name, health) {}

    // Method to simulate throwing stars
    void ThrowStars() {
        cout << Name << ":I am throwing stars!" << endl;
    }

    // Override the attack method for Ninja (Polymorphism - Overriding)
    int Attack() override {
        return 25;  // Ninja's specific attack value
    }

    // Ninja-specific Help method (Abstraction)
    void Help() override {
        cout << "\nNinjas are really cool! Can you use them to throw stars?!" << endl;
    }
};

// Pirate class inherits from Character
class Pirate : public characterClass {
public:
    // Constructor to initialize Name and Health in the Pirate subclass
    Pirate(string name, int health) : characterClass(name, health) {}

    // Our method to simulate using a sword
    void UseSword() {
        cout << Name << ": I am swooshing my sword!" << endl;
    }

    // Override the attack method for Pirate (Polymorphism - Overriding)
    int Attack() override {
        return 25;  // Pirate's specific attack value
    }

    // Pirate-specific Help method (Abstraction)
    void Help() override {
        cout << "\nPirates are strong and skilled with a sword! Can you swing the sword?" << endl;
    }
};

// This function will display the intro 
void displayIntro() {
    cout << "==== Pirates vs Ninjas ====!" << endl;
    cout << "\nWho will win? Let the battle begin!" << endl;
}

int main() {
    // This will call the intro function
    displayIntro();

    // We need to create Ninja and Pirate objects
    Ninja ninja("\nSasuke", 120); // Naruto Refrence 
    Pirate pirate("Luffy", 100); // One piece refrence 



    // This function is going to simulate actions between our ninja ans pirate 
    ninja.Talk("\nSasuke:", "Prepare to fight!");  // Sasuke talks with default message
    pirate.Talk("\nLuffy:", "Prepare to fight!");  // Luffy talks with custom message

    // the ninja's throws stars
    ninja.ThrowStars();

    // The pirate uses his sword
    pirate.UseSword();

    // This display's our attack values (Overriding)
    cout << ninja.Name << " attacked with " << ninja.Attack() << " \nhit points!" << endl;
    cout << pirate.Name << " attacked with " << pirate.Attack() << " \nhit points!" << endl;

    // Our help methods for both characters
    ninja.Help();  // Ninja-specific help
    pirate.Help();  // Pirate-specific help

    // Our setting health and expiration functions
    ninja.setHealth(-10);  // This is going to trigger our expiration/death message
    pirate.setHealth(30);  // Luffy health is reduced

    // This will display the current health of the characters 
    cout << ninja.Name << "'s Health: " << ninja.getHealth() << endl;
    cout << pirate.Name << "'s Health: " << pirate.getHealth() << endl;

    return 0;
};



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
