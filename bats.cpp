/******************************************************
** Program: bats.cpp
** Author: Brian Munger
** Date: 11/28/2023
** Description: child class to event. Includes necessary functions
                refered to in game program that are polymorphic.
** Input: none
** Output: symbol is printed in debug mode, percept is printed if adjacent
           to player, bats will confuse players reversing their moves if the
           player is in the same room as a bat.
******************************************************/

#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation

//default constructor for bats
Bats::Bats() {}


void Bats::print_symbol() {
    //B = bats
    cout << 'B';
}


void Bats::percept() {
    //percept for bats
    cout << "You hear wings flapping." << endl;
}


int Bats::encounter(int armor) {
    cout << "An angry bat confuses you! Your movements will be reversed for";
    cout << " your next five moves. " << endl;
    //4 = bats confuse players for five moves
    return 4;
}


bool Bats::is_closed() {
    //is not a closed room
    return false;
}