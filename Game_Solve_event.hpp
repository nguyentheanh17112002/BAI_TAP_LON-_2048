#ifndef GAME_SOLVE_EVENT_HPP_
#define GAME_SOLVE_EVENT_HPP_

#include"Game_move.hpp"
#include"Game_default.hpp"


void solve_event(SDL_Event &e , vvi &board_game , bool &check , int &score)
{
    while(true)
    {
        if(SDL_PollEvent(&e) == 0) continue;
        if(e.type == SDL_KEYDOWN )
        {
            if(e.key.keysym.sym == SDLK_LEFT)
            {
                move_left(board_game , check ,score);
                break;
            }
            else if(e.key.keysym.sym == SDLK_RIGHT)
            {
                move_right(board_game , check , score );
                break;
            }
            else if(e.key.keysym.sym == SDLK_DOWN)
            {
                move_down(board_game , check , score );
                break;
            }
            else if(e.key.keysym.sym == SDLK_UP)
            {
                move_up(board_game , check , score );
                break;
            }
        }
    }
}



#endif // GAME_SOLVE_EVENT_HPP_
