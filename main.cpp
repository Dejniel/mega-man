#include <iostream>
#include "windows.h"
#include "Level.h"
#include <ncursesw/ncurses.h>
#include "player.h"

void preparation()
{
	curs_set(0);					// Hide terminal cursor;
	keypad(stdscr, TRUE); // Getch() now sees arrows (up, down, left, right);
	timeout(40);					// After xms game continues even without input 1s(1000ms)
	noecho();							// Don't print keypresses in terminal;
}
void cleanup(WINDOW *mainwin)
{
	attroff(COLOR_PAIR(1)); // return to default color
	delwin(mainwin);				// ncurses exit cleanup
	endwin();
	refresh();
}
/*
TODO:
-add enemies
-add shooting
-add levels
*/
int menu(){
	int input = getch();
		if (input != ERR)
		{
			switch (input)
			{
			case 'e':
				return true;
				break;	
			}
		}
	return false;
}

int main(void)
{
	WINDOW *mainwin = initscr();
	box(mainwin, '|', '-'); 
	preparation();
	Level room;
	while(1){
		if(menu()){
			break;
		}
	}
	Player player(15, 15, 1, 100, '@', 1, 2, &room); // pos_x, pos_y, speed, health, repr, dim_x, dim_y
	
	while (true)																 // Game loop
	{
//		box(mainwin, '|', '-'); 
		room.print_level();
		player.print_character();
		if (player.movement_handler() == 1)
			break;
		refresh();
		clear();
	}
				 
	cleanup(mainwin);
	return EXIT_SUCCESS;
	
}
                     