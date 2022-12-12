#include <curses.h>

#define LMAX 8
#define CENTER 1

int main(void) {
    char label_text[LMAX][8] = {"S", "O", "F", "T", 
                                "K", "E", "Y", "S"};

    slk_init(1);
    initscr();
    
    for (int label = 0; label < LMAX; label++)
        slk_set(label+1, label_text[label], CENTER);
    slk_refresh();
    
    getch();

    slk_clear();
    getch();

    slk_restore();
    getch();

    endwin();
    return 0;
}