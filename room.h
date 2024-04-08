/******************************************************
** Program: room.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Header file for the room class. Contains the
                private member variables and public member functions
                associated with the room class. 
******************************************************/

#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

class Room
{
private: 
    Event* e;           //pointer to an event in a room
    bool has_event;     //bool that inidicates if there is an event in a room 
public:
    /*********************************************************************
    ** Function: Room()
    ** Description: default constructor for the Room class
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: a Room object is successfully created
    *********************************************************************/ 
    Room();

    /*********************************************************************
    ** Function: set_event()
    ** Description: sets the event of a given room to whatever is passed through
    ** Parameters: Event* - pointer to an event
    ** Pre-Conditions: none
    ** Post-Conditions: the e (event pointer) points to whatever was passed through
    *********************************************************************/ 
    void set_event(Event*);
    /*********************************************************************
    ** Function: set_has_event()
    ** Description: this sets the has event boolean to whatever is passed through
    ** Parameters: bool - indicates if a room has an event
    ** Pre-Conditions: none
    ** Post-Conditions: correctly depicts if there is a event in a given room
    *********************************************************************/ 
    void set_has_event(const bool);

    /*********************************************************************
    ** Function: get_has_event()
    ** Description: returns the bool that depicts if there is an event in a given room
    ** Parameters: none
    ** Pre-Conditions: has_event bool is successfully populated
    ** Post-Conditions: has_event bool is successfully returned
    *********************************************************************/ 
	bool get_has_event() const;
    /*********************************************************************
    ** Function: get_event()
    ** Description: returns the event pointer in a given room
    ** Parameters: none
    ** Pre-Conditions: Event* e is successfully assigned
    ** Post-Conditions: Event* e is successfully returned
    *********************************************************************/ 
    Event* get_event() const;
};
#endif