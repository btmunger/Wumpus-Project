/******************************************************
** Program: wumpus.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Header file for the wumpus class. Contains the
                private member variables and public member functions
                associated with the wumpus class. 
******************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"
//Wumpus Interface

class Wumpus : public Event {
private:
public:
    /*********************************************************************
    ** Function: Wumpus()
    ** Description: default constructor for a wumpus object
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: a wumpus object is created
    *********************************************************************/ 
    Wumpus();

    /*********************************************************************
    ** Function: print_symbol()
    ** Description: prints 'W' when in debug mode and when a Wumpus is in the given
                    room
    ** Parameters: none
    ** Pre-Conditions: the Wumpus is in a given room and the game is in debug mode
    ** Post-Conditions: 'W' is printed in the room where the Wumpus is
    *********************************************************************/ 
    void print_symbol();
    /*********************************************************************
    ** Function: percept()
    ** Description: prints a message when the player is in a room adjacent to a room
                    with the Wumpus that indicates the event is nearby.
    ** Parameters: none
    ** Pre-Conditions: the Wumpus is in an adjacent room
    ** Post-Conditions: the percept for a Wumpus object is printed to the console
    *********************************************************************/ 
    void percept();
    /*********************************************************************
    ** Function: encounter()
    ** Description: prints a message letting the player know the Wumpus killed them,
                    then ends the game
    ** Parameters: int - the armor durability of the player
    ** Pre-Conditions: the player is in the same room as the Wumpus
    ** Post-Conditions: the Wumpus kills the player an outputs a corresponding message
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