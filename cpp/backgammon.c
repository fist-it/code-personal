#include <stdlib.h>
#include <ncurses.h>
#include <time.h>


/*
WHITE - 1
BLACK - 0

board:
WHITE > 0
BLACK < 0
*/

// BOARD
const int BOARD_SIZE = 24;
const int LEFT = 3;
const int RIGHT = 48;
const int DOWN = 19;
const int UP = 3;
const int BOARD_WIDTH = 45;
const int BOARD_HEIGHT = 16;
const int BAR_L = 23;
const int BAR_R = 28;
const int BAR_Y = 11;

// MENU
const int OPTION_X = 52;
const int OPTION_Y = 4;
const int INFO_X = 2;
const int INFO_Y = 23;

const int NUMBER_INPUT_Y = 21;
const int NUMBER_INPUT_X = 44;

const int DICE_DEBUG_X = 3;
const int DICE_DEBUG_Y = 26;

const int PLAYER_INFO_Y = 21;
const int PLAYER_INFO_X = 2;

const int DEBUG_BOARD_Y = 28;
const int DEBUG_BOARD_X = 3;

const int WARNING_Y = 25;
const int WARNING_X = 20;

const int HIT_X = 52;
const int HIT_Y = 12;

const int COMEBACK_X = 52;
const int COMEBACK_Y = 10;

const int HOME_X = 10;
const int HOME_Y = 30;
//PLAYER2 ON Y=22

const int BAR_DEBUG_X = 20;
const int BAR_DEBUG_Y = 27;

// struct
typedef struct
{
	int board[BOARD_SIZE];
	int dice[2];
	int turn;
	int home[2];
	int at_home[2];
	int menu;
	int bar[2];
} backgammon_t;

//LOADERS


void load_upper_right_white(backgammon_t *game)
{
	
	for (int i = 0; i < 6; i++)
	{
		int j = 0;
		while (j < game->board[i] && j < 5)
		{
			mvprintw(UP + 1 + j, RIGHT - 2 - (i * 3), "W");
			mvprintw(UP + 1 + j, RIGHT - 3 - (i * 3), "W");
			j++;
		}
		if (game->board[i] > 5)
		{
			if (game->board[i] < 15)
			{
				mvprintw(UP + 6, RIGHT - 3 - (i * 3), "+%d", game->board[i] - 5);
			}
			else
			{
				mvprintw(UP + 6, RIGHT - 4 - (i * 3), "+%d", (game->board[i] - 5));
			}
		}
	}
}

void load_upper_right_black(backgammon_t *game)
{
	
	for (int i = 0; i < 6; i++)
	{
		int j = 0;
		if (game->board[i] < 0)
		{

			while (j < (-1 * game->board[i]) && j < 5)
			{
				mvprintw(UP + 1 + j, RIGHT - 2 - (i * 3), "B");
				mvprintw(UP + 1 + j, RIGHT - 3 - (i * 3), "B");
				j++;
			}
			if (-1 * game->board[i] > 5)
			{
				if (-1 * game->board[i] < 15)
				{
					mvprintw(UP + 6, RIGHT - 3 - (i * 3), "+%d", -(5 + game->board[i]));
				}
				else
				{
					mvprintw(UP + 6, RIGHT - 4 - (i * 3), "+%d", -(5 + game->board[i]));
				}
			}
		}
	}
}

void load_upper_left_white(backgammon_t *game)
{
	
	for (int i = 0; i < 6; i++)
	{
		int j = 0;
		if (game->board[6 + i] > 0)
		{
			while (j < game->board[6 + i] && j < 5)
			{
				mvprintw(UP + 1 + j, BAR_L - 2 - (i * 3), "W");
				mvprintw(UP + 1 + j, BAR_L - 3 - (i * 3), "W");
				j++;
			}
			if (game->board[i + 6] > 5)
			{
				if (game->board[i + 6] < 15)
				{
					mvprintw(UP + 6, BAR_L - 3 - (i * 3), "+%d", game->board[i + 6] - 5);
				}
				else
				{
					mvprintw(UP + 6, BAR_L - 4 - (i * 3), "+%d", game->board[i + 6] - 5);
				}
			}
		}
	}
}

