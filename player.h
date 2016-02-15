#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "card.h"



struct Player {
    char* name;
    uint8_t* cards[2]; // pointer to index in deck
    bool live_hand;
};

struct Player* player_new(char* name);
void player_destroy(struct Player* player);
char* player_new_name(void);

void player_muck_hand(struct Player* player);
void player_print(struct Player* player);

#endif // PLAYER_H_INCLUDED
