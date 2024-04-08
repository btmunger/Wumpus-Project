/******************************************************
** Program: event.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Header file for the event class. Contains the
                private member variables and public member functions
                associated with the event class. 
******************************************************/

#ifndef EVENT_H
#define EVENT_H 

using namespace std;

class Event
{
protected:
public:
    /*********************************************************************
    ** Function: Event()
    ** Description: default constructor for an event object
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: successfully constructs an event object
    *********************************************************************/ 
    Event();
    /*********************************************************************
    ** Function: print_symbol()
    ** Description: virtual function that prints the symbol of a given event
    ** Parameters: none
    ** Pre-Conditions: the debug menu has been selected
    ** Post-Conditions: the respective event symbol is printed to the console
    *********************************************************************/ 
	virtual void print_symbol() = 0;
    /*********************************************************************
    ** Function: percept()
    ** Description: virtual function that prints the percept of a given event
    ** Parameters: none
    ** Pre-Conditions: the event is adjacent to the player's location
    ** Post-Conditions: the respective event percept is printed to the console
    *********************************************************************/ 
    virtual void percept() = 0;
    /*********************************************************************
    ** Function: encounter()
    ** Description: virtual function that handles the action of an event when it is in
                    the same room as the player
    ** Parameters: int - the armor durability of the player
    ** Pre-Conditions: the event is in the same room as the player
    ** Post-Conditions: the respective action and output is concluded as needed
    *********************************************************************/ 
    virtual int encounter(int) = 0;
    /*********************************************************************
    ** Function: is_closed()
    ** Description: virtual function that returns true if the event type is closed, 
                    false otherwise
    ** Parameters: none
    ** Pre-Conditions: the event is in the same room as the player
    ** Post-Conditions: returns true if the event type is closed, false otherwise
    *********************************************************************/ 
    virtual bool is_closed() = 0;
}; 
#endif