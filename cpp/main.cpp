#include <ncurses.h>
#include <iostream>

using namespace std;

int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int ch = getch();
    while (ch != 'q')
    {
        switch (ch)
        {
            case KEY_UP:
                cout << "UP" << endl;
                break;
            case KEY_DOWN:
                cout << "DOWN" << endl;
                break;
            case KEY_LEFT:
                cout << "LEFT" << endl;
                break;
            case KEY_RIGHT:
                cout << "RIGHT" << endl;
                break;
        }
        ch = getch();
    }

    endwin();
    return 0;
}