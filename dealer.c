
#include "dealer.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

static uint8_t* board_cards[5]; // pointer to index in deck

void dealer_init(void) {
    uint8_t i;
    for(i=0; i < 5; ++i) {
        board_cards[i] = NULL;
    }
}

void dealer_destroy(void) {
    dealer_muck_board();
}

void dealer_muck_board(void) {
    uint8_t i;
    for(i=0; i < 5; ++i) {
        if(board_cards[i]) {
            free(board_cards[i]);
        }
        board_cards[i] = NULL;
    }
}

void dealer_deal_card(struct Player* player) {
    uint8_t* topCard = malloc(sizeof(uint8_t*));
    *topCard = card_deal_from_top();
    if(player->cards[0] == NULL) {
        player->cards[0] = topCard;
    } else if(player->cards[1] == NULL) {
        player->cards[1] = topCard;
        player->live_hand = true;
    }
/* TODO (auser#1#): throw exception if dealing too many cards */
}

void dealer_deal_flop(void) {
    // burn
    card_deal_from_top();
    dealer_deal_to_board(0);
    dealer_deal_to_board(1);
    dealer_deal_to_board(2);
}

void dealer_deal_turn(void) {
    // burn
    card_deal_from_top();
    dealer_deal_to_board(3);

}

void dealer_deal_river(void) {
    // burn
    card_deal_from_top();
    dealer_deal_to_board(4);
}

void dealer_deal_to_board(uint8_t index) {
    board_cards[index] = malloc(sizeof(uint8_t*));
    *(board_cards[index]) = card_deal_from_top();
}

void dealer_print_board(void) {
    uint8_t i;
    for(i=0; i < 5; ++i) {
        if(!board_cards[i]) {
            break;
        }

        if(i==0) {
            printf("{");
        } else {
            printf(" ");
        }

        char* card_name = card_get_name(*(board_cards[i]));
        printf("[%s]", card_name);
        free(card_name);
    }
    printf("}\n");
}

struct Player *dealer_find_winner(struct Player *players) {
    /*
        Hand Ranks

        Royal Flush


        Straight Flush
        Quads
        Boat
        Flush
        Straight
        3 of a kind
        2 pair
        pair
        high card

    */
    return 0;
}

bool dealer_has_flush(struct Player* player) {
    uint8_t clubs = + !((*(board_cards[0])) >> 4)
                    + !((*(board_cards[0])) >> 4)
}

uint8_t dealer_get_suit_count(struct Player* player, uint8_t suit) { // suit is 4 bits wide
    uint8_t suit_count = 0;
    uint8_t i;
    for(i=0; i<5; ++i) {
        suit_count += !((board_cards[card_1_index] >> 4) - suit);
    }

    suit_count += !((player->cards[0] >> 4) - (deck[card_2_index] >> 4)) + !((deck[card_1_index] >> 4) - (deck[card_2_index] >> 4)); // TODO check players cards
}
