#include <ncurses.h>
#include <string.h>

int main(void) {
    char *text = "Stock market is a big old peko on top.";
    char *t;
    int len;

    initscr();

    len = strlen(text);
    t = text;
    while (len) {
        move(5,5);
        insch(*(t+len-1));
        refresh();
        napms(100);
        len--;
    }
    getch();

    endwin();
    return 0;
}