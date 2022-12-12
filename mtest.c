#include <ncurses.h>

int main(void) {
    mmask_t mmask;

    initscr();
    if (NCURSES_MOUSE_VERSION > 0)
        addstr("This verson of NCurses supports the mouse.\n");
    else 
        addstr("This verson of NCurses does not support the mouse.\n");

    mmask = mousemask(ALL_MOUSE_EVENTS, NULL);
    if (!mmask)
        addstr("Unable to access the mouse of this terminal.\n");
    else 
        addstr("Mouse events can be captured.\n");

    refresh();
    getch();
    endwin();

    
    return 0;
}