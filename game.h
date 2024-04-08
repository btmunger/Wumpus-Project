/******************************************************
** Program: game.h
** Author: Brian Munger
** Date: 11/28/2023
** Description: Header file for the game class. Contains the
                private member variables and public member functions
                associated with the game class. 
******************************************************/

#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"
#include "wumpus.h"
#include "bats.h"
#include "stalactites.h"
#include "gold.h"
#include "closed.h"
#include "passage.h"
#include "armor.h"

using namespace std;

//Game interface 
class Game
{
private:
	vector<vector<Room>> rooms; //2D vector of Room objects
	int length; 				//length of the board (rows)
	int width;  				//width of the board (collumns)

	int num_arrows; 			//keeps track of number of errors remaining
	int num_reverse;			//keeps track of number of reverse moves remaining
	int close_room;             //iterator that tracks how many turns since closed room
	int closed;                 //keeps track of how many rooms are closed 

	bool debug_view;			//debug mode or not
	int player_row;             //players current row position
	int player_col;             //players current collumn position
	int wumpus_row;             //wumpus current row position
	int wumpus_col;             //wumpus current collumn position

	Wumpus w;                   //default wumpus object
	Bats b;                     //default bats object
	Stalactites s;				//default stalactites object
	Gold g;						//default gold object
	Closed c;					//default closed object
	Passage p;					//default passage object
	Armor a;

	int starting_row;           //starting row of player
	int starting_col;           //starting col of player
	bool has_gold;              //indicates if player has gold
	int armor_dur;              //indicates if player has gold;
	bool wumpus_shot;           //indicates if player has shot the Wumpus

	int passage1_row;           //row of the first passage event
	int passage1_col;           //collumn of the first passage event
	int passage2_row;			//row of the second passage event
	int passage2_col;			//collumn of the second passage event

public:
	/*********************************************************************
	** Function: Game()
	** Description: non-default constructor for a game. Initalizes member variables
				    by stating the grid size, game mode, number of arrows(3), and other 
					various statements.
	** Parameters: int - length of grid, int - width of grid, bool - debug mode
	** Pre-Conditions: int parameters correctly depict the size of the grid, bool parameter
					   correctly depicts what gamemode the game should be in
	** Post-Conditions: a game object is correctly and properly constructeds
	*********************************************************************/
	Game(int, int, bool);
	/*********************************************************************
	** Function: ~Game()
	** Description: non-default destructor for a game. 
	** Parameters: int - length of grid, int - width of grid, bool - debug mode
	** Pre-Conditions: int parameters correctly depict the size of the grid, bool parameter
					   correctly depicts what gamemode the game should be in
	** Post-Conditions: a game object is correctly and properly constructeds
	*********************************************************************/
	~Game();
	
	/*********************************************************************
	** Function: place_user()
	** Description: Places the user randomly on the grid before they start 
					playing the game. 
	** Parameters: none
	** Pre-Conditions: grid is properly constructed
	** Post-Conditions: the user is placed randomly on the grid
	*********************************************************************/
	void place_user();
	/*********************************************************************
	** Function: place_wumpus()
	** Description: Places the Wumpus randomly on the grid, ensures the Wumpus is
					not placed in a room with the user or another event
	** Parameters: none
	** Pre-Conditions: grid is properly constructed, user has been successfully placed 
					   previously
	** Post-Conditions: the Wumpus is placed randomly on the grid in a room not 
						containing the user or any other events
	*********************************************************************/
	void place_wumpus();
	/*********************************************************************
	** Function: set_placed_event()
	** Description: Places the event object on the grid given the random row and col
					value previously generated
	** Parameters: char - event name; int - row; int -col
	** Pre-Conditions: row and col have been randomly generated and do not correspond to the
					   player or another event
	** Post-Conditions: the event is successfully placed using the row and col generated
	*********************************************************************/
	void set_placed_event(char, int, int);
	/*********************************************************************
	** Function: place_event()
	** Description: Places the event randomly on the grid, ensures the event is
					not placed in a room with the user or another event
	** Parameters: char - name of event
	** Pre-Conditions: grid is properly constructed, user has been successfully placed 
					   previously
	** Post-Conditions: the event is placed randomly on the grid in a room not 
						containing the user or any other events
	*********************************************************************/
	void place_event(char);

