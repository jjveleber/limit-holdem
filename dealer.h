#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED

#include "player.h"
#include "card.h"

void dealer_init(void);
void dealer_destroy(void);
void dealer_deal_to_board(uint8_t index);
void dealer_deal_flop(void);
void dealer_deal_turn(void);
void dealer_deal_river(void);
void dealer_muck_board(void);
void dealer_print_board(void);
void dealer_deal_card(struct Player* player);
struct Player* dealer_find_winner(struct Player* players);
bool dealer_has_flush(struct Player* player);
bool dealer_has_straight(struct Player* player);
uint8_t dealer_get_suit_count(uint8_t suit);
//uint16_t dealer_straight_flush(struct Player* player);
//uint16_t dealer_quads(struct Player* player);
//uint16_t dealer_boat(struct Player* player);
//uint16_t dealer_flush(struct Player* player);
//uint16_t dealer_straight(struct Player* player);
//uint16_t dealer_trips(struct Player* player);
//uint16_t dealer_two_of_a_kind(struct Player* player);
//uint16_t dealer_pair(struct Player* player);
//uint16_t dealer_high_card(struct Player* player);

#endif // DEALER_H_INCLUDED

