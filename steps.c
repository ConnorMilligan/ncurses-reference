#include <curses.h>

int main(void) {
    int y, x, maxy, maxx;

    initscr();

    getmaxyx(stdscr, maxy, maxx);

    for (y = x = 0; y < maxy; y++, x+=2) {
        move(x, y);
        hline(0, maxx-x);
        vline(0, maxy-y);
    }
    refresh();
    getch();

    endwin();
    return 0;
}