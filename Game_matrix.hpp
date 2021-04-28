#ifndef GAME_MATRIX_HPP_
#define GAME_MATRIX_HPP_

#include"Game_default.hpp"
#include"Game_create_random.hpp"


void update_board_game(vvi &board_game)
{
        while(true)
        {
            pos a = create_random_pos();
            if(board_game[a.x][a.y] == 0)
            {
                board_game[a.x][a.y] = creat_random_value();
                break;
            }
        }
}

#endif // GAME_MATRIX_HPP_
