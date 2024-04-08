/******************************************************
** Program: gold.cpp
** Author: Brian Munger
** Date: 11/28/2023
** Description: child class to event. Includes necessary functions
                refered to in game program that are polymorphic.
** Input: none
** Output: symbol is printed in debug mode, percept is printed if adjacent
           to player, gold is picked up in encounter function if user is in
           same room as gold. 
******************************************************/

#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

Gold::Gold() {}


void Gold::print_symbol() {
    //G = Gold
    cout << 'G';
}


void Gold::percept() {
    //percept for gold
    cout << "You see a glimmer nearby." << endl;
}


int Gold::encounter(int armor) {
    cout << "You found a shinny golden treasure! You pick it up." << endl; 
    cout << "Better make it back to the starting rope...alive." << endl;
    //5 = code for gold successfully picked up
    return 5;
}


bool Gold::is_closed() {
    //is not a closed room
    return false;
}