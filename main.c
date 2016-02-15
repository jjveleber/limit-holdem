#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#include "player.h"
#include "dealer.h"

#define PLAYERS_IN_GAME 3
extern uint8_t* deck;

void print_deck(void);

int main()
{
    card_init_deck();
    dealer_init();

    print_deck();
    //card_shuffle_deck();
    printf("\n\n%d", card_same_suit(deck[0], deck[1]));
    printf("\n\n%d", card_same_suit(deck[13], deck[14]));
    printf("\n\n%d", card_same_suit(deck[0], deck[14]));
    printf("\n\n");
    print_deck();
    struct Player* players[PLAYERS_IN_GAME];
    uint8_t i;
    for(i = 0; i < PLAYERS_IN_GAME; ++i) {
        players[i] = player_new(player_new_name());
    }

    uint8_t j;
    for(j = 1; j <= 2; ++j) {
        for(i = 0; i < PLAYERS_IN_GAME; ++i) {
            dealer_deal_card(players[i]);
        }
    }

    for(i = 0; i < PLAYERS_IN_GAME; ++i) {
        player_print(players[i]);
    }

    dealer_deal_flop();
    dealer_print_board();
    dealer_deal_turn();
    dealer_print_board();
    dealer_deal_river();
    dealer_print_board();
    dealer_muck_board();

//    uint8_t j;
//    for(j=0; j < 3; ++j) {
//        printf("\n\t\t%c\n", card_get_suit_name((j << 4)));
//        for(i=0; i < 12; ++i) {
//            uint8_t index1 = i + (j*13);
//            uint8_t index2 = i + ((j+1)*13);
//            name1 = card_get_name(index1);
//            name2 = card_get_name(index2);
//            printf("Cards are the same suit[%d, %d] [%s,%s]: %s\n", index1, index2, name1, name2, card_same_suit(index1,index2) ? "true" : "false");
//            free(name1);
//            free(name2);
//        }
//    }
    for(i = 0; i < PLAYERS_IN_GAME; ++i) {
        player_destroy(players[i]);
    }

    dealer_destroy();
    card_close_deck();
    return 0;
}

void print_deck(void) {
    uint8_t i;
    char* name;
    for(i=0; i < CARD_DECK_COUNT-1; ++i) {
        name = card_get_name(i);
        printf("[%d]\t[%s]\n", i, name);
        free(name);
    }
}
