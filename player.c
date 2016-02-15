
#include "player.h"
#include <stdio.h>

#define NO_CARD "NC"


static char* const PLAYER_NAMES[] = {
    "Fred\0",
    "Barney\0",
    "Wanda\0"
};
static uint8_t player_names_counter = 0;

struct Player* player_new(char* name) {
    struct Player* player = malloc(sizeof(struct Player));
    player->name = name;
    player->cards[0] = NULL;
    player->cards[1] = NULL;
    return player;
}

void player_destroy(struct Player* player) {
    //free(player->name);
    // Cards belong to the deck. They will be freed there.
    player_muck_hand(player);
    free(player);
}

char* player_new_name(void) {
//    char* name = malloc(sizeof(char))
    return PLAYER_NAMES[player_names_counter++];
}

void player_muck_hand(struct Player* player) {
    player->live_hand = false;
    if(player->cards[0] != NULL) {
        free(player->cards[0]);
        player->cards[0] = NULL;
    }

    if(player->cards[1] != NULL) {
        free(player->cards[1]);
        player->cards[1] = NULL;
    }
}

void player_print(struct Player* player) {
    char* card1_name = card_get_name(*(player->cards[0]));
    char* card2_name = card_get_name(*(player->cards[1]));
    printf("Name: %s\tCards: [%s,%s] Live Cards: %s\n",
            player->name,
            card1_name,
            card2_name,
            player->live_hand ? "Yes" : "No"
          );
    free(card1_name);
    free(card2_name);
}