void load_upper_left_black(backgammon_t *game)
{
	
	for (int i = 0; i < 6; i++)
	{
		int j = 0;
		if (game->board[6 + i] < 0)
		{
			while (j < (-1 * game->board[6 + i]) && j < 5)
			{
				mvprintw(UP + 1 + j, BAR_L - 2 - (i * 3), "B");
				mvprintw(UP + 1 + j, BAR_L - 3 - (i * 3), "B");
				j++;
			}
			if (-1 * game->board[i + 6] > 5)
			{
				if (-1 * game->board[i + 6] < 15)
				{
					mvprintw(UP + 6, BAR_L - 3 - (i * 3), "+%d", -(5 + game->board[i + 6]));
				}
				else
				{
					mvprintw(UP + 6, BAR_L - 4 - (i * 3), "+%d", -(5 + game->board[i + 6]));
				}
			}
		}
	}
}

void load_lower_left_white(backgammon_t *game)
{
	
	for (int i = 0; i < 6; i++)
	{
		int j = 0;
		if (game->board[12 + i] > 0)
		{
			while (j < game->board[12 + i] && j < 5)
			{
				mvprintw(DOWN - 1 - j, LEFT + 2 + (i * 3), "W");
				mvprintw(DOWN - 1 - j, LEFT + 3 + (i * 3), "W");
				j++;
			}
			if (game->board[i + 12] > 5)
			{
				if (game->board[i + 12] < 15)
				{
					mvprintw(DOWN - 6, LEFT + 2 + (i * 3), "+%d", game->board[i + 12] - 5);
				}
				else
				{
					mvprintw(DOWN - 6, LEFT + 1 + (i * 3), "+%d", game->board[i + 12] - 5);
				}
			}
		}
	}
}

void load_lower_left_black(backgammon_t *game)
{
	
	for (int i = 0; i < 6; i++)
	{
		int j = 0;
		if (game->board[12 + i] < 0)
		{
			while (j < (-1 * game->board[12 + i]) && j < 5)
			{
				mvprintw(DOWN - 1 - j, LEFT + 2 + (i * 3), "B");
				mvprintw(DOWN - 1 - j, LEFT + 3 + (i * 3), "B");
				j++;
			}
			if (-1 * game->board[i + 12] > 5)
			{
				if (-1 * game->board[i + 12] < 15)
				{
					mvprintw(DOWN - 6, LEFT + 2 + (i * 3), "+%d", -(5 + game->board[i + 12]));
				}
				else
				{
					mvprintw(DOWN - 6, LEFT + 1 + (i * 3), "+%d", -(5 + game->board[i + 12]));
				}
			}
		}
	}
}

void load_lower_right_black(backgammon_t *game)
{
	
	for (int i = 0; i < 6; i++)
	{
		int j = 0;
		if (game->board[18 + i] < 0)
		{
			while (j < (-1 * game->board[18 + i]) && j < 5)
			{
				mvprintw(DOWN - 1 - j, BAR_R + 2 + (i * 3), "B");
				mvprintw(DOWN - 1 - j, BAR_R + 3 + (i * 3), "B");
				j++;
			}
			if (-1 * game->board[i + 18] > 5)
			{
				if (-1 * game->board[i + 18] < 15)
				{
					mvprintw(DOWN - 6, BAR_R + 2 + (i * 3), "+%d", -(5 + game->board[i + 18]));
				}
				else
				{
					mvprintw(DOWN - 6, BAR_R + 1 + (i * 3), "+%d", -(5 + game->board[i + 18]));
				}
			}
		}
	}
}

void load_lower_right_white(backgammon_t *game)
{
	
	for (int i = 0; i < 6; i++)
	{
		int j = 0;
		if (game->board[18 + i] > 0)
		{
			while (j < game->board[18 + i] && j < 5)
			{
				mvprintw(DOWN - 1 - j, BAR_R + 2 + (i * 3), "W");
				mvprintw(DOWN - 1 - j, BAR_R + 3 + (i * 3), "W");
				j++;
			}
			if (game->board[i + 18] > 5)
			{
				if (game->board[i + 18] < 15)
				{
					mvprintw(DOWN - 6, BAR_R + 2 + (i * 3), "+%d", game->board[i + 18] - 5);
				}
				else
				{
					mvprintw(DOWN - 6, BAR_R + 1 + (i * 3), "+%d", game->board[i + 18] - 5);
				}
			}
		}
	}
}

void load_bar_white(backgammon_t* game){
	int j = 0;
	while(j < game->bar[0] && j < 6){
		mvprintw(BAR_Y - 2 - j, BAR_L + 2, "WW");
		j++;
	}
	if(game->bar[0] > 5){
		mvprintw(BAR_Y - 7, BAR_L + 2, "+%d", game->bar[0]-5);
	}
}

void load_bar_black(backgammon_t* game){
	int j = 0;
	while(j < game->bar[1] && j < 6){
		mvprintw(BAR_Y + 2 + j, BAR_L + 2, "BB");
		j++;
	}
	if(game->bar[1] > 5){
		mvprintw(BAR_Y + 7, BAR_L + 2, "+%d", game->bar[1]-5);
	}
}

