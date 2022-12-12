#include <ncurses.h>

int main(void){ 
    MEVENT mort;
    int ch;

    initscr();
    noecho();
    keypad(stdscr, TRUE);

    mousemask(ALL_MOUSE_EVENTS, NULL);

    for (;;) {
        ch = getch();

        if (ch == KEY_MOUSE) {
            getmouse(&mort);
            move(mort.y, mort.x);
            addch('*');
            refresh();
            continue;
        }
        if (ch == '\n')
            break;
    }
    
    endwin();
    return 0;
}