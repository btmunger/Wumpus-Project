/******************************************************
** Program: closed.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Header file for the closed class. Contains the private 
                member variables and public member functions
                associated with the closed class. 
******************************************************/

#ifndef CLOSED_H
#define CLOSED_H 

#include "event.h"
//Closed Interface

class Closed : public Event {
private:
public:
    /*********************************************************************
    ** Function: Closed()
    ** Description: the default constructor for a closed object 
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: a closed object is successfully
    *********************************************************************/ 
    Closed();

    /*********************************************************************
    ** Function: print_symbol()
    ** Description: prints 'C' when in debug mode and when a the given room is closed
    ** Parameters: none
    ** Pre-Conditions: the given room is closed and the game is in debug mode
    ** Post-Conditions: 'X' is printed in a closed room
    *********************************************************************/ 
    void print_symbol();
    /*********************************************************************
    ** Function: percept()
    ** Description: does not print anything for a closed room
    ** Parameters: none
    ** Pre-Conditions: a closed room is adjacent to the current room
    ** Post-Conditions: nothing is printed to the console
    *********************************************************************/ 
    void percept();
    /*********************************************************************
    ** Function: encounter()
    ** Description: does not do anything for a closed room, a player can never enter
                    a closed room.
    ** Parameters: int - the armor durability of the player
    ** Pre-Conditions: none
    ** Post-Conditions: nothing happens
    *********************************************************************/ 
    int encounter(int);
    /*********************************************************************
    ** Function: is_closed()
    ** Description: returns true since this event is a closed room
    ** Parameters: none
    ** Pre-Conditions: the event is in the same room as the player
    ** Post-Conditions: returns true
    *********************************************************************/ 
    bool is_closed();
};

#endif