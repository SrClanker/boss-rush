#include <stdio.h>
#include <ncurses.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 4096
#define NUM_BOSSES 3

typedef struct {
    char name[MAX_NAME];
    int damage;
    int health;
} Entity;

void getName(Entity *player);
bool anyErrors(Entity *player);

int main(void) {
    Entity player = { 
        .damage = 15, 
        .health = 100 
    };
    getName(&player);

    const char *bossNames[NUM_BOSSES] = { "Spitter", "Crane", "Muscular" };
    size_t bossNamesLength = sizeof(bossNames) / sizeof(bossNames[0]);

    Entity spitter = { 
        "Spitter", 
        .damage = 15, 
        .health = 100 
    };
    Entity crane = { 
        "Crane", 
        .damage = 15, 
        .health = 100 
    };
    Entity muscular = { 
        "Muscular", 
        .damage = 15, 
        .health = 100 
    };

    for (int i = 0; i < bossNamesLength; i++) {
        printf("%d. %s\n", i+1, bossNames[i]);
    }

    return 0;
}

void getName(Entity *player) {
    while (fgets(player->name, sizeof(player->name), stdin) != NULL) {
        if (anyErrors(player)) {
            printf("Invalid input...\n");
        } else { break; }
    }

    player->name[strcspn(player->name, "\n")] = '\0';
}

bool anyErrors(Entity *player) {
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
