#include <ncurses.h>

#define MENU_MAX 6

void drawMenu(int item) {
    char *mainMenu = "Main Menu";
    char menu[MENU_MAX][21] = {
        "Answer E-mail",
        "Off to the web",
        "Word processing",
        "Financial management",
        "Maintenance",
        "Shutdown"
    };

    clear();
    addstr(mainMenu);
    for (int i = 0; i < MENU_MAX; i++) {
        if (i == item)
            attron(A_REVERSE);
        mvaddstr(3+(i*2), 20, menu[i]);
        attroff(A_REVERSE);
    }
    
    mvaddstr(17, 25, "Use arrow keys to move");
    refresh();
}

int main(void) {
    int key, menuitem = 0;

    initscr();

    drawMenu(menuitem);
    keypad(stdscr, TRUE);
    noecho();

    do {
        key = getch();

        switch (key) {
            case KEY_DOWN:
                menuitem++;
                if (menuitem > MENU_MAX-1) 
                    menuitem = 0;                
                break;
            case KEY_UP:
                menuitem--;
                if (menuitem < 0) 
                    menuitem = MENU_MAX-1;                
                break;
            default:
                break;
        }
        drawMenu(menuitem);
    } while (key != '\n');
    
    echo();

    endwin();
    return 0;
}