void load_bar(backgammon_t* game){
	load_bar_white(game);
	load_bar_black(game);
}

void clear_bar(){
	for(int i=0; i<6; i++){
		mvprintw(BAR_Y - 1 - i, BAR_L + 2, "  ");
		mvprintw(BAR_Y + 1 + i, BAR_L + 2, "  ");
	}
}

void clear_bar_info(){
	move(WARNING_Y-1, WARNING_X);
	clrtoeol();
}

void load_board(backgammon_t game)
{
	load_upper_right_white(&game);
	load_upper_right_black(&game);
	load_upper_left_white(&game);
	load_upper_left_black(&game);
	load_lower_left_white(&game);
	load_lower_left_black(&game);
	load_lower_right_white(&game);
	load_lower_right_black(&game);
	clear_bar();
	load_bar(&game);
}

void debug_board(backgammon_t game)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		mvprintw(DEBUG_BOARD_Y + i, DEBUG_BOARD_X, " %d : %d", i,  game.board[i]);
	}
}

void print_home(backgammon_t* game){
	mvprintw(HOME_Y, HOME_X, "White pawns at home: %d", game->at_home[0]);
	mvprintw(HOME_Y+1, HOME_X, "Black pawns at home: %d", game->at_home[1]);
}
//input long numbers
void clear_number(){
	move(NUMBER_INPUT_Y, NUMBER_INPUT_X);
	clrtoeol();
}

void clear_hit(){
	move(HIT_Y, HIT_X);
	clrtoeol();
}

void exit_game()
{
	clear();
	echo();
	endwin();
	exit(0);
}

int get_number()
{
	int number = 1;
	mvprintw(NUMBER_INPUT_Y, NUMBER_INPUT_X, "%d", number);
	while (1)
	{
		int ch = getch();
		switch (ch)
		{
		case KEY_UP:
			clear_number();
			number++;
			if(number > 24){
				number = 1;
			}
			mvprintw(NUMBER_INPUT_Y, NUMBER_INPUT_X, "%d", number);
			break;
		case KEY_DOWN:
		
			clear_number();
			if(number == 1){
				number = 25;
			}
			number--;
			mvprintw(NUMBER_INPUT_Y, NUMBER_INPUT_X, "%d", number);
			break;
		case KEY_RIGHT:
			clear_number();
			return number-1;
		case KEY_LEFT:
			exit_game();
			break;
		}
	}
}

void print_dice(backgammon_t* game){
	mvprintw(DICE_DEBUG_Y, DICE_DEBUG_X, "Dice 1 = %d", game->dice[0]);
	mvprintw(DICE_DEBUG_Y + 1, DICE_DEBUG_X, "Dice 2 = %d", game->dice[1]);
}

void clear_info()
{
	move(INFO_Y, INFO_X);
	clrtoeol();
}

void clear_comeback(){
	move(COMEBACK_Y, COMEBACK_X);
	clrtoeol();
}

void clear_bar_debug(){
	move(BAR_DEBUG_Y, BAR_DEBUG_X);
	clrtoeol();
	move(BAR_DEBUG_Y+1, BAR_DEBUG_X);
	clrtoeol();
}

void count_home(backgammon_t *game)
{
	game->home[0] = game->at_home[0];
	game->home[1] = game->at_home[0];
	for (int i = 0; i < 6; i++)
	{
		if(game->board[BOARD_SIZE-i-1]>0){
			game->home[0] = game->home[0] + game->board[BOARD_SIZE-i-1];
		}
	}
	for(int i=0; i<6; i++){
		if(game->board[i]<0){
			game->home[1] += -1*game->board[i];
		}
	}

}

void load_rest(backgammon_t* game, FILE *fp){
		fscanf(fp, "%d", &game->dice[0]);
		fscanf(fp, "%d", &game->dice[1]);
		fscanf(fp, "%d", &game->turn);
		fscanf(fp, "%d", &game->at_home[0]);
		fscanf(fp, "%d", &game->at_home[1]);
		fscanf(fp, "%d", &game->menu);
		fscanf(fp, "%d", &game->bar[0]);
		fscanf(fp, "%d", &game->bar[1]);
		game->home[0] = 0;
		game->home[1] = 0;
}

