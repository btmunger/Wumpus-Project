/******************************************************
** Program: armor.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Header file for the armor class. Contains the private 
                member variables and public member functions
                associated with the armor class. 
******************************************************/

#ifndef ARMOR_H
#define ARMOR_H 

#include "event.h"
//Armor Interface

class Armor : public Event {
private:
public:
    /*********************************************************************
    ** Function: Armor()
    ** Description: the default constructor for a armor object 
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: a armor object is successfully
    *********************************************************************/ 
    Armor();

    /*********************************************************************
    ** Function: print_symbol()
    ** Description: prints 'A' when in debug mode and when armor is in the given
                    room
    ** Parameters: none
    ** Pre-Conditions: the armor is in a given room and the game is in debug mode
    ** Post-Conditions: A is printed in the room where the armor is
    *********************************************************************/  
    void print_symbol();
    /*********************************************************************
    ** Function: percept()
    ** Description: prints a message when the player is in a room adjacent to a room
                    with the armor that indicates the event is nearby.
    ** Parameters: none
    ** Pre-Conditions: the armor is in an adjacent room
    ** Post-Conditions: the percept for a armor object is printed to the console
    *********************************************************************/ 
    void percept();
    /*********************************************************************
    ** Function: encounter()
    ** Description: when the user is in the same room as the armor, the user picks it
                    up, and can survive two otherwise deadly encounters.
    ** Parameters: int - the armor durability of the player
    ** Pre-Conditions: the player is in the same room as the armor
    ** Post-Conditions: the player picks up the armor
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