/******************************************************
** Program: passage.cpp
** Author: Brian Munger
** Date: 11/28/2023
** Description: child class to event. Includes necessary functions
                refered to in game program that are polymorphic.
** Input: none
** Output: symbol is printed in debug mode, percept is printed if adjacent
           to player, message is displayed regarding teleporting player. 
******************************************************/

#include "passage.h"

#include <iostream>

using namespace std;

//Passage Implementation

Passage::Passage() {}


void Passage::print_symbol() {
    //P = Passage
    cout << 'P';
}


void Passage::percept() {
    //percept for passage
    cout << "You feel a breeze." << endl;
}


int Passage::encounter(int armor) {
    cout << "You found a hidden passage!" << endl;
    cout << "You teleport to the other passage in the cave." << endl;
    //6 = code for hidden passage teleport
    return 6;
}


bool Passage::is_closed() {
    //is not a closed room
    return false;
}