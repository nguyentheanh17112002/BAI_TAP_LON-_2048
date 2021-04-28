#ifndef GAME_DRAW_HPP
#define GAME_DRAW_HPP

#define vvi vector<vector<int>>
#include"Game_default.hpp"
#include<string>



void draw(SDL_Renderer* &renderer , SDL_Surface* &surface , SDL_Texture * &texture , vvi &board_game , int &score){

    int x = 0 ;
    int y = 0;

    SDL_SetRenderDrawColor(renderer , 215 , 215 , 215 , 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer , 0 , 0 , 0 , 255);
    for(int i = 0 ; i < 4; i ++){
        SDL_Rect rect;
        for(int j = 0 ; j < 4 ; j++){
            rect.x = x;
            rect.y = y ;
            rect.w = BOX_WIDTH;
            rect.h = BOX_HEIGHT;
            SDL_RenderDrawRect(renderer , &rect);

            if(board_game[i][j]){
                int a = board_game[i][j];

                std::string text = to_string(a);

                SDL_Color fg1 = {223 , 0 , 41};
                SDL_Color fg2 = {148 , 83 , 5};
                SDL_Color fg3 = {249 , 244 , 0};
                SDL_Color fg4 = {91 , 189 , 43};
                SDL_Color fg5 = {0 , 174 , 114};
                SDL_Color fg6 = {0 , 178 , 191};
                SDL_Color fg7 = {32 , 90 , 167};
                SDL_Color fg8 = {81 , 31 , 144};
                SDL_Color fg9 = {100 , 0 , 75};


                TTF_Font* font = NULL;
                font = TTF_OpenFont("VeraMoBd.ttf", 100);

                if(a < 8)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg1);
                else if(a < 16 )
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg2);
                else if(a < 32 )
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg3);
                else if( a < 64)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg4);
                else if( a < 128)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg5);
                else if(a < 256)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg6);
                else if(a < 512)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg7);
                else if(a < 1024)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg8);
                else
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg9);




                texture = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_FreeSurface(surface);

                SDL_Rect srcRest;

                TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

                srcRest.x = 0;
                srcRest.y = 0;

                SDL_RenderCopy(renderer, texture, NULL, &rect);

            }

            x += BOX_WIDTH;
        }

        y += BOX_HEIGHT;
        x = 0;
    }
    // ve o score
    SDL_SetRenderDrawColor(renderer , 192 , 255 , 62 , 255);
    SDL_Rect rect1;
    rect1.x = BOX_WIDTH * 4;
    rect1.y = 0;
    rect1.w = BOX_WIDTH * 4;
    rect1.h = BOX_HEIGHT * 4;
    SDL_RenderFillRect(renderer , &rect1);

    string text1 = "SCORE";

    TTF_Font* font = NULL;
    font = TTF_OpenFont("VeraMoBd.ttf", 300);

    SDL_Color fg = {0 , 128 , 128};
    surface = TTF_RenderText_Solid(font, text1.c_str(), fg);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect2;
    rect2.x = BOX_WIDTH * 4;
    rect2.y = 0;
    rect2.w = BOX_WIDTH * 4;
    rect2.h = BOX_HEIGHT ;
    SDL_Rect srcRest;

    TTF_SizeText(font, text1.c_str(), &srcRest.w, &srcRest.h);

    srcRest.x = 0;
    srcRest.y = 0;

    SDL_RenderCopy(renderer, texture, &srcRest, &rect2);




    // ve diem so


    string text_score = to_string(score);
    SDL_Color fg_sc = {0 , 191 , 255};
    surface = TTF_RenderText_Solid(font, text_score.c_str(), fg_sc);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect3;
    rect3.x = BOX_WIDTH * 5;
    rect3.y = BOX_HEIGHT * 2;
    rect3.w = BOX_WIDTH * 2;
    rect3.h = BOX_HEIGHT * 2;

    TTF_SizeText(font, text_score.c_str(), &srcRest.w, &srcRest.h);

    SDL_RenderCopy(renderer, texture, &srcRest, &rect3);


    SDL_RenderPresent(renderer);
}

