#include <ncurses.h>
#include <string.h>

void fill(void);

int main(void) {
    char *text = "Stock market is a big old peko on top.";
    char *t;
    int len;

    initscr();
    fill();
    refresh();

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

void fill(void) {
    int x, y;

    getmaxyx(stdscr, y, x);
    for(int i = 0; i < y; i++)
        addstr("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
}