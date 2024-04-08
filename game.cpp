/******************************************************
** Program: game.cpp
** Author: Brian Munger
** Date: 11/28/2023
** Description: this is the main cpp file that contains the functions that make
				the game work. It places events on the grid, displays the grid, checks
				the percepts or encounters, and allows the player to move about the grid.
				The player 
** Input: the user enteres where they would like to go in the grid / if they 
		  would like to fire an arrow and where.
** Output: the program outputs the grid, any percepts, win/lose messages, and any other
		   neccessary messages.
******************************************************/

#include "game.h"
#include <iostream>

using namespace std;


Game::Game(int l, int w, bool d){
	this->length = l;          //length chosen by user
	this->width = w;           //width chosen by user
	this->debug_view = d;      //game mode chosen by user
	this->num_arrows = 3;      //start with 3 arrows
	this->has_gold = false;    //user starts game without the gold
	this->armor_dur = 0;       //user starts game without the armor
	this->wumpus_shot = false; //user starts game not have shot the Wumpus
	this->num_reverse = 0;     //bat has not confused player yet
	this->close_room = 0;      //no turns have passed yet
	this->closed = 0;          //0 rooms start closed
	this->wumpus_row = -1;     //wumpus is not on grid yet
	this->wumpus_col = -1;
}


//default destructor
Game::~Game(){
}


void Game::place_user() {
	//random placement of user 
	//0 to length-1
	player_row = rand() % length;
	//0 to width-1
	player_col = rand() % width;
	//assigns value to member variables 
	starting_row = player_row;
	starting_col = player_col;
}


void Game::place_wumpus() {
	//new wumpus row and collumn to be set
	int w_row;
	int w_col;
	do {
		//0 to length-1
		w_row = rand() % length;
		//0 to width-1
		w_col = rand() % width;
	/*
	 Will keep finding random rooms until a room is found that has no events, does not
	 have the player in it, and is not the room the wumpus was previously in (if relocating)
	 the wumpus.
	*/
	} while ((rooms.at(w_row).at(w_col).get_has_event()) || (w_row == player_row 
	&& w_col == player_col) || (w_row == wumpus_row && w_col == wumpus_col)); 
	//assigns to member variable
	wumpus_row = w_row;
	wumpus_col = w_col;
	//indicates there is an event in the current room, and assigns the event
	rooms.at(wumpus_row).at(wumpus_col).set_has_event(true);
	rooms.at(wumpus_row).at(wumpus_col).set_event(&w);
}


void Game::set_passages(int i, int p_row, int p_col) {
	//if setting the first passage (first for loop iteration)
	if (i == 0){
		//set the first passage variables
		passage1_row = p_row;
		passage1_col = p_col;
	//otherwise...
	} else {
		//set the second passage variables
		passage2_row = p_row;
		passage2_col = p_col;
	}
}


void Game::set_placed_event(char name, int e_row, int e_col) {
	//there is an event as given location
	rooms.at(e_row).at(e_col).set_has_event(true);
	//if gold...
	if (name == 'g')
		rooms.at(e_row).at(e_col).set_event(&g);
	//if armor...
	else if (name == 'a')
		rooms.at(e_row).at(e_col).set_event(&a);
	//if bats...
	else if (name == 'b')
		rooms.at(e_row).at(e_col).set_event(&b);
	//if stacalites...
	else if (name == 's')
		rooms.at(e_row).at(e_col).set_event(&s);
}


void Game::place_event(char name) {
	//event row and collumn to be set
	int e_row;
	int e_col;
	do {
		//0 to length-1
		e_row = rand() % length;
		//0 to width-1
		e_col = rand() % width;
	/*
	Will keep finding random rooms until a room is found that has no events and does
	not have the player in it.
	*/
	} while ((rooms.at(e_row).at(e_col).get_has_event()) || (e_row == player_row 
	&& e_col == player_col)); 
	Game::set_placed_event(name, e_row, e_col);
}


