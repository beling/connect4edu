#include "board.h"
#include "utils.h"
#include "players.h"

player_f* ask_for_player_type() {
          std::cout << " h - human, m - minmax, a - alpha-beta, c - mcts" << std::endl;
          switch (ask("hmac")) {
            case 'h': return human_player;
            case 'm': return minmax_player;
            case 'a': return alphabeta_player;
            case 'c': return mcts_player;
          }
}

int main(int argc, char *argv[])
{
    Board b;
    
    player_f *player_1, *player_2;
    
    std::cout << "Player 1 (O)?";
    player_1 = ask_for_player_type();
    
    std::cout << "Player 2 (X)?";
    player_2 = ask_for_player_type();

    std::cout << b << std::endl;
    while (!b.is_win() && !b.is_full()) {
        int col = b.max_play() ? player_1(b) : player_2(b);
        b.do_move(col);
        std::cout << b;
        for (int i = 0; i < col; ++i) std::cout << ' ';
        std::cout << '^' << std::endl;
    }
    
    if (b.is_win())
       std::cout << b.who_play_recent() << " wins!" << std::endl;
    else
       std::cout << " draw!";
       
    std::cout << "q to quit" << std::endl;
    ask("");

    return 0;
}
