#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define CARD_DECK_COUNT 53

void card_init_deck(void);
void card_close_deck(void);
bool card_same_suit(const uint8_t card_1_index, const uint8_t card_2_index);
char* const card_get_name(const uint8_t card_index);
char const card_get_suit_name(const uint8_t card);
char const card_get_value_name(const uint8_t card);
void card_shuffle_deck(void);
const uint8_t card_deal_from_top(void);

#endif // CARD_H_INCLUDED
