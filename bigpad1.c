#include <curses.h>

int main(void) {
    WINDOW *p;
    int x, c;

    initscr();

    p = newpad(50, 100);

    if (p == NULL) {
        addstr("Unable to make new pad.\n");
        refresh();
        endwin();
        return 1;
    }

    addstr("New pad created");
    //refresh();
    prefresh(p, 0, 0, 0, 0, 1, 15);
    getch();

    endwin();
    return 0;
}