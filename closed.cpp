/******************************************************
** Program: closed.cpp
** Author: Brian Munger
** Date: 11/28/2023
** Description: child class to event. Includes necessary functions
                refered to in game program that are polymorphic.
** Input: none
** Output: symbol is printed in debug mode, true is returned in 'is_closed'
           to depict that the room is closed.
******************************************************/

#include "closed.h"

#include <iostream>

using namespace std;

//Closed Implementation

Closed::Closed() {}


void Closed::print_symbol() {
    //X = Closed
    cout << 'X';
}

void Closed::percept() {
    //nothing is printed
    return;
}

int Closed::encounter(int armor) {
    //room is closed
    return 0;
}


bool Closed::is_closed() {
    //is a closed room
    return true;
}