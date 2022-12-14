#include <ncurses.h>

void showHelp(void);
WINDOW *help;

int main(void) {
    int ch;

    initscr();
    help = newwin(10,30,4,26);

    if (help == NULL) {
        addstr("Unable to allocate window memory\n");
        endwin();
        return(1);
    }
    mvwaddstr(help,1,7,"Help menu Screen\n");
    mvwaddstr(help,5,3,"Press the ~ key to quit\n");
    mvwaddstr(help,8,4,"Help menu Screen\n");
    box(help, 0, 0);

    addstr("Typer program\n");
    addstr("Press + for help\n\n");
    refresh();
    noecho();
    do {
        ch = getch();
        refresh();

        if (ch == '+') {
            showHelp();
        } else {
            addch(ch);
        }
    } while (ch != '~');

    endwin();    
    return 0;
}

void showHelp(void) {
    touchwin(help);
    wrefresh(help);
    getch();

    touchwin(stdscr);
    refresh();
}