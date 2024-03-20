#include <ncurses.h>
#include "input.c"
#include "plugins.c"

int main(int argc, char** argv) {
    // initscr();
    // curs_set(0);
    // noecho();
    // start_color();

    // char* value;
    // init_pair(1, COLOR_RED, COLOR_BLACK);
    // input("goto ", value, A_BOLD | COLOR_PAIR(1), NULL);
    // addstr(value);
    // getch();

    // endwin();

    load_plugins("./");

    return 0;
}
