/******************************************************
** Program: wumpus.cpp
** Author: Brian Munger
** Date: 11/28/2023
** Description: child class to event. Includes necessary functions
                refered to in game program that are polymorphic.
** Input: none
** Output: symbol is printed in debug mode, percept is printed if adjacent
           to player, Wumpus will kill the player if they are in the same room
           together. 
******************************************************/

#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation

//default constructor
Wumpus::Wumpus() {}


void Wumpus::print_symbol() {
    //W = Wumpus
    cout << 'W';
}


void Wumpus::percept() {
    //percept for Wumpus
    cout << "You smell a terrible stench." << endl;
}


int Wumpus::encounter(int armor) {
    cout << "You walk into a room containing the Wumpus, waking it up!" << endl;
    if (armor > 0) {
        cout << "Your armor protects you from its attack!" << endl;
        if (armor - 1 == 0)
            cout << "Your armor breaks. Be careful. " << endl;
        //9 = code for Wumpus not killing the player
        return 9;
    } else {
        cout << "It eats you in one bite. GAME OVER!" << endl;
        //1 = code for Wumpus killing the player
        return 1;
    }
}


bool Wumpus::is_closed() {
    //is not a closed room
    return false;
}