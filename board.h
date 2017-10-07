#ifndef CONNECT4_BOARD_H
#define CONNECT4_BOARD_H

#include <iostream>

#define COLS_NUM 7
#define ROWS_NUM 6

#define MAX_PAYOFF 1e9

/**
 * Objects of this class represent connect4 boards (game states).
 */
struct Board {

    char cells[ROWS_NUM + 2][COLS_NUM + 2 + 1];	//1..ROWS_NUM, 1..COLS_NUM include board content: 'X', 'O', ' '

    char history[ROWS_NUM*COLS_NUM];   //moves already done as an array of column numbers, valid index are from 0 to pieces_on_board-1

    char pieces_at_col[COLS_NUM + 1];  //how many pieces are placed in each column, indexed from 1, 1 to COLS_NUM are in use

    char pieces_on_board;  //number of moves already done

    Board();   //construct empty board

	// check if it is possible to make a move at column c
    bool can_move(int c) const {
        return pieces_at_col[c] < ROWS_NUM;
    }

	// check who has made last move, return "X" or "O"
    char who_play_recent() const {
        return "XO"[pieces_on_board % 2];
    }

    char who_play() const {
        return "OX"[pieces_on_board % 2];
    }
    
    bool max_play_recent() const {
         return (pieces_on_board % 2) == 1;
    }
    
    bool max_play() const {
         return (pieces_on_board % 2) == 0;
    }
    
    char who_play_01() const {
         return pieces_on_board % 2;
    }

    void do_move(int c) {
        pieces_at_col[c]++;
        cells[pieces_at_col[c]][c] = who_play();
        history[pieces_on_board] = c;
        pieces_on_board++;
    }

    void undo_move() {
        pieces_on_board--;
        char c = history[pieces_on_board];
        cells[pieces_at_col[c]][c] = ' ';
        pieces_at_col[c]--;
    }

    int scan(char p, int r, int c, int dr, int dc) const {
        int result = -1;
        do {
            r += dr;
            c += dc;
            result++;
        } while (cells[r][c] == p);
        return result;
    }

    bool is_win() const {
        char p = who_play_recent();
        int c = history[pieces_on_board-1];
        int r = pieces_at_col[c];
        return
          ((scan(p, r, c, 1, 0) + scan(p, r, c, -1, 0)) >= 3) ||
          ((scan(p, r, c, 0, 1) + scan(p, r, c, 0, -1)) >= 3) ||
          ((scan(p, r, c, 1, 1) + scan(p, r, c, -1, -1)) >= 3) ||
          ((scan(p, r, c, -1, 1) + scan(p, r, c, 1, -1)) >= 3);
    }

    bool is_full() const {
        return pieces_on_board == ROWS_NUM * COLS_NUM;
    }

    friend std::ostream& operator<<(std::ostream& out, const Board& b) {
        for (int r = ROWS_NUM+1; r >= 0; --r)
            out << b.cells[r] << std::endl;
        return out;
    }

    void print_details(std::ostream& out) const;
};

#endif // CONNECT4_BOARD_H
