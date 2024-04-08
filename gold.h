/******************************************************
** Program: gold.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Header file for the gold class. Contains the private 
                member variables and public member functions
                associated with the gold class. 
******************************************************/

#ifndef GOLD_H
#define GOLD_H 

#include "event.h"
//Gold Interface

class Gold : public Event {
private:
public:
    /*********************************************************************
    ** Function: Gold()
    ** Description: the default constructor for a gold object 
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: a gold object is successfully
    *********************************************************************/ 
    Gold();

    /*********************************************************************
    ** Function: print_symbol()
    ** Description: prints 'W' when in debug mode and when gold is in the given
                    room
    ** Parameters: none
    ** Pre-Conditions: the gold is in a given room and the game is in debug mode
    ** Post-Conditions: W is printed in the room where the gold is
    *********************************************************************/  
    void print_symbol();
    /*********************************************************************
    ** Function: percept()
    ** Description: prints a message when the player is in a room adjacent to a room
                    with the gold that indicates the event is nearby.
    ** Parameters: none
    ** Pre-Conditions: the gold is in an adjacent room
    ** Post-Conditions: the percept for a gold object is printed to the console
    *********************************************************************/ 
    void percept();
    /*********************************************************************
    ** Function: encounter()
    ** Description: when the user is in the same room as the gold, the user picks it
                    up, and will have to make it back to the starting position with it to win. 
    ** Parameters: int - the armor durability of the player
    ** Pre-Conditions: the player is in the same room as the gold
    ** Post-Conditions: the player picks up the gold
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