	/*********************************************************************
	** Function: set_passages()
	** Description: this function sets the passage variables to the random empty rooms that 
					were found by the place_passages() function. These variables will be reference
					later to teleport the user.
	** Parameters: int - which passage is being set, int - row of passage, int - col 
				   of passage
	** Pre-Conditions: random empty rooms have been found to set the hidden passage to
	** Post-Conditions: the hidden passage events (2 of them) have been placed
	*********************************************************************/
	void set_passages(int, int, int);
	/*********************************************************************
	** Function: place_passages()
	** Description: Places the hidden passages randomly on the grid, ensures the passages
					are not placed in a room with the user or another event
	** Parameters: none
	** Pre-Conditions: grid is properly constructed, user has been successfully placed 
					   previously
	** Post-Conditions: the passages are placed randomly on the grid in a room not 
						containing the user or any other events
	*********************************************************************/
	void place_passages();

	/*********************************************************************
	** Function: set_up()
	** Description: Sets up the grid by calling the respective placing functions
					and sizing the grid to the length and width the user choose.
	** Parameters: none
	** Pre-Conditions: grid is properly constructed
	** Post-Conditions: the grid is properly resized and populated with the user and events
	*********************************************************************/
	void set_up();

	/*********************************************************************
	** Function: print_event()
	** Description: Second function that prints the grid for the game. Prints the user
					and events (if in debug mode) for each room.
	** Parameters: int - iterator from the display_game function
	** Pre-Conditions: is properly called by display_game with the iterator
	** Post-Conditions: players and events are properly printed
	*********************************************************************/
	void print_event(int) const;
	/*********************************************************************
	** Function: display_game()
	** Description: First function that prints the grid for the game. Creates the barrier width,
					and calls the print_event function for every room.
	** Parameters: none
	** Pre-Conditions: grid is properly constructed and has the correct events
	** Post-Conditions: 
	*********************************************************************/
	void display_game() const;

	/*********************************************************************
	** Function: check_win()
	** Description: checks if the user won the game by collecting the gold and returning
					to the starting position
	** Parameters: none
	** Pre-Conditions: member variables have been properly initaited 
	** Post-Conditions: true is returned if the player successfully wins the game
	*********************************************************************/
	bool check_win() const;

	/*********************************************************************
	** Function: get_dir()
	** Description: this function is called when the user chooses to fire an arrow, and
					prompts the user to enter the direction (wasd) that the arrow will be
					fired to. Ensures the user enters 'wasd.'
	** Parameters: none
	** Pre-Conditions: player has chosen to fire an arrow
	** Post-Conditions: the direction of the arrow (wasd) is properly returned
	*********************************************************************/
	char get_dir();

	/*********************************************************************
	** Function: shoot_wumpus()
	** Description: this function is called when the user successfully shoots the Wumpus. This
					action results in the player winning the game. 
	** Parameters: none
	** Pre-Conditions: the Wumpus was successfully shot by the player
	** Post-Conditions: the Wumpus is removed from the grid, the player wins
	*********************************************************************/
	void shoot_wumpus();
	/*********************************************************************
	** Function: missed_shot()
	** Description: this function is called when the user does not hit the Wumpus with an arrow.
					There is a 75% chance the Wumpus will move to a random room (the respective
					function is called to do so), and a 25% chance it stays in the room it is in.
	** Parameters: none
	** Pre-Conditions: the user misses their arrow shot
	** Post-Conditions: the Wumpus either stays put or moves to a random room 
	*********************************************************************/
	void missed_shot();

