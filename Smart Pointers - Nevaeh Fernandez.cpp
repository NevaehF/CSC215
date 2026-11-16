// Smart Pointers - Nevaeh Fernandez.cpp : This file contains the 'main' function. Program execution begins and ends there.


/*
    Nevaeh Fernandez 
    Missing Assignemnt Due: Nov.11.2025 
    nevferna@uat.edu
*/

#include <iostream>
#include <memory>
#include <vector>
#include <string>


// A simple Player class to demonstrate smart pointers
class Player {
public:
    std::string name;
    Player(std::string playerName) : name(playerName) {
        std::cout << "Player \"" << name << "\" has been created.\n";
    }
    ~Player() {
        std::cout << "Player \"" << name << "\" has been destroyed.\n";
    }
    void greet() const {
        std::cout << "Hello, my name is " << name << ".\n";
    }
};
void createPlayersWithUniquePtr() {
    std::cout << "\n--- Unique Pointer Demonstration ---\n";
    // Creating a unique_ptr to manage a Player object
    std::unique_ptr<Player> player1 = std::make_unique<Player>("Richard");
    player1->greet();
    {
        // Demonstrating scope: this player will be destroyed after this block ends
        std::unique_ptr<Player> player2 = std::make_unique<Player>("Ban");
        player2->greet();
    } // player2 goes out of scope here, and memory is automatically released
    std::cout << "Exiting the unique_ptr demonstration scope...\n";
    // player1 goes out of scope here
}
void createPlayersWithSharedPtr() {
    std::cout << "\n--- Shared Pointer Demonstration ---\n";
    // This is the shared ownership of a Player object
    std::shared_ptr<Player> player1 = std::make_shared<Player>("Chris");
    {
        std::shared_ptr<Player> player2 = player1; // Shared ownership
        std::cout << "Player \"" << player1->name << "\" is now shared between two pointers.\n";
            player2->greet();
        std::cout << "Exiting inner block where player2 shared ownership...\n";
    } // player2 goes out of scope, but player1 still holds ownership
    std::cout << "Only one shared_ptr remains now. The Player object will be destroyed when it goes out of scope.\n";
        // player1 goes out of scope here
}
void demonstrateWeakPtr() {
    std::cout << "\n--- Weak Pointer Demonstration ---\n";
    // we need a shared_ptr to manage our Player object
    std::shared_ptr<Player> sharedPlayer = std::make_shared<Player>("Diana");
    std::weak_ptr<Player> weakPlayer = sharedPlayer; // weak_ptr observes
    sharedPlayer;

    if (auto lockedPlayer = weakPlayer.lock()) {
        std::cout << "Weak pointer successfully locked. Player is still alive.\n";
        lockedPlayer->greet();
        }
    std::cout << "Releasing the shared_ptr...\n";
    sharedPlayer.reset(); // Destroy the shared Player object

    if (auto lockedPlayer = weakPlayer.lock()) {
        std::cout << "Weak pointer locked. This should not happen because the Player is destroyed.\n";
    }
    else {
        std::cout << " Weak pointer can no longer lock the Player object as it is destroyed.\n";
    }
}
//This is our main function
int main() {
    std::cout << "Welcome to the Smart Pointer Example Program!\n";
    // Demonstrate unique_ptr
    createPlayersWithUniquePtr();
    // Demonstrate shared_ptr
    createPlayersWithSharedPtr();
    // Demonstrate weak_ptr
    demonstrateWeakPtr();
    std::cout << "\nThank you for using the Smart Pointer Example Program. Goodbye!\n";
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
