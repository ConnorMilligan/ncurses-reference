#include <ncurses.h>

int main(void) {
    initscr();

    addstr("Goodbye world!");
    refresh();
    getch();

    endwin();
    return 0;
}