void Game::place_passages() {
	//hidden passage row and collumn to be set
	int p_row;
	int p_col;
	for (int i = 0; i < 2; i++) {
		do {
			//0 to length-1
			p_row = rand() % length;
			//0 to width-1
			p_col = rand() % width;
		/*
		Will keep finding random rooms until a room is found that has no events and does
		not have the player in it.
		*/
		} while ((rooms.at(p_row).at(p_col).get_has_event()) || (p_row == player_row 
		&& p_col == player_col)); 
		rooms.at(p_row).at(p_col).set_has_event(true);
		rooms.at(p_row).at(p_col).set_event(&p);
		Game::set_passages(i, p_row, p_col);
	}
}


void Game::set_up() {
	//initalizes size of array
	Room r;
	rooms.resize(length, vector<Room>(width, r));
	//randomly places user
	Game::place_user();
	//randomly places wumpus
	Game::place_wumpus();
	//randomly places bats
	Game::place_event('b');
	Game::place_event('b');
	//randomly places stalactites
	Game::place_event('s');
	Game::place_event('s');
	//randomly places gold
	Game::place_event('g');
	//randomly places armor
	Game::place_event('a');
	//randomly places hidden passages
	Game::place_passages();
}


void Game::print_event(int i) const {
	for (int j = 0; j < this->width; ++j)
		{
			//prints where player is
			if(i == player_row && j == player_col)
				cout << "*";
			else
				//space for the grid (if no player exists)
				cout << " ";
			if(rooms.at(i).at(j).get_has_event()) {
				//if debug view is chosen 
				if (debug_view) {
					Event* e = rooms.at(i).at(j).get_event();
					//prints symbol (virtual function for event)
					e->print_symbol();
				} else { 
					cout << " ";
				}
				//barriers for the grid
				cout << " ||";
			} else {
				//barriers for the grid (if no event exists)
				cout << "  ||";
			}
		}
}


void Game::display_game() const{
	cout << endl << endl;
	//displays how many arrows there are
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	string line = "";
	//determines how wide the barriers will be
	for (int i = 0; i < this->width; ++i)
		line += "-----";
	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		//calls second display function
		print_event(i);
		cout << endl;
	}
	cout << line << endl;
}


bool Game::check_win() const{
	bool player_win = false;
	//if user returns to starting position AND has the gold
	if (player_row == starting_row && player_col == starting_col) {
		if (has_gold){
			//player wins! output message
			player_win = true;
			cout << "You made it out alive with the gold!! You win!!" << endl;
		}
	}
	//user wins if they shoot the Wumpus
	if (wumpus_shot) {
		player_win = true;
	}
	//returns true if player wins, false otherwise
	return player_win;
}


void Game::move_up() {
	bool border_reached = false;
	//won't move player up if they are as north as possible
	if ((player_row - 1) == -1) {
		cout << "Can not travel futher north, there is a wall!" << endl;
		border_reached = true;
	} else if (border_reached == false) {
		if (rooms.at(player_row-1).at(player_col).get_has_event()) {
			Event* e = rooms.at(player_row-1).at(player_col).get_event();
			if (e->is_closed())
				cout << "Can not travel north, that room is closed!" << endl;
			else
				player_row--;
		} else {
			player_row--;
		}
	} else {
		//otherwise, moves player up one
		player_row--;
	}
}


void Game::move_down() {
	bool border_reached = false;
	//won't move player down if they are as south as possible
	if ((player_row + 1) == length) {
		cout << "Can not travel futher south, there is a wall!" << endl;
		border_reached = true;
	} else if (border_reached == false) {
		if (rooms.at(player_row+1).at(player_col).get_has_event()) {
			Event* e = rooms.at(player_row+1).at(player_col).get_event();
			if (e->is_closed())
				cout << "Can not travel south, that room is closed!" << endl;
			else
				player_row++;
		} else {
			player_row++;
		}
	} else {
		//otherwise, moves player down one
		player_row++;
	}
}


void Game::move_left() {
	bool border_reached = false;
	//won't move player left if they are as west as possible
	if ((player_col - 1) == -1) {
		cout << "Can not travel futher west, there is a wall!" << endl;
		border_reached = true;
	} else if (border_reached == false) {
		if (rooms.at(player_row).at(player_col-1).get_has_event()) {
			Event* e = rooms.at(player_row).at(player_col-1).get_event();
			if (e->is_closed())
				cout << "Can not travel west, that room is closed!" << endl;
			else
				player_col--;
		} else {
			player_col--;
		}
	} else { 
		//otherwise, moves player left one
		player_col--;
	}
}


