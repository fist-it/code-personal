#include <iostream>
#include <time.h>
#include <ncurses.h>

using namespace std;


//BOARD
const int BOARD_SIZE = 24;
const int END = BOARD_SIZE - 1;
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 10;

//MENU
const int OPTION1_X = 25;
const int OPTION1_Y = 10;
const int OPTION2_X = 25;
const int OPTION2_Y = 11;
const int OPTION3_X = 25;
const int OPTION3_Y = 12;
const int OPTION4_X = 25;
const int OPTION4_Y = 13;



//struct
typedef struct
{
	int board[BOARD_SIZE];
	int dice[2];
	int turn;
	int home[2];
	int menu;
} backgammon_t;

int roll()
{
	return rand() % 6 + 1;
}



void choose_start_roll(int *turn)
{
	int dice1 = roll();
	int dice2 = roll();

	if (dice1 > dice2)
	{
		*turn = 0;
	}
	else if (dice1 < dice2)
	{
		*turn = 1;
	}
	else
	{
		cout << "Same score, roll again" << endl;
		choose_start_roll(turn);
	}
}




void draw_board(backgammon_t *game)
{
	clear();
	
}

void init(backgammon_t* game)
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	raw();
	init_game_var(game);
	init_player1(game);
	init_player2(game);
	choose_start_roll(&(game->turn));
}

//MENU
void menu_first(){
	mvprintw(OPTION1_X, OPTION1_Y, ">");
	mvprintw(OPTION2_X, OPTION2_Y, " ");
	mvprintw(OPTION3_X, OPTION3_Y, " ");
	mvprintw(OPTION4_X, OPTION4_Y, " ");
}

void menu_second(){
	mvprintw(OPTION1_X, OPTION1_Y, " ");
	mvprintw(OPTION2_X, OPTION2_Y, ">");
	mvprintw(OPTION3_X, OPTION3_Y, " ");
	mvprintw(OPTION4_X, OPTION4_Y, " ");
}

void menu_third(){
	mvprintw(OPTION1_X, OPTION1_Y, " ");
	mvprintw(OPTION2_X, OPTION2_Y, " ");
	mvprintw(OPTION3_X, OPTION3_Y, ">");
	mvprintw(OPTION4_X, OPTION4_Y, " ");
}

void menu_fourth(){
	mvprintw(OPTION1_X, OPTION1_Y, " ");
	mvprintw(OPTION2_X, OPTION2_Y, " ");
	mvprintw(OPTION3_X, OPTION3_Y, " ");
	mvprintw(OPTION4_X, OPTION4_Y, ">");
}


void menu_update(int menu){
	switch(menu){
		case 0:
			//  ">" on first option
			menu_first();
			break;
		case 1:
			//  ">" on second option
			menu_second();
			break;
		case 2:
			//  ">" on third option
			menu_third();
			break;
		case 3:
			//  ">" on fourth option
			menu_fourth();
			break;
	}
	refresh();
}


//INIT

void init_player1(backgammon_t *game)
{
	game->board[0] = 2;
	game->board[11] = 5;
	game->board[16] = 3;
	game->board[18] = 5;
}

void init_player2(backgammon_t *game)
{
	game->board[END - 0] = 2;
	game->board[END - 11] = 5;
	game->board[END - 16] = 3;
	game->board[END - 18] = 5;
}

int init_game_var(backgammon_t *game)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		game->board[i] = 0;
	}
	game->dice[0] = 0;
	game->dice[1] = 0;
	game->home[0] = 0;
	game->home[1] = 0;
	game->menu = 0;
	return 0;
}

int init_game(backgammon_t* game){
	int ch = getch();
	while (ch != 'q')
	{
		switch (ch)
		{
			case KEY_UP:
				game->menu++;
				game->menu %= 4;
				menu_update(game->menu);
			case KEY_DOWN:
				game->menu--;
				game->menu %= 4;
				menu_update(game->menu);
			case KEY_ENTER:
				switch(game->menu){
					case 0:
						//roll
					case 1:
						//save game
					case 2:
						//load game
					case 3:
						//exit
						exit(0);
				}
		}
	}
}

int main() {
	backgammon_t game;
	init(&game);
	init_game(&game);
	
}
