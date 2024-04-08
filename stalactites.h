/******************************************************
** Program: stalacties.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Header file for the stalactites class. Contains the
                private member variables and public member functions
                associated with the stalactites class. 
******************************************************/

#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"
//Stalactites Interface

class Stalactites : public Event {
private:
public:
    /*********************************************************************
    ** Function: Stalactites()
    ** Description: default constructor for a stalactite object
    ** Parameters: none 
    ** Pre-Conditions: none
    ** Post-Conditions: a stalactite object is successfully constructed
    *********************************************************************/ 
    Stalactites();

    /*********************************************************************
    ** Function: print_symbol()
    ** Description: prints 'S' when in debug mode and when a stalactite is in the given
                    room
    ** Parameters: none
    ** Pre-Conditions: the stalactite is in a given room and the game is in debug mode
    ** Post-Conditions: 'S' is printed in the room where the stalactite is
    *********************************************************************/ 
    void print_symbol();
    /*********************************************************************
    ** Function: percept()
    ** Description: prints a message when the player is in a room adjacent to a room
                    with a stalactite that indicates the event is nearby.
    ** Parameters: none
    ** Pre-Conditions: a stalactite is in an adjacent room
    ** Post-Conditions: the percept for a stalactite object is printed to the console
    *********************************************************************/ 
    void percept();
    /*********************************************************************
    ** Function: encounter()
    ** Description: 50/50 chance of either killing the player (by landing on them) or
                    nothing happens
    ** Parameters:  int - the armor durability of the player
    ** Pre-Conditions: the player is in the same room as a stalactite
    ** Post-Conditions: the player either dies or nothing happens
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
