
#include"Game_default.hpp"
#include"Game_create_random.hpp"
#include"Game_matrix.hpp"
#include"Game_draw.hpp"
#include"Game_move.hpp"
#include"Game_Solve_event.hpp"


using namespace std;

int main(int argc , char * argv[])
{
    vvi board_game {{0 , 0 , 0 , 0} , {0 , 0 , 0 ,0 } , {0 , 0 ,0 ,0 } , {0 , 0 , 0 ,0}};

    srand(time(NULL));

    int score = 0;

    update_board_game(board_game);
    update_board_game(board_game);
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Event e;

    initSDL(window, renderer);

    Mix_Music* music = NULL;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		printf("%s", Mix_GetError());
		return -1;
	}


	music = Mix_LoadMUS("2048.mp3");
	if (music == NULL)
	{
		printf("%s", Mix_GetError());
	}
    Mix_PlayMusic(music, -1);

    draw(renderer , surface , texture , board_game , score);
    while(!is_game_over(board_game))
    {
        bool check = false;
        solve_event(e , board_game , check , score);

        if(check)
        {
            update_board_game(board_game);
        }
        draw(renderer , surface , texture , board_game ,score);

    }


    game_over(renderer , surface , texture , board_game , score);

    waitUntilKeyPressed();

    return 0;
}
