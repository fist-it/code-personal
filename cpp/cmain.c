#include <ncurses.h>
#include <time.h>

// BOARD
const int BOARD_SIZE = 24;
const int END = BOARD_SIZE - 1;
const int LEFT = 3;
const int RIGHT = 48;
const int DOWN = 19;
const int UP = 3;
const int BOARD_WIDTH = 45;
const int BOARD_HEIGHT = 16;
const int BAR_L = 23;
const int BAR_R = 28;

// MENU
const int OPTION_X = 52;
const int OPTION_Y = 4;
const int INFO_X = 2;
const int INFO_Y = 22;

const int DEBUG_X = 3;
const int DEBUG_Y = 23;

const int MENU_DEBUG_X = 3;
const int MENU_DEBUG_Y = 24;

// struct
typedef struct
{
	int board[BOARD_SIZE];
	int dice[2];
	int turn;
	int home[2];
	int menu;
	int dead[2];
} backgammon_t;

// GUI

void clear_info()
{
	move(INFO_Y, INFO_X);
	clrtoeol();
}

void clear_debug()
{
	move(DEBUG_Y, DEBUG_X);
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
	clear();
	draw_borders();
	draw_columns();
	draw_spikes();
	draw_bar();
	draw_menu();
	draw_numbers();
}

void menu_choice(backgammon_t *game, int direction)
{
	if (direction == 1)
	{
		mvprintw(OPTION_Y + game->menu, OPTION_X - 1, " ");
		mvprintw(OPTION_Y + (game->menu + 1) % 4, OPTION_X - 1, ">");
		game->menu++;
		game->menu %= 4;
		mvprintw(MENU_DEBUG_Y, MENU_DEBUG_X, "menu = %d", game->menu);
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
		mvprintw(MENU_DEBUG_Y, MENU_DEBUG_X, "menu = %d", game->menu);
	}
}

void exit_game()
{
	clear();
	echo();
	endwin();
	exit(0);
}

// GAME

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
	else if (*turn != -1)
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
				// DEBUG
				mvprintw(DEBUG_Y, DEBUG_X, "ROLLED");
				// roll
				if (game->turn == -1)
				{
					clear_info();
					mvprintw(INFO_Y, INFO_X, "Roll to choose who starts!");
					choose_start_roll(&game->turn);
					break;
				}
				else
				{
					game->dice[0] = roll();
					game->dice[1] = roll();
					if (check_double(game))
					{
						clear_info();
						mvprintw(INFO_Y, INFO_X, "Double!");
						for (int i = 0; i < 4; i++)
						{
							// choose 4 moves with same value
						}
					}
					else
					{
						clear_info();
						mvprintw(INFO_Y, INFO_X, "Not double!");
						// choose 2 moves with different values
					}
					break;
				}
			case 1:
				// save game
				// DEBUG
				clear_debug();
				mvprintw(DEBUG_Y, DEBUG_X, "SAVED");
				break;
			case 2:
				// load game
				// DEBUG
				clear_debug();
				mvprintw(DEBUG_Y, DEBUG_X, "LOADED");
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
	game->menu = 0;
	game->dead[0] = 0;
	game->dead[1] = 0;
	game->turn = -1;
	return 0;
}

void load_upper_right_white(backgammon_t *game)
{
	int j = 0;
	for (int i = 0; i < 7; i++)
	{
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
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
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
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
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
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
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
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
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
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
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
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
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
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
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
	choose_start_roll(&game->turn);
}

int main()
{
	backgammon_t game;
	init(&game);
	start_game(&game);
	getch();
	clear();
	exit_game();
}
