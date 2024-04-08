/******************************************************
** Program: stalactites.cpp
** Author: Brian Munger
** Date: 11/28/2023
** Description: child class to event. Includes necessary functions
                refered to in game program that are polymorphic.
** Input: none
** Output: symbol is printed in debug mode, percept is printed if adjacent
           to player, stalactite has 50% chance of falling on and killing player
           if player is in the same room as a stalactite.
******************************************************/

#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

//default constructor
Stalactites::Stalactites() {}


void Stalactites::print_symbol() {
    //S = Stalactites
    cout << 'S';
}


void Stalactites::percept() {
    //percept for stalactites
    cout << "You hear water dripping." << endl;
}


int Stalactites::encounter(int armor) {
    cout << "You enter a room with stalactites on the ceiling!" << endl;
    //50/50 chance it falls on the player and kills them
    if (rand() % 2 == 1) {
        if (armor > 0) {
            cout << "A stalactite falls on you, but your armor saves you!!" << endl;
            if (armor - 1 == 0)
                cout << "Your armor breaks. Be careful. " << endl;
            //8 = code for armor falling but not killing you
            return 8;
        } else {
            cout << "A stalactite falls on you, killing you. GAME OVER!" << endl;
            //2 = code for stalactite falling and killing player
            return 2;
        }
    } else {
        cout << "Luckily, a stalactite doesn't fall on you. Whew!" << endl;
        //3 = code for stalactite not falling on player, game continues
        return 3;
    }
}


bool Stalactites::is_closed() {
    //is not a closed room
    return false;
}