void game_over(SDL_Renderer* &renderer , SDL_Surface* &surface , SDL_Texture * &texture , vvi &board_game , int &score)
{
    int x = 0 ;
    int y = 0;

    SDL_SetRenderDrawColor(renderer , 215 , 215 , 215 , 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer , 0 , 0 , 0 , 255);
    for(int i = 0 ; i < 4; i ++){
        SDL_Rect rect;
        for(int j = 0 ; j < 4 ; j++){
            rect.x = x;
            rect.y = y ;
            rect.w = BOX_WIDTH;
            rect.h = BOX_HEIGHT;
            SDL_RenderDrawRect(renderer , &rect);

            if(board_game[i][j]){
                int a = board_game[i][j];

                std::string text = to_string(a);

                SDL_Color fg1 = {223 , 0 , 41};
                SDL_Color fg2 = {148 , 83 , 5};
                SDL_Color fg3 = {249 , 244 , 0};
                SDL_Color fg4 = {91 , 189 , 43};
                SDL_Color fg5 = {0 , 174 , 114};
                SDL_Color fg6 = {0 , 178 , 191};
                SDL_Color fg7 = {32 , 90 , 167};
                SDL_Color fg8 = {81 , 31 , 144};
                SDL_Color fg9 = {100 , 0 , 75};


                TTF_Font* font = NULL;
                font = TTF_OpenFont("VeraMoBd.ttf", 100);

                if(a < 8)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg1);
                else if(a < 16 )
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg2);
                else if(a < 32 )
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg3);
                else if( a < 64)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg4);
                else if( a < 128)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg5);
                else if(a < 256)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg6);
                else if(a < 512)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg7);
                else if(a < 1024)
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg8);
                else
                    surface = TTF_RenderText_Solid(font, text.c_str(), fg9);




                texture = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_FreeSurface(surface);

                SDL_Rect srcRest;

                TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

                srcRest.x = 0;
                srcRest.y = 0;

                SDL_RenderCopy(renderer, texture, &srcRest, &rect);

            }

            x += BOX_WIDTH;
        }

        y += BOX_HEIGHT;
        x = 0;
    }

    SDL_SetRenderDrawColor(renderer , 192 , 255 , 62 , 255);
    SDL_Rect rect1;
    rect1.x = BOX_WIDTH * 4;
    rect1.y = 0;
    rect1.w = BOX_WIDTH * 4;
    rect1.h = BOX_HEIGHT * 4;
    SDL_RenderFillRect(renderer , &rect1);

    string text1 = "GAME OVER";

    TTF_Font* font = NULL;
    font = TTF_OpenFont("VeraMoBd.ttf", 300);

    SDL_Color fg = {0 , 128 , 128};
    surface = TTF_RenderText_Solid(font, text1.c_str(), fg);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect2;
    rect2.x = BOX_WIDTH * 4;
    rect2.y = 0;
    rect2.w = BOX_WIDTH * 4;
    rect2.h = BOX_HEIGHT ;
    SDL_Rect srcRest;

    TTF_SizeText(font, text1.c_str(), &srcRest.w, &srcRest.h);

    srcRest.x = 0;
    srcRest.y = 0;

    SDL_RenderCopy(renderer, texture, &srcRest, &rect2);

    string text_score = "Score: " + to_string(score);
    SDL_Color fg_sc = {0 , 191 , 255};
    surface = TTF_RenderText_Solid(font, text_score.c_str(), fg_sc);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect3;
    rect3.x = BOX_WIDTH * 4;
    rect3.y = BOX_HEIGHT ;
    rect3.w = BOX_WIDTH * 4;
    rect3.h = BOX_HEIGHT * 2;

    TTF_SizeText(font, text_score.c_str(), &srcRest.w, &srcRest.h);

    SDL_RenderCopy(renderer, texture, &srcRest, &rect3);

    font = NULL;
    font = TTF_OpenFont("VeraMoBd.ttf", 500);



    string text_quit ="Press any key to quit!";
    SDL_Color fg_quit {223 , 0 , 41};
    surface = TTF_RenderText_Solid(font, text_quit.c_str(), fg_quit);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect4;
    rect4.x = BOX_WIDTH * 4;
    rect4.y = 350;
    rect4.w = BOX_WIDTH * 4;
    rect4.h = 50;


    TTF_SizeText(font, text_score.c_str(), &srcRest.w, &srcRest.h);

    SDL_RenderCopy(renderer, texture, NULL, &rect4);

    SDL_RenderPresent(renderer);
}



#endif // GAME_DRAW_HPP