void Game::move_right() {
	bool border_reached = false;
	//won't move player right if they are as east as possible
	if ((player_col + 1) == width) {
		cout << "Can not travel futher east, there is a wall!" << endl;
		border_reached = true;
	} else if (border_reached == false) {
		if (rooms.at(player_row).at(player_col+1).get_has_event()) {
			Event* e = rooms.at(player_row).at(player_col+1).get_event();
			if (e->is_closed())
				cout << "Can not travel east, that room is closed!" << endl;
			else
				player_col++;
		} else {
			player_col++;
		}
	} else { 
		//otherwise, moves player right one
		player_col++;
	}
}


char Game::get_dir(){
	//get direction of arrow:
	char dir;
	do {
		//prompts the user to enter the direction of the user
		cout << "Fire an arrow...." << endl;
		cout << "W-up" << endl;
		cout << "A-left" << endl;
		cout << "S-down" << endl;
		cout << "D-right" << endl;

		cout << "Enter direction: " << endl;
		cin >> dir;
		cin.ignore(256, '\n');
	//ensures the user enters a proper direction (wasd)
	} while (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd');
	//returns the direction of the user
	return dir;
}


void Game::shoot_wumpus() {
	//displays when Wumpus is shot
	cout << "Great shot!! You shot and killed the Wumpus! You win!!" << endl;
	//removes the Wumpus from the game
	rooms.at(wumpus_row).at(wumpus_col).set_event(nullptr);
	rooms.at(wumpus_row).at(wumpus_col).set_has_event(false);
	//they win!
	wumpus_shot = true;
}


void Game::missed_shot() {
	//75% percent chance the Wumpus will move to a random room if the user misses 
	if (rand() % 4 != 1) {
		cout << "You missed! The wumpus wakes up and moves to a random empty room." << endl;
		//removes the Wumpus from the grid
		rooms.at(wumpus_row).at(wumpus_col).set_event(nullptr);
		rooms.at(wumpus_row).at(wumpus_col).set_has_event(false);
		//places the Wumpus into a new random room
		Game::place_wumpus();
	//25% percent chance the Wumpus does not move to a random room
	} else {
		cout << "You missed! Luckily, your shot does not wake up the Wumpus. " << endl;
	}
}


void Game::fire_up() {
	//indicates if the Wumpus was hit
	bool wumpus_hit = false;
	int counter = 1;
	//checks three rooms (distance arrow can travel)
	for (int i = 3; i > 0; i--) {  
		//ensures the player can fire the arrow (it won't hit a wall)  
		if (player_row != (3-i)) { 
			//if Wumpus is shot...   
			if (wumpus_row == player_row-(counter) && wumpus_col == player_col) {
				Game::shoot_wumpus();
				wumpus_hit = true;
				break;
			}
		} else { 
			//arrow hit a wall (player was within three spaces of the wall)
			cout << "Your arrow hit a wall!" << endl;
		}
		counter++;
	} 
	//calls function if the Wumpus is not shot
	if (!wumpus_hit)
		Game::missed_shot();
}


void Game::fire_down() {
	//indicates if the Wumpus was hit
	bool wumpus_hit = false;
	int counter = 1;
	//checks three rooms (distance arrow can travel)
	for (int i = 1; i < 4; i++) {    
		//ensures the player can fire the arrow (it won't hit a wall
		if (player_row != (length-i)) {
			//Wumpus hit
			if (wumpus_row == player_row+(counter) && wumpus_col == player_col) {
				Game::shoot_wumpus();
				wumpus_hit = true;
				break;
			}
		} else { 
			//arrow hit a wall (player was within three spaces of the wall)
			cout << "Your arrow hit a wall!" << endl;
		}
		counter++;
	} 
	//calls function if the Wumpus is not shot
	if (!wumpus_hit) 
		Game::missed_shot();
}


void Game::fire_right() {
	//indicates if the Wumpus was hit
	bool wumpus_hit = false;
	int counter = 1;
	//checks three rooms (distance arrow can travel)
	for (int i = 1; i < 4; i++) {    
		//ensures the player can fire the arrow (it won't hit a wall
		if (player_col != (width-i)) {
			//Wumpus hit
			if (wumpus_row == player_row && wumpus_col == player_col+(counter)) {
				Game::shoot_wumpus();
				wumpus_hit = true;
				break;
			}
		} else { 
			//arrow hit a wall (player was within three spaces of the wall)
			cout << "Your arrow hit a wall!" << endl;
		}
		counter++;
	} 
	//calls function if the Wumpus is not shot
	if (!wumpus_hit) 
		Game::missed_shot();
}


void Game::fire_left() {
	//indicates if the Wumpus was hit
	bool wumpus_hit = false;
	int counter = 1;
	//checks three rooms (distance arrow can travel)
	for (int i = 3; i > 0; i--) {    
		//ensures the player can fire the arrow (it won't hit a wall
		if (player_col != (3-i)) {  
			//Wumpus hit 
			if (wumpus_row == player_row && wumpus_col == player_col-(counter)) {
				Game::shoot_wumpus();
				wumpus_hit = true;
				break;
			}
		} else {
			//arrow hit a wall (player was within three spaces of the wall) 
			cout << "Your arrow hit a wall!" << endl;
		}
		counter++;
	} 
	//calls function if the Wumpus is not shot
	if (!wumpus_hit) 
		Game::missed_shot();
}


void Game::fire_arrow(){
	//gets direction of arrow
	char dir = get_dir();
	//w = up
	if (dir == 'w')
		Game::fire_up();
	//s = down
	else if (dir == 's') 
		Game::fire_down();
	//d = right
	else if (dir == 'd')
		Game::fire_right();
	//a = left
	else if (dir == 'a')
		Game::fire_left();
	num_arrows--;
}


void Game::check_arrows() {
	//if there is at least one arrow...
	if(num_arrows > 0) 
		Game::fire_arrow();
	//if no arrows are left...
	else
		cout << "Bummer! Can't fire an arrow, you don't have any left!" << endl;
}


void Game::move(char c) {	
	//calls the arrow fire function if the user enters 'f'
	if (c == 'f'){
		Game::check_arrows();
		return;
	}
	switch(c){
		//calls move up function if the user enters 'w'
		case 'w':
			Game::move_up();
			break;
		//calls move left function if the user enters 'a'
		case 'a':
			Game::move_left();
			break;
		//calls move down function if the user enters 's'
		case 's':
			Game::move_down();
			break;
		//calls move right function if the user enters 'd'
		case 'd':
			Game::move_right();
			break;
	}
}


void Game::move_reverse(char c) {
	//calls the arrow fire function if the user enters 'f'
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	switch(c){
		//calls move down function if the user enters 'w'
		case 'w':
			Game::move_down();
			break;
		//calls move right function if the user enters 'a'
		case 'a':
			Game::move_right();
			break;
		//calls move up function if the user enters 's'
		case 's':
			Game::move_up();
			break;
		//calls move left function if the user enters 'd'
		case 'd':
			Game::move_left();
			break;
	}
}


char Game::get_input(){
	//get action, move direction or firing an arrow
	char c;
	//prompts the user to enter either 'wasd' to move or 'f' to fire an arrow
	do {
		//spacing
		cout << endl << endl << "Player move..." << endl << endl;
		cout << "W-up" << endl;
		cout << "A-left" << endl;
		cout << "S-down" << endl;
		cout << "D-right" << endl;
		cout << "f-fire an arrow" << endl;

		cout << "Enter input: " << endl;
		//collects users input
		cin >> c;
		cin.ignore(256, '\n');
	//error checks that the user entered either 'wasd' or 'f'
	} while (c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'f');

	return c;
}


void Game::percepts_2() {
	//second percepts function (to follow 15 line function r)
	if (player_col != 0) {
		//checks event percept left 1 from user
		if (rooms.at(player_row).at(player_col-1).get_has_event()) {          
			Event* e = rooms.at(player_row).at(player_col-1).get_event();
			//calls virtual percept function for that event
			e->percept();
		}
	}
	if (player_col != (width-1)) {
		//checks event percept right 1 from user
		if (rooms.at(player_row).at(player_col+1).get_has_event()) {          
			Event* e = rooms.at(player_row).at(player_col+1).get_event();
			//calls virtual percept function for that event
			e->percept();
		} 
	}
}


void Game::percepts() {
	//first percept function
	if (player_row != 0) {
		//checks event percept up 1 from user
		if (rooms.at(player_row-1).at(player_col).get_has_event()) {            
			Event* e = rooms.at(player_row-1).at(player_col).get_event();
			//calls virtual percept function for that event
			e->percept();
		}
	}
	if (player_row != (length-1)) {
		//checks event percept down 1 from user
		if (rooms.at(player_row+1).at(player_col).get_has_event()) {         
			Event* e = rooms.at(player_row+1).at(player_col).get_event();
			//calls virtual percept function for that event
			e->percept();
		}
	}
	//calls second percept function
	percepts_2();
}


void Game::passage_teleport(){
	//if users position is the same as the first passages location
	if (passage1_row == player_row && passage1_col == player_col) {
		//move them to the second passages location
		player_row = passage2_row;
		player_col = passage2_col;
	//if users position is the same as the second passages location
	} else if (passage2_row == player_row && passage2_col == player_col) {
		//move them to the first passages location
		player_row = passage1_row;
		player_col = passage1_col;
	}
}

 
void Game::pick_up_event(char name) {
	//if picking up gold...
	if (name == 'g')
		has_gold = true;
	//if picking up armor...
	else if (name == 'a')
		armor_dur = 2;
	//removes event from grid
	rooms.at(player_row).at(player_col).set_event(nullptr);
	rooms.at(player_row).at(player_col).set_has_event(false);
}


bool Game::encounters() {
	//gets the event that is in the room with the player
	Event* e = rooms.at(player_row).at(player_col).get_event();
	int encounter_num = e->encounter(armor_dur);
	//1 = wumpus kills player
	//2 = stalactite falls, kills player
	if (encounter_num == 1 || encounter_num == 2) {   
		//gameover
		return true;
	//4 = stalactite doesn't fall
	} else if (encounter_num == 4) { 
		num_reverse = 5;
	//5 = gold is picked up
	} else if (encounter_num == 5) { 
		//removes gold from the grid
		Game::pick_up_event('g');
	//6 = player teleports via hidden passage
	} else if (encounter_num == 6) {
		//calls teleport function
		Game::passage_teleport();
	//7 = armor is picked up
	} else if (encounter_num == 7) {
		//removes armor from the grid
		Game::pick_up_event('a');
	//8 or 9 = armor protects player
	} else if (encounter_num == 8 || encounter_num == 9) {
		//decreases armor durability
		armor_dur--;
	}
	//game continues
	return false;
}


void Game::check_close_room() {
	//increments close room counter variable
	close_room++;
	if (close_room == 5) {
		int c_row;
		int c_col;
		//resets variable to 0 when 5 turns pass
		close_room = 0;
		do {
			//0 to length-1
			c_row = rand() % length;
			//0 to width-1
			c_col = rand() % width;
		/*
	 	Will keep finding random rooms until a room is found that has no events, does not
	 	have the player in it, and is not the starting position.
		*/
		} while ((rooms.at(c_row).at(c_col).get_has_event()) || (c_row == player_row 
		&& c_col == player_col) || (c_row == starting_row && c_col == starting_col));
		//closes an open room 
		rooms.at(c_row).at(c_col).set_has_event(true);
		rooms.at(c_row).at(c_col).set_event(&c); 
		cout << "Yikes. A room has been closed off. " << endl; 
	}
}


void Game::control_game(bool gameover, char input) {
	while ((Game::check_win() == false) && (gameover == false)){
		check_close_room();
		//print game board
		Game::display_game();
		//display percerts around player's location
		Game::percepts();

		//Player move
		//1. get input
		input = Game::get_input();
		//2. move player
		if (num_reverse == 0)
			Game::move(input);
		else	
			Game::move_reverse(input);

		//3. encounter events
		if (rooms.at(player_row).at(player_col).get_has_event() && !gameover)
			gameover = Game::encounters();
		if (closed == ((length*width) - 11)) {
			cout << "Most of rooms are closed! Can't get back to the start now. GAME OVER!" << endl;
			gameover = true;
		}
	}
}


//Note: you need to modify this function
void Game::play_game(){
	//sets up the game 
	Game::set_up();
	//tracks if user dies (ends game)
	bool gameover = false;
	//variable for user input
	char input = 'a';
	control_game(gameover, input);
}