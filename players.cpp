#include "players.h"

#include <string>   //used by human_player
#include "utils.h"

int human_player(const Board& board) {
    std::string possible_moves;
    for (int i = 1; i <= COLS_NUM; ++i)
        if (board.can_move(i))
            possible_moves += ('0' + char(i));
    std::cout << "type one of: " << possible_moves << std::endl;
    return ask(possible_moves.c_str()) - '0';
}


int approx_minmax(const Board& board) {
    return 0;           //TODO project 1
}

int minmax(Board& board, int depth) {
    if (board.is_win())
       return board.max_play_recent() ? MAX_PAYOFF : -MAX_PAYOFF;
    if (board.is_full())
       return 0;
    if (depth == 0)
       return approx_minmax(board);
    depth--;
    int best_value;
    if (board.max_play()) {
       best_value = -MAX_PAYOFF;
       for (int i = 1; i <= COLS_NUM; ++i)
           if (board.can_move(i)) {
              board.do_move(i);
              int v = minmax(board, depth);
              board.undo_move();
              if (v > best_value) best_value = v;
           }
    } else {
       best_value = MAX_PAYOFF;
       for (int i = 1; i <= COLS_NUM; ++i)
           if (board.can_move(i)) {
              board.do_move(i);
              int v = minmax(board, depth);
              board.undo_move();
              if (v < best_value) best_value = v;
           }
    }
    return best_value;
}

int minmax_player(const Board& board) {
    Board b = board;
    int best_value = b.max_play() ? -MAX_PAYOFF-1 : MAX_PAYOFF+1;
    int best_move;
    int depth = board.pieces_on_board / 10 + 7;
    for (int i = 1; i <= COLS_NUM; ++i)
        if (b.can_move(i)) {
           b.do_move(i);
           int v = minmax(b, depth);
           b.undo_move();
           if (b.max_play()) {
              if (v > best_value) {
                    best_value = v;
                    best_move = i;
                 }
           } else {
              if (v < best_value) {
                    best_value = v;
                    best_move = i;
                 }
           }
        }
    return best_move;
}

int alphabeta_player(const Board& board) {
    return minmax_player(board);           //TODO project 2
}

int mcts_player(const Board& board) {
    return minmax_player(board);           //TODO project 3
}
