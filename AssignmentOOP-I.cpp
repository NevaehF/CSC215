/*
Assignment: Object Oriented Programming I
Nevaeh Fernandez 
10.Sep.2025
nevferna@uat.edu
*/

#include <iostream>
#include <string>

using namespace std; 

// Requirment 1: We have to create a class called "characterClass" 
class characterClass {
    // It needs to be public 
public:
    string Name; // Requirment 2: It needs to be a public property inorder to store the names of the characters

    // These are going to be the constructor to initialize the name and health of the characters. 
    characterClass(string name, int health) : Name(name), Health(health) {
    }

    // THis is the getter for the private Health property 
    int getHealthStats() {
        return Health;
    }

    // This is the setter for the private Health Property
    void setHealthStats(int h) {
        Health = h;
    }

protected : 
    // This is protected so the subclasses can modify the Health if it needs to 
    void decreaseHealthStats(int amount) {
        Health -= amount; 
    }

private : 
    int Health; // Our encapsulated Health property 
};

// Requirment 3: #1 Our Ninja class will now inherit from our characterClass 
class Ninja : public characterClass {
public : 
    // The constructor to initialize Name and Health in the Ninja subclass 
    Ninja(string name, int health) : characterClass(name, health) {}

    // Requirment #4: Method to simulate throwing stars
    void ThrowStars() {
        cout << Name << ": I am throwing stars!" << endl;
    }
};

// Requirment 3: #2 Our Pirate class will inherit from Character superclass just as the Ninja class does
class Pirate : public characterClass {
public:
    // This is the constructor to initialize Name and Health in the Pirate subclass
    Pirate(string name, int health) : characterClass(name, health) {}

    // Requirment #5: Our method that simulates using a sword
    void UseSword() {
        cout << Name << ": I am Swooshing my Sword!" << endl;
    }
};

// This function will display the intro 
void displayIntroText() {
    cout << "==== Pirates vs Ninjas ====!" << endl;
    cout << "Who will win? Let the battle begin!" << endl;
}

int main() {
    // We need to call the intro function therefor we need to display the text 
    displayIntroText();

    // We need to create Ninja and Pirate objects
    Ninja ninja("Sasuke", 120); // Naruto 
    Pirate pirate("Luffy", 100); // One piece 

    // This Calls the methods on the objects
    ninja.ThrowStars();
    pirate.UseSword();

    // We need to make sure to display their health (Using encapsulated health property) (Helps the user experiance) 
    cout << ninja.Name << "'s Health: " << ninja.getHealthStats() << endl;
    cout << pirate.Name << "'s Health: " << pirate.getHealthStats() << endl;

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
