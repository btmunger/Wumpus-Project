/******************************************************
** Program: armor.cpp
** Author: Brian Munger
** Date: 11/28/2023
** Description: child class to event. Includes necessary functions
                refered to in game program that are polymorphic.
** Input: none
** Output: symbol is printed in debug mode, percept is printed if adjacent
           to player, armor is picked up in encounter function if user is in
           same room as armor. 
******************************************************/

#include "armor.h"

#include <iostream>

using namespace std;

//Armor Implementation

Armor::Armor() {}


void Armor::print_symbol() {
    //A = Armor
    cout << 'A';
}


void Armor::percept() {
    //percept for Armor
    cout << "You feel the power." << endl;
}


int Armor::encounter(int armor) {
    cout << "You found a strong set of armor!" << endl;
    cout << "This will protect you from two otherwise fatal events..." << endl;
    //7 = code for armor successfully picked up
    return 7;
}


bool Armor::is_closed() {
    //is not a closed room
    return false;
}