	/*********************************************************************
	** Function: fire_up()
	** Description: this function is called when the user chooses to fire an arrow up (using w).
					It checks to make sure that the arrow can travel 3 rooms (hits a wall otherwise),
					and calls the shoot_wumpus() or missed_shot() function respectively.
	** Parameters: none
	** Pre-Conditions: user chose to fire an arrow up
	** Post-Conditions: the arrow is fired up and the shoot_wumpus or missed_shot() function
						is respectively called
	*********************************************************************/
	void fire_up();
	/*********************************************************************
	** Function: fire_down()
	** Description: this function is called when the user chooses to fire an arrow down (using s).
					It checks to make sure that the arrow can travel 3 rooms (hits a wall otherwise),
					and calls the shoot_wumpus() or missed_shot() function respectively.
	** Parameters: none
	** Pre-Conditions: user chose to fire an arrow down
	** Post-Conditions: the arrow is fired down and the shoot_wumpus or missed_shot() function
						is respectively called
	*********************************************************************/
	void fire_down();
	/*********************************************************************
	** Function: fire_right()
	** Description: this function is called when the user chooses to fire an arrow right (using d).
					It checks to make sure that the arrow can travel 3 rooms (hits a wall otherwise),
					and calls the shoot_wumpus() or missed_shot() function respectively.
	** Parameters: none 
	** Pre-Conditions: user chose to fire an arrow right
	** Post-Conditions: the arrow is fired right and the shoot_wumpus or missed_shot() function
						is respectively called
	*********************************************************************/
	void fire_right();
	/*********************************************************************
	** Function: fire_left()
	** Description: this function is called when the user chooses to fire an arrow left (using a).
					It checks to make sure that the arrow can travel 3 rooms (hits a wall otherwise),
					and calls the shoot_wumpus() or missed_shot() function respectively.
	** Parameters: none
	** Pre-Conditions: user chose to fire an arrow left
	** Post-Conditions: the arrow is fired left and the shoot_wumpus or missed_shot() function
						is respectively called
	*********************************************************************/
	void fire_left();

	/*********************************************************************
	** Function: fire_arrow()
	** Description: this function is called when the user decides to shoot an arrow. It calls the
					get_dir() function to get the direction the arrow will be fired in, and then calls
					the respective fire function depending on the direction the user chose.
	** Parameters: none 
	** Pre-Conditions: the user chose to fire an arrow
	** Post-Conditions: the right function is called depending on which direction they would like the arrow
						to be fired.
	*********************************************************************/
	void fire_arrow();

	/*********************************************************************
	** Function: move_up()
	** Description: if the player is not at the first row, this function moves the
					player up one space. User can not move into a closed room.
	** Parameters: none
	** Pre-Conditions: grid and player member variables have been successfully initiated
	** Post-Conditions: moves the player up one space in the grid if able
	*********************************************************************/
	void move_up();
	/*********************************************************************
	** Function: move_down()
	** Description: if the player is not at the last row, this function moves the 
					player down one space. User can not move into a closed room.
	** Parameters: none
	** Pre-Conditions: grid and player member variables have been successfully initiated
	** Post-Conditions: moves the player down one space in the grid if able
	*********************************************************************/
	void move_down();
	/*********************************************************************
	** Function: move_left()
	** Description: if the player is not at the first collumn, this function moves the 
					player left one space. User can not move into a closed room.
	** Parameters: none
	** Pre-Conditions: grid and player member variables have been successfully initiated
	** Post-Conditions: moves the player left one space in the grid if able
	*********************************************************************/
	void move_left();
	/*********************************************************************
	** Function: move_right()
	** Description: if the player is not at the last collumn, this function moves the 
					player right one space. User can not move into a closed room.
	** Parameters: none
	** Pre-Conditions: grid and player member variables have been successfully initiated
	** Post-Conditions: moves the player right one space in the grid if able
	*********************************************************************/
	void move_right();

	/*********************************************************************
	** Function: check_arrows()
	** Description: ensures the player has at least one arrow before calling the fire arrow
					function
	** Parameters: none
	** Pre-Conditions: the player has chosen to fire an arrow
	** Post-Conditions: does not call the fire arrow function if the user has no arrows
	*********************************************************************/
	void check_arrows();
	/*********************************************************************
	** Function: move()
	** Description: this function handles managing the player's action: to either move through
					the cave or fire an arrow. 'wasd' indicates the player would like to move (in
					a certain direction) and 'f' indicates the player would like to fire an arrow. 
					The respective funciton is called depending on what the user entered. 
	** Parameters: char - the players choice to move (wasd) or fire an arrow (f)
	** Pre-Conditions: the user enters 'wasd' to move through the cave or 'f' to fire an arrow
	** Post-Conditions: the right function is called to either move the player or fire an arrow
	*********************************************************************/
	void move(char);
	/*********************************************************************
	** Function: move_reverse()
	** Description: this function operates similarly to the above move() function, but is called when
					the user is confused by a bat. There movements are reveresed, for example 'w' moves the
					player down instead of up. Firing an arrow (by entering 'f') still normally fires an arrow.
	** Parameters: char - the players choice to move (wasd) or fire an arrow (f)
	** Pre-Conditions: the user enters 'wasd' to move through the cave or 'f' to fire an arrow
	** Post-Conditions: the right function is called to either move the player reveresly or fire an arrow
	*********************************************************************/
	void move_reverse(char);

