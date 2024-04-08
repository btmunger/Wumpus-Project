/******************************************************
** Program: room.cpp
** Author: Brian Munger
** Date: 11/28/2023
** Description: function definition for the room class. Room objects
                will be placed in the 2D vector. Contains getters and setters
                for the event object, and boolean marking if there is an object
                there. 
** Input: none
** Output: none
******************************************************/

#include "room.h"

using namespace std;

//Room Implementation

//default constructor for the room class
Room::Room(){
    e = nullptr;
    has_event = false;
}


void Room::set_event(Event* new_e){
    //sets event 
    e = new_e;
}


void Room::set_has_event(const bool new_event) {
    //sets event boolean 
    has_event = new_event;
}


bool Room::get_has_event() const{
    //returns event boolean
    return has_event;
}


Event* Room::get_event() const {
    //returns event
    return e;
}