void load_from_file(backgammon_t* game){
	FILE *fp;
	fp = fopen("save.txt", "r");
	if(fp == NULL){
		mvprintw(WARNING_Y, WARNING_X, "No save file!");
		mvprintw(OPTION_Y, OPTION_X-1, " ");
	}
	else{
		for(int i=0; i<BOARD_SIZE; i++){
			if(i < 12){
				fscanf(fp, "%d ", &game->board[11-i]);
				if(i == 11){
					fscanf(fp, "\n");
				}
			}
			else{
				fscanf(fp, "%d", &game->board[i]);
			}
		}
		load_rest(game, fp);
		fclose(fp);
		mvprintw(OPTION_Y+2, OPTION_X-1, " ");
		clear_info();
	}
	count_home(game);
	print_home(game);
}

void save_rest(backgammon_t* game, FILE *fp){
	fprintf(fp, "\n");
	fprintf(fp, "%d ", game->dice[0]);
	fprintf(fp, "%d ", game->dice[1]);
	fprintf(fp, "\n");
	fprintf(fp, "%d ", game->turn);
	fprintf(fp, "\n");
	fprintf(fp, "%d ", game->at_home[0]);
	fprintf(fp, "%d ", game->at_home[1]);
	fprintf(fp, "\n");
	fprintf(fp, "%d ", game->menu);
	fprintf(fp, "\n");
	fprintf(fp, "%d ", game->bar[0]);
	fprintf(fp, "%d ", game->bar[1]);
}

void save_to_file(backgammon_t* game){
	FILE *fp;
	fp = fopen("save.txt", "w");
	for(int i=0; i<BOARD_SIZE; i++){
		if(i < 12){
			fprintf(fp, "%d ", game->board[11-i]);
			if(i == 11){
				fprintf(fp, "\n");
			}
		}
		else{
			fprintf(fp, "%d ", game->board[i]);
		}
	}
	save_rest(game, fp);
	fclose(fp);
}

// GUI

void clear_double()
{
	move(INFO_Y+1, INFO_X);
	clrtoeol();
}

void clear_warning()
{
	for(int i=0; i<15; i++){
		mvprintw(WARNING_Y, WARNING_X+i, " ");
	}
}

void clear_player_info()
{
	move(PLAYER_INFO_Y, PLAYER_INFO_X);
	clrtoeol();
	move(PLAYER_INFO_Y + 1, PLAYER_INFO_X);
	clrtoeol();
}

void draw_borders()
{
	// HORIZONTAL BORDERS
	for (int i = 0; i <= BOARD_WIDTH; i++)
	{
		mvprintw(UP, LEFT + i, "=");
		mvprintw(DOWN, LEFT + i, "=");
	}
	// VERTICAL BORDERS
	for (int i = 1; i < BOARD_HEIGHT; i++)
	{
		mvprintw(UP + i, LEFT, "|");
		mvprintw(UP + i, RIGHT, "|");
	}
}

void draw_columns()
{
	// LEFT COLUMNS
	for (int i = LEFT + 1; i < BAR_L; i++)
	{
		if (i % 3 != 1)
		{
			for (int j = UP + 1; j < DOWN; j++)
			{
				if (j <= UP + 5 || j >= DOWN - 5)
				{
					mvprintw(j, i, "|");
				}
			}
		}
	}
	// RIGHT COLUMNS
	for (int i = BAR_R + 1; i < RIGHT; i++)
	{
		if (i % 3 != 2)
		{
			for (int j = UP + 1; j < DOWN; j++)
			{
				if (j <= UP + 5 || j >= DOWN - 5)
				{
					mvprintw(j, i, "|");
				}
			}
		}
	}
}

void draw_spikes()
{
	// LEFT TOP V
	for (int j = LEFT + 1; j < BAR_L; j++)
	{
		if (j % 3 != 1)
		{
			mvprintw(9, j, "V");
		}
	}
	// RIGHT TOP V
	for (int j = BAR_R + 1; j < RIGHT; j++)
	{
		if (j % 3 != 2)
		{
			mvprintw(9, j, "V");
		}
	}
	// LEFT BOTTOM Ʌ
	for (int j = LEFT + 1; j < BAR_L; j++)
	{
		if (j % 3 != 1)
		{
			mvprintw(13, j, "A");
		}
	}
	// RIGHT BOTTOM Ʌ
	for (int j = BAR_R + 1; j < RIGHT; j++)
	{
		if (j % 3 != 2)
		{
			mvprintw(13, j, "A");
		}
	}
}

void draw_bar()
{
	// BAR
	for (int i = UP + 1; i < DOWN; i++)
	{
		mvprintw(i, BAR_L, "|");
		mvprintw(i, BAR_R, "|");
	}
	mvprintw((UP + DOWN) / 2, (BAR_L + BAR_R) / 2 - 1, "BAR");
}

