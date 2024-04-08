/******************************************************
** Program: passage.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Header file for the passage class. Contains the private 
                member variables and public member functions
                associated with the passage class. 
******************************************************/

#ifndef PASSAGE_H
#define PASSAGE_H 

#include "event.h"
//Passage Interface

class Passage : public Event {
private:
public:
    /*********************************************************************
    ** Function: Passage()
    ** Description: the default constructor for a passage object 
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: a passage object is successfully
    *********************************************************************/ 
    Passage();

    /*********************************************************************
    ** Function: print_symbol()
    ** Description: prints 'P' when in debug mode and when a passage is in the given
                    room
    ** Parameters: none
    ** Pre-Conditions: the passage is in a given room and the game is in debug mode
    ** Post-Conditions: P is printed in the room where the passage is
    *********************************************************************/  
    void print_symbol();
    /*********************************************************************
    ** Function: percept()
    ** Description: prints a message when the player is in a room adjacent to a room
                    with the passage that indicates the event is nearby.
    ** Parameters: none
    ** Pre-Conditions: the passage is in an adjacent room
    ** Post-Conditions: the percept for a passage object is printed to the console
    *********************************************************************/ 
    void percept();
    /*********************************************************************
    ** Function: encounter()
    ** Description: when the user is in the same room as the passage, the user teleports to the
                    other passage on the grid. A statement indicates their travel, and their
                    position is updated on the grid.
    ** Parameters: int - the armor durability of the player
    ** Pre-Conditions: the player is in the same room as the passage
    ** Post-Conditions: the player is teleported to the other passage
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