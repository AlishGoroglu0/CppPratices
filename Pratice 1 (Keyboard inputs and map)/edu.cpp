#include <ncurses.h>
#include <iostream>
#include <algorithm>

void drawMap(int pos) {
    
    clear();
    for (int i = 0; i < 10; ++i) {
        if (i == pos) mvprintw(0, i * 4, "[A]");
        else mvprintw(0, i * 4, "[ ]");
    }
    refresh();
}

int main() {
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int pos = 2; 
    int ch;

    while ((ch = getch()) != 'q') { 
        if (ch == 'a' && pos > 0) pos--;
        else if (ch == 'd' && pos < 9) pos++;
        
        drawMap(pos);
    }

    endwin();
    return 0;
}