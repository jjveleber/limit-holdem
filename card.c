
#include "card.h"
#include <time.h>

#define CARD_DECK_SIZE CARD_DECK_COUNT * sizeof(uint8_t)
#define CARD_VALUE_MASK 0x0F
#define CARD_SUIT_MASK 0x03
#define CARD_SPADE 'S'
#define CARD_DIAMOND 'D'
#define CARD_CLUB 'C'
#define CARD_HEART 'H'
#define CARD_ERROR '!'

uint8_t* deck = 0;
static uint8_t deck_top_index = 0;

void card_init_deck(void) {
    // Setup random number generator for shuffling the deck
    srand(time(NULL));

    deck = malloc(sizeof(uint8_t) * CARD_DECK_SIZE);
    uint8_t i;

    for(i = 0; i < CARD_DECK_COUNT; ++i) {
        // Clubs =      b00     i = 0
        // Diamonds =   b01     i = 1
        // Hearts =     b10     i = 2
        // Spades =     b11     i = 3
        deck[i] =  ((i / 13) << 4) + ((i % 13)); // bits 0-3 = card index in suit | bits 4 & 5 = suit
    }
}

void card_close_deck(void) {
    free(deck);
}

bool card_same_suit(const uint8_t card_1_index, const uint8_t card_2_index)
{
    if(card_1_index > CARD_DECK_COUNT - 1 || card_2_index > CARD_DECK_COUNT - 1 ) {
        // TODO: throw an exception
        return false;
    }
    return !((deck[card_1_index] >> 4) - (deck[card_2_index] >> 4));
}


char* const card_get_name(const uint8_t card_index) {

    uint8_t card = deck[card_index];

    char card_suit_name = card_get_suit_name(card);
    char card_value_name = card_get_value_name(card);

    char* name = malloc(sizeof(char) * 3); // suit + value + null
    name[0] = card_suit_name;
    name[1] = card_value_name;
    name[2] = '\0';
    return name;
}


char const card_get_value_name(const uint8_t card) {
    uint8_t card_value = (card & CARD_VALUE_MASK);
    switch(card_value) {
        case 0:
            return 'A';
        case 9:
            return 'T';
        case 10:
            return 'J';
        case 11:
            return'Q';
        case 12:
            return 'K';
        default:
            return card_value + 1 + '0';
    }

}

char const card_get_suit_name(const uint8_t card) {
    uint8_t card_suit = (card >> 4) & CARD_SUIT_MASK;
    switch(card_suit) {
        case 0:
            return CARD_CLUB;
        case 1:
            return CARD_HEART;
        case 2:
            return CARD_SPADE;
        case 3:
            return CARD_DIAMOND;
        default:
            return CARD_ERROR;

    }
}

void card_shuffle_deck(void) {
    deck_top_index = 0;
    uint16_t i;
    uint8_t index1;
    uint8_t index2;
    uint8_t card1;
    uint8_t card2;
    for(i=0; i < UINT16_MAX; ++i) {
        index1 = (uint8_t) (rand() % 53);
        index2 = (uint8_t) (rand() % 53);
        card1 = deck[index1];
        card2 = deck[index2];
        deck[index1] = card2;
        deck[index2] = card1;
    }
}

const uint8_t card_deal_from_top(void) {
    return deck_top_index++;
}
