#include <ncurses.h>

int main(void) {
    initscr();
    attron(A_BOLD);
    addstr("Little star\n");
    attron(A_BLINK);
    addstr("pekora usada\n");
    attroff(A_BOLD);
    addstr("whos the cutest vtuber in the world?\n");
    addstr("Peko chan!\n");
    attron(A_NORMAL);
    addstr("Yes\n");
    refresh();
    getch();
    endwin();
    return 0;
}