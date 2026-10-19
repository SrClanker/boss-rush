#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[4096];
    int damage;
    int health;
} Player;

void getName(Player *player);
bool anyErrors(Player *player);

int main(void) {
    Player player;
    getName(&player);

    return 0;
}

void getName(Player *player) {
    while (fgets(player->name, sizeof(player->name), stdin) != NULL) {
        if (anyErrors(player)) {
            printf("Invalid input...\n");
        } else { break; }
    }

    player->name[strcspn(player->name, "\n")] = '\0';
}

bool anyErrors(Player *player) {
    if (player->name[0] == '\n') {
        return true;
    }

    for (int i = 0; player->name[i] != '\0'; i++) {
        if (isdigit(player->name[i])) {
            return true;
        }
    }

    return false;
}
