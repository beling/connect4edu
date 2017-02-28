#include "board.h"

#include <cstring>


Board::Board()
    : pieces_on_board(0)
{
    for (int c = 0; c <= COLS_NUM; ++c)
        pieces_at_col[c] = 0;
    strcpy(cells[0], "#1234567#");
    strcpy(cells[7], "#1234567#");
    for (int r = 1; r <= 6; ++r)
        strcpy(cells[r], "#       #");
}

void Board::print_details(std::ostream& out) const {
    out << *this;
    out << "pieces on board: " << int(pieces_on_board) << std::endl;
    out << "pieces at cols:";
    for (int c = 1; c <= COLS_NUM; ++c)
        out << ' ' << int(pieces_at_col[c]);
    out << std::endl;
    out << "history:";
    for (int h = 0; h < pieces_on_board; ++h)
        std::cout << ' ' << int(history[h]);
}