void draw_menu()
{
	mvprintw(OPTION_Y, OPTION_X, "Roll");
	mvprintw(OPTION_Y + 1, OPTION_X, "Save");
	mvprintw(OPTION_Y + 2, OPTION_X, "Load");
	mvprintw(OPTION_Y + 3, OPTION_X, "Exit");
	mvprintw(OPTION_Y, OPTION_X - 1, ">");
}

void draw_numbers()
{
	// UPPER
	mvprintw(UP - 1, LEFT + 2, "12 11 10  9  8  7         6  5  4  3  2  1");
	//	LOWER
	mvprintw(DOWN + 1, LEFT + 2, "13 14 15 16 17 18        19 20 21 22 23 24");
}

void draw_board(backgammon_t *game)
{
	draw_borders();
	draw_columns();
	draw_spikes();
	draw_bar();
	draw_menu();
	draw_numbers();
	if(game->turn == -1){
		mvprintw(INFO_Y, INFO_X, "Roll to choose who starts!");
	}
	else if(game->turn%2 == 0){
		mvprintw(INFO_Y, INFO_X, "White turn!");
	}
	else{
		mvprintw(INFO_Y, INFO_X, "Black turn!");
	}
}

void refresh_board(backgammon_t *game)
{
	draw_board(game);
	load_board(*game);

}

void invalid_move(){
	mvprintw(WARNING_Y, WARNING_X, "Invalid move!");
}

void menu_choice(backgammon_t *game, int direction)
{
	if (direction == 1)
	{
		mvprintw(OPTION_Y + game->menu, OPTION_X - 1, " ");
		mvprintw(OPTION_Y + (game->menu + 1) % 4, OPTION_X - 1, ">");
		game->menu++;
		game->menu %= 4;
	}
	else
	{
		mvprintw(OPTION_Y + game->menu, OPTION_X - 1, " ");
		mvprintw(OPTION_Y + (game->menu - 1) % 4, OPTION_X - 1, ">");
		game->menu--;
		if (game->menu < 0)
		{
			mvprintw(OPTION_Y - 1, OPTION_X - 1, " ");
			mvprintw(OPTION_Y + 3, OPTION_X - 1, ">");
			game->menu = 3;
		}
		game->menu %= 4;
	}
}

// GAME

void win(int person, backgammon_t* game){
	clear();
	if(!person){
		mvprintw(0, 0, "White wins with oponent having %d pieces at home!", game->at_home[1]);
	}
	else{
		mvprintw(0, 0, "Black wins with oponent having %d pieces at home!", game->at_home[0]);
	}
	mvprintw(1, 0, "Press any key to exit!");
	getch();
	exit_game();
}

void eval_win(backgammon_t* game){
	if(game->at_home[0] >= 15){
		win(0, game);
	}
	else if(game->at_home[1] >= 15){
		win(1, game);
	}
}

void roll(backgammon_t* game)
{
	game->dice[0]=rand() % 6 + 1;
	game->dice[1]=rand() % 6 + 1;
}

void choose_start_roll(int *turn)
{
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	clear_player_info();
	mvprintw(PLAYER_INFO_Y, PLAYER_INFO_X, "White rolled: %d", dice1);
	mvprintw(PLAYER_INFO_Y + 1, PLAYER_INFO_X, "Black rolled: %d", dice2);
	
	if (dice1 > dice2)
	{
		*turn = 0;
		clear_info();
		mvprintw(INFO_Y, INFO_X, "White starts!");
	}
	else if (dice1 < dice2)
	{
		*turn = 1;
		clear_info();
		mvprintw(INFO_Y, INFO_X, "Black starts!");
	}
	else
	{
		mvprintw(INFO_Y, INFO_X, "Same dice, roll again!");
		choose_start_roll(turn);
	}
}

