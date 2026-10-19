#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>

typedef struct {
    char name[4096];
    int damage;
    int health;
} Player;

bool getName(Player *player);

int main(void) {
    Player player;
    bool didGetName = getName(&player);

    initscr();

    if (didGetName) {
        printw("Name: %s", player.name);
    } else {
        printw("Invalid input...");
    }

    refresh();
    getch();
    endwin();

    return 0;
}

bool getName(Player *player) {
    while (fgets(player->name, sizeof(player->name), stdin) == NULL) {
        return false;
    }

    if (player->name[0] == '\n') {
        return false;
    }

    for (int i = 0; player->name[i] != '\0'; i++) {
        if (isdigit(player->name[i])) {
            return false;
        }
    }
   
    player->name[strcspn(player->name, "\n")] = '\0';
    return true;
}
