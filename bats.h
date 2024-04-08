/******************************************************
** Program: bats.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Bats file for the shop class. Contains the
                private member variables and public member functions
                associated with the bats class. 
******************************************************/

#ifndef BATS_H
#define BATS_H 

#include "event.h"
//Bats Interface

class Bats : public Event {
private:
public:
    /*********************************************************************
    ** Function: Bats()
    ** Description: default constructor for a bats object
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: a bat object is successfully constructed
    *********************************************************************/ 
    Bats();
    
    /*********************************************************************
    ** Function: print_symbol()
    ** Description: prints 'B' when in debug mode and when a bat is in the given
                    room
    ** Parameters: none
    ** Pre-Conditions: the bat is in a given room and the game is in debug mode
    ** Post-Conditions: 'B' is printed in the room where the Bat is
    *********************************************************************/ 
    void print_symbol();
    /*********************************************************************
    ** Function: percept()
    ** Description: prints a message when the player is in a room adjacent to a room
                    with a bat in it that indicates the event is nearby.
    ** Parameters: none
    ** Pre-Conditions: a bat is in an adjacent room
    ** Post-Conditions: the percept for a bat object is printed to the console
    *********************************************************************/ 
    void percept();
    /*********************************************************************
    ** Function: encounter()
    ** Description: confuses the player by reversing their next five moves, resets reveresed
                    moves to five if the player runs into bats twice
    ** Parameters: int - the armor durability of the player
    ** Pre-Conditions: the player is in the same room as a bat
    ** Post-Conditions: the bat confuses the player for the next five turns
    *********************************************************************/ 
    int encounter(int);
    /*********************************************************************
    ** Function: is_closed()
    ** Description: returns false since this event isn't a closed room
    ** Parameters: none
    ** Pre-Conditions: the event is in the same room as the player
    ** Post-Conditions: returns false
    *********************************************************************/ 
    bool is_closed();
};

#endif