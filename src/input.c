#include <ncurses.h>
#include <string.h>

void input(char* prompt, char* value, attr_t attrs, void(*hintproc)(char*, char**)) {
    noecho();
    curs_set(2);

    int y, x, i = 0, p = strlen(prompt);
    getmaxyx(stdscr, y, x);
    WINDOW* win = newwin(1, x, y-1, 0);

    wattron(win, attrs);
    mvwaddstr(win, 0, 0, prompt);
    wattroff(win, attrs);

    while (1) {
        char ch = wgetch(win);
        if (ch == '\n') {
            value[i] = '\0';
            break;
        } else if (ch == 127) {
            if (i > 0) {
                value[i--] = '\0';
                mvwaddch(win, 0, p+i, ' ');
                wmove(win, 0, p+i);
            }
        } else {
            value[i++] = ch;
            mvwaddch(win, 0, p+i-1, ch);
        }
    }

    delwin(win);
    curs_set(0);
}
