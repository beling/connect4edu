#ifndef CONNECT4_PLAYERS_H
#define CONNECT4_PLAYERS_H

#include "board.h"

typedef int player_f(const Board& board);

int human_player(const Board& board);
int minmax_player(const Board& board);
int alphabeta_player(const Board& board);
int mcts_player(const Board& board);


#endif // CONNECT4_PLAYERS_H