int check_double(backgammon_t *game)
{
	if (game->dice[0] == game->dice[1])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int check_and_execute_hit_white(backgammon_t* game, int dice) {
    for(int i=0; i<BOARD_SIZE; i++){
		if(game->board[i] > 0){
			if(game->board[i+dice]==-1){
				game->board[i]--;
				game->board[i+dice] = 1;
				game->bar[1]++;
				refresh_board(game);
				clear_hit();
				mvprintw(HIT_Y, HIT_X, "Hit at %d!", i+dice+1);
				mvprintw(BAR_DEBUG_Y, BAR_DEBUG_X, "Bar 1 = %d", game->bar[0]);
				mvprintw(BAR_DEBUG_Y + 1, BAR_DEBUG_X, "Bar 2 = %d", game->bar[1]);
				return 1;
			}
		}
	}
	return 0;
}

int check_and_execute_hit_black(backgammon_t* game, int dice){
	for(int i=BOARD_SIZE-1; i>=0; i--){
		if(game->board[i]<0 && i-dice>=0){
			if(game->board[i-dice]==1){
				game->board[i]++;
				game->board[i-dice] = -1;
				game->bar[0]++;
				refresh_board(game);
				clear_hit();
				mvprintw(HIT_Y, HIT_X, "Hit at %d!", i-dice+1);
				mvprintw(BAR_DEBUG_Y, BAR_DEBUG_X, "Bar 1 = %d", game->bar[0]);
				mvprintw(BAR_DEBUG_Y + 1, BAR_DEBUG_X, "Bar 2 = %d", game->bar[1]);
				return 1;
			}
		}
	}
	return 0;
}

void hit_black_to_white(backgammon_t* game, int from, int to){
	game->board[from]++;
	game->board[to] = -1;
	game->bar[0]++;
	mvprintw(HIT_Y, HIT_X, "Hit at %d!", to+1);
	mvprintw(BAR_DEBUG_Y, BAR_DEBUG_X, "Bar 1 = %d", game->bar[0]);
	mvprintw(BAR_DEBUG_Y + 1, BAR_DEBUG_X, "Bar 2 = %d", game->bar[1]);
	refresh_board(game);
}

void hit_white_to_black(backgammon_t* game, int from, int to){
	game->board[from]--;
	game->board[to] = 1;
	game->bar[1]++;
	mvprintw(HIT_Y, HIT_X, "Hit at %d!", to+1);
	mvprintw(BAR_DEBUG_Y, BAR_DEBUG_X, "Bar 1 = %d", game->bar[0]);
	mvprintw(BAR_DEBUG_Y + 1, BAR_DEBUG_X, "Bar 2 = %d", game->bar[1]);
	refresh_board(game);
}

void move_white(backgammon_t* game, int dice);
void move_black(backgammon_t* game, int dice);

void end_phase_white(backgammon_t* game, int from, int dice){
	if(game->board[from] > 0){
		if(from + dice >= BOARD_SIZE){
				game->board[from]--;
				game->at_home[0]++;
				refresh_board(game);
			}
			else{
				game->board[from]--;
				game->board[from+dice]++;
				refresh_board(game);
				mvprintw(PLAYER_INFO_Y + 1, PLAYER_INFO_X, "Moved from %d to %d", from+1, from+dice+1);
			}
		}
		else{
			invalid_move();
			move_white(game, dice);
		}
	}


void end_phase_black(backgammon_t* game, int from, int dice){
	if(game->board[from] < 0){
		if(from - dice <= -1){
			game->board[from]++;
			game->at_home[1]++;
			refresh_board(game);
		}
		else{
			game->board[from]++;
			game->board[from-dice]--;
			refresh_board(game);
			mvprintw(PLAYER_INFO_Y + 1, PLAYER_INFO_X, "Moved from %d to %d", from+1, from-dice+1);
		}
	}
	else{
		invalid_move();
		move_black(game, dice);
	}
}


void move_white(backgammon_t* game, int dice){
	eval_win(game);
	clear_player_info();
	mvprintw(PLAYER_INFO_Y, PLAYER_INFO_X, "Choose your move by index (moving by %d): ", dice);
	int from = get_number();
	if(game->home[0] >= 15){
		end_phase_white(game, from, dice);
	}
	else{
		if(game->board[from] > 0 && game->board[from+dice] >= 0 && from+dice < BOARD_SIZE && from >= 0){
		game->board[from]--;
		game->board[from+dice]++;
		refresh_board(game);
		mvprintw(PLAYER_INFO_Y + 1, PLAYER_INFO_X, "Moved from %d to %d", from+1, from+dice+1);
		clear_warning();
		}

	//NIE WYMUSZONE BICIE
	/*
	else if(game->board[from] > 0 && game->board[from+dice] == -1 && from+dice < BOARD_SIZE && from >= 0){
		hit_white_to_black(game, from, from+dice);
	}
	*/


		else{
			invalid_move();
			move_white(game, dice);
		}
	}
	refresh_board(game);
	//debug_board(*game);
	print_home(game);

}

void move_black(backgammon_t* game, int dice){
	eval_win(game);
	clear_player_info();
	mvprintw(PLAYER_INFO_Y, PLAYER_INFO_X, "Choose your move by index (moving by %d): ", dice);
	int from = get_number();
	if(game->home[1] >= 15){
		end_phase_black(game, from, dice);
	}
	else{
		if(game->board[from] < 0 && game->board[from-dice] <= 0 && from-dice >= 0 && from < BOARD_SIZE){
		game->board[from]++;
		game->board[from-dice]--;
		refresh_board(game);
		mvprintw(PLAYER_INFO_Y + 1, PLAYER_INFO_X, "Moved from %d to %d", from+1, from-dice+1);
		clear_warning();
		}
	//NIE WYMUSZONE BICIE
	/*
	else if(game->board[from] < 0 && game->board[from-dice] == 1 && from-dice >= 0 && from < BOARD_SIZE){
		hit_black_to_white(game, from, from-dice);
	}
	*/
		else{
			invalid_move();
			move_black(game, dice);
		}
	}
	refresh_board(game);
	//debug_board(*game);
	print_home(game);
}

void comeback_white_dice1(backgammon_t* game){
	clear_info();
	mvprintw(COMEBACK_Y, COMEBACK_X, "White came back at %d!", game->dice[0]+1);
	if(game->board[game->dice[0]-1] == -1){
		game->bar[1]++;
	}
	game->board[game->dice[0]-1] = 1;
	game->bar[0]--;
	refresh_board(game);
}

void comeback_white_dice2(backgammon_t* game){
	clear_info();
	mvprintw(COMEBACK_Y, COMEBACK_X, "White came back at %d!", game->dice[1]+1);
	if(game->board[game->dice[1]-1] == -1){
		game->bar[1]++;
	}
	game->board[game->dice[1]-1] = 1;
	game->bar[0]--;
	refresh_board(game);
}

void check_comeback_white(backgammon_t* game){
	if(game->board[game->dice[0]-1] == 0 || game->board[game->dice[1]-1] == -1){
		comeback_white_dice1(game);
	}
	else if(game->board[game->dice[1]-1] == 0 || game->board[game->dice[1]-1] == -1){
		comeback_white_dice1(game);
	}
	mvprintw(BAR_DEBUG_Y, BAR_DEBUG_X, "Bar 1 = %d", game->bar[0]);
	mvprintw(BAR_DEBUG_Y + 1, BAR_DEBUG_X, "Bar 2 = %d", game->bar[1]);
	
}

void comeback_black_dice1(backgammon_t* game){
	clear_info();
	mvprintw(COMEBACK_Y, COMEBACK_X, "Black came back at %d!", BOARD_SIZE-game->dice[0]+1);
	if(game->board[BOARD_SIZE-game->dice[0]] == 1){
		game->bar[0]++;
	}
	game->board[BOARD_SIZE-game->dice[0]] = -1;
	game->bar[1]--;
	refresh_board(game);
}

void comeback_black_dice2(backgammon_t* game){
	clear_info();
	mvprintw(COMEBACK_Y, COMEBACK_X, "Black came back at %d!", BOARD_SIZE-game->dice[1]+1);
	if(game->board[BOARD_SIZE-game->dice[1]] == 1){
		game->bar[0]++;
	}
	game->board[BOARD_SIZE-game->dice[1]] = -1;
	game->bar[1]--;
	refresh_board(game);
}

void check_comeback_black(backgammon_t* game){
	if(game->board[BOARD_SIZE-game->dice[0]] == 0 || game->board[BOARD_SIZE-game->dice[1]] == 1){
		comeback_black_dice1(game);
	}
	else if(game->board[BOARD_SIZE-game->dice[1]] == 0 || game->board[BOARD_SIZE-game->dice[1]] == 1){
		comeback_black_dice2(game);
	}
		mvprintw(BAR_DEBUG_Y, BAR_DEBUG_X, "Bar 1 = %d", game->bar[0]);
		mvprintw(BAR_DEBUG_Y + 1, BAR_DEBUG_X, "Bar 2 = %d", game->bar[1]);
}

//FIX >555b

void white_bar(backgammon_t* game){
	mvprintw(WARNING_Y, WARNING_X, "White has pieces in bar!");
	check_comeback_white(game);
}

void black_bar(backgammon_t* game){
	mvprintw(WARNING_Y, WARNING_X, "Black has pieces in bar!");
	check_comeback_black(game);
}

void move_double(backgammon_t* game){
	clear_warning();
		clear_double();
		mvprintw(INFO_Y+1, INFO_X, "Double!");
		for (int i = 0; i < 4; i++)
		{
			if(game->turn%2==0){
				if(game->bar[0] < 1){
					//WYMUSZENIE BICIA
					
					if(check_and_execute_hit_white(game, game->dice[0])){
						continue;
					}
					else{
						move_white(game, game->dice[0]);
						print_dice(game);
					}	
				//NIE WYMUSZENIE BICIA
				//move_white(game, game->dice[0]);
				//print_dice(game);
				}
				else{
					white_bar(game);
					break;
				}
			}
			else{
				if(game->bar[1]>0){
					black_bar(game);
				}
				//WYMUSZENIE BICIA
				
				if(check_and_execute_hit_black(game, game->dice[0])){
					continue;
				}
				else{
					move_black(game, game->dice[0]);
					print_dice(game);
				}
				//NIE WYMUSZENIE BICIA
				//move_black(game, game->dice[0]);
				
			}
			eval_win(game);
		}
}

void white_turn(backgammon_t* game){
	if(game->bar[0] < 1){
		mvprintw(INFO_Y, INFO_X, "White turn!");
		//WYMUSZENIE BICIA
		if(!check_and_execute_hit_white(game, game->dice[0])){
			move_white(game, game->dice[0]);
			print_dice(game);
		}
		if(!check_and_execute_hit_white(game, game->dice[1])){
			move_white(game, game->dice[1]);
		}
		//NIE WYMUSZENIE BICIA
		//move_white(game, game->dice[0]);
		//move_white(game, game->dice[1]);
	clear_info();
	}
	else{
		mvprintw(INFO_Y, INFO_X, "White has pieces in bar!");
		check_comeback_white(game);
	}
}

void black_turn(backgammon_t* game){
	if(game->bar[1] < 1){
		mvprintw(INFO_Y, INFO_X, "Black turn!");
			//WYMUSZENIE BICIA
			if(!check_and_execute_hit_black(game, game->dice[0])){
				move_black(game, game->dice[0]);
			}
			if(!check_and_execute_hit_black(game, game->dice[1])){
				move_black(game, game->dice[1]);
			}
		//NIE WYMUSZENIE BICIA
		//move_black(game, game->dice[0]);
		//move_black(game, game->dice[1]);
		clear_info();
	}
	else{
		mvprintw(INFO_Y, INFO_X, "Black has pieces in bar!");
		check_comeback_black(game);
	}
}

void roll_dice(backgammon_t* game){
	eval_win(game);
	clear_bar_info();
	clear_warning();
	clear_comeback();
	clear_double();
	if (game->turn == -1)
	{
		clear_info();
		mvprintw(INFO_Y, INFO_X, "Roll to choose who starts!");
		choose_start_roll(&game->turn);
	}
	else
	{
		clear_player_info();
		roll(game);
		print_dice(game);
		//DOUBLE
		if (check_double(game))
		{
			move_double(game);
		}
		//NO DOUBLE
		else
		{
			clear_info();
			mvprintw(INFO_Y, INFO_X, "Not double!");
			// choose 2 moves with different values
			if(game->turn%2 == 0){
				white_turn(game);
			}
				
			else{
				black_turn(game);
			}
		}
		game->turn++;
		refresh_board(game);
		clear_hit();
	}
	count_home(game);
	eval_win(game);
}

// MAIN



int start_game(backgammon_t *game)
{

	while (1)
	{
		int ch = getch();
		switch (ch)
		{
		case KEY_UP:
			menu_choice(game, -1);
			break;
		case KEY_DOWN:
			menu_choice(game, 1);
			break;
		case KEY_RIGHT:
			switch (game->menu)
			{
			case 0:

				// roll
				if(game->turn%2 == 0){
					mvprintw(INFO_Y, INFO_X, "White turn!");
				}
				else{
					mvprintw(INFO_Y, INFO_X, "Black turn!");
				}
				roll_dice(game);

				break;
			case 1:
				// save game
				save_to_file(game);
				clear_info();
				mvprintw(INFO_Y, INFO_X, "Game saved!");

				break;
			case 2:
				// load game
				load_from_file(game);
				refresh_board(game);

				mvprintw(INFO_Y+1, INFO_X, "Game loaded!");
				break;
			case 3:
				exit_game();
			}
			break;
		}
	}
}

// INIT

void init_player1(backgammon_t *game)
{
	game->board[0] = 2;
	game->board[11] = 5;
	game->board[16] = 3;
	game->board[18] = 5;
}

void init_player2(backgammon_t *game)
{
	game->board[23] = -2;
	game->board[12] = -5;
	game->board[7] = -3;
	game->board[5] = -5;
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
	game->at_home[0] = 0;
	game->at_home[1] = 0;
	game->menu = 0;
	game->bar[0] = 0;
	game->bar[1] = 0;
	game->turn = -1;
	return 0;
}



void init(backgammon_t *game)
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	raw();
	init_game_var(game);
	init_player1(game);
	init_player2(game);
	draw_board(game);
	load_board(*game);
}

int main()
{
	srand(time(NULL));
	backgammon_t game;
	init(&game);
	start_game(&game);
	clear();
}