	/*********************************************************************
	** Function: get_input()
	** Description: prompts the user to enter the direction they would like to move or if they would
					like to fire an arrow. Error checks to ensure the user entered either 'wasd' or 
					'f.'
	** Parameters: none
	** Pre-Conditions: it is time for the user to decide to either move or fire an arrow
	** Post-Conditions: the user entered either 'wasd' to move in the grid or 'f' to fire an arrow
	*********************************************************************/
	char get_input();

	/*********************************************************************
	** Function: percepts_2()
	** Description: this function is called after the player takes a turn to indicate to them which
					events are adjacent to them. Each event has its own percept phrase, and is referenced
					depending on which event is adjacent to the player. Seperated into two functions to
					follow the 15 line function rule.
	** Parameters: none
	** Pre-Conditions: percepts() has ran normally
	** Post-Conditions: percepts from events to the left and right of the player have been printed
	*********************************************************************/
	void percepts_2();
	/*********************************************************************
	** Function: percepts()
	** Description: this function is called after the player takes a turn to indicate to them which
					events are adjacent to them. Each event has its own percept phrase, and is referenced
					depending on which event is adjacent to the player. Seperated into two functions to
					follow the 15 line function rule.
	** Parameters: none
	** Pre-Conditions: the user has either moved or fired an arrow since last call
	** Post-Conditions:  percepts from events to the north and south of the player have been printed
	*********************************************************************/
	void percepts();

	/*********************************************************************
	** Function: passage_teleport()
	** Description: when the user is in the same room as a hidden passage event, they 'encounter'
					it by teleporting to the other passage. Which passage they teleport to is 
					dependent on their current location.
	** Parameters: none
	** Pre-Conditions: the user is encountering a hidden passage event (in the same room as one)
	** Post-Conditions: the user successfully teleports to the other hidden passage in the grid
	*********************************************************************/
	void passage_teleport();
	/*********************************************************************
	** Function: pick_up_event()
	** Description: this function is called when the user encounters (is in the same room) either gold 
					or armor. The user 'picks it up' and removes the event from the grid.
	** Parameters: char - name of event
	** Pre-Conditions: the user is in a room with either gold or armor
	** Post-Conditions: the user 'picks' up the armor or gold, and it is removed from the grid
	*********************************************************************/
	void pick_up_event(char);

	/*********************************************************************
	** Function: encounters()
	** Description: this function is called when the user walks into a room that has an event in it. 
					The virtual encounter function is called for that event, and depending on what number is
					returned (each event returns a number specific to them), the program either stops (the user lost)
					or it continues. 
	** Parameters: none
	** Pre-Conditions: the user is in a room with an event 
	** Post-Conditions: the proper encounter message and action is performed/outputted
	*********************************************************************/
	bool encounters();

	/*********************************************************************
	** Function: check_close_room()
	** Description: this function checks to see how many turns have passed since the
					last vacant room had been closed. If five turns have passed, then a new
					random vacant room is closed, so the user can not access it.
	** Parameters: none
	** Pre-Conditions: the grid has been properly constructed and populated
	** Post-Conditions: close_room is incremented or a new closed room is created
	*********************************************************************/
	void check_close_room();
	/*********************************************************************
	** Function: control_game()
	** Description: this is the main game control function of the game. It calls the respective
					functions every round as long as the user has not won or lost the game.
	** Parameters: bool - gameover variable previously created; char - input of player
	** Pre-Conditions: the game is properly set up
	** Post-Conditions: the game is successfully won or lost
	*********************************************************************/
	void control_game(bool, char);

	/*********************************************************************
	** Function: play_game()
	** Description: this function sets up the game, creates essential variables, and calls the
					game control function.
	** Parameters: none
	** Pre-Conditions: the game is properly constructed
	** Post-Conditions: control_game() is called
	*********************************************************************/
	void play_game();
};
#endif