/******************************************************
** Program: main.cpp 
** Author: Brian Munger
** Date: 11/28/2023
** Description: contains the main() function and therefore
				is the driver file for the program. Gathers from
				the user what the width and length of the game
				grid will be, along with which mode the game will be
				played in.
** Input: user enters the width and length of the grid (integers), and
		  if the game will be in normal or debug mode (integer)
** Output: welcome statement, prompts the user for the width and length
		   of the cave, and prompts the user for what mode the game will
		   be played in 
******************************************************/

#include <iostream>  //for user input and output
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

/*********************************************************************
** Function: get_width()
** Description: this function gathers what the width of the cave grid will be,
			    and checks to ensure it is between 4 and 50, which is the accepted
				range of this assignment.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: a user entered width between 4 and 50 is returned. 
*********************************************************************/
int get_width() {
	int width;
	do {
	cout << "Enter the width of the cave (4-50): ";
	cin >> width;
	} while (width < 4 || width > 50);  //checks that user enters a number between 4 and 50
	return width;                       //width is returned
} 


/*********************************************************************
** Function: get_length()
** Description: this functions gathers what the length of the cave grid will be,
				and checks to ensure it is between 4 and 50, which is the accepted
				range of this assignment.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: a user entered length between 4 and 50 is returned. 
*********************************************************************/
int get_length() {
	int length;
	do {
	cout << "Enter the length of the cave (4-50): ";
	cin >> length;
	} while (length < 4 || length > 50);  //checks that user enters a number between 4 and 50
	return length;                        //length is returned
}


/*********************************************************************
** Function: get_debug()
** Description: this functions prompts the user to choose to either play the game normally
				or in debug mode, which will show all of the symbols of the events. Error
				checking is included by ensuring the user enters 1 or 0 (debug or normal).
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: 1 is returned to enter debug mode, or 0 is returned to play normally. 
*********************************************************************/
bool get_debug() {
	int debug;
	cout << "Would you like to activate the debug mode?" << endl;
	do {
		cout << "Enter 1 to activate the debug mode, or 0 to play normally: ";
		cin >> debug;
	} while (debug != 0 && debug != 1);
	if (debug == 1)           //if the user enters 1, game enters debug mode
		return true;
	return false;             //otherwise game runs normally 
} 

/*********************************************************************
** Function: main()
** Description: driver function for the Hunt the Wumpus game. Gets the game parameters,
				constructs the game, and calls the play game function.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: game was successfully played. Results in a win or lose. 
*********************************************************************/
int main()
{
	//set the random seed
	srand(time(NULL));                           
	cout << "Welcome to Hunt the Wumpus!" << endl;

	//gets parameters of game from user
	int width = get_width();
	int length = get_length();
	bool debug = get_debug();
	
	//constructs game given user entered parameters
	Game g(width, length, debug);
	//calls game control function
	g.play_game();

}