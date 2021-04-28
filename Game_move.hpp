#ifndef GAME_MOVE_HPP
#define GAME_MOVE_HPP

#include"Game_default.hpp"
#include"Game_matrix.hpp"

bool is_game_over(vvi &board_game)
{
    for(int i = 0 ; i < 4 ; i++ )
        for(int j = 0 ; j < 4 ; j ++)
        {
            if(board_game[i][j] == 0) return false;
            if(j < 3 && board_game[i][j] == board_game[i][j + 1]) return false;
            if(i < 3 && board_game[i + 1][j] == board_game[i][j]) return false;
        }
    return true;
}

void move_left(vvi &board_game , bool &check , int &score)
{
    vvi arr1 = board_game;
    for(int i = 0 ; i < 4 ; i++)
    {
        int arr[4] = {0};
        int dem = 0 ;
        for(int j = 0 ; j < 4 ; j ++)
        {
            if(board_game[i][j])
                {
                    arr[dem] = board_game[i][j];
                    dem++;
                }
        }

        for(int j = 0 ; j < 3 ; j ++)
        {
            if(arr[j] == arr[j + 1])
            {
                score += arr[j];
                arr[j] *= 2;

                arr[j + 1] = 0;
            }
        }
        for(int j = 0 ; j < 3 ; j ++)
        {
            if(arr[j] == 0)
            {
                arr[j] = arr[j + 1];
                arr[j + 1] = 0;
            }
        }

        for(int j = 0 ; j < 4 ; j ++)
        {
            board_game[i][j] = arr[j];
        }

    }

    for(int i = 0 ; i < 4 ; i ++)
    {
        for(int j = 0 ; j < 4 ; j ++)
            if(arr1[i][j] != board_game[i][j])
            {
                check = true;
                break;
            }

    }
    if(check) score++;
}


void move_right(vvi &board_game , bool check , int &score)
{
    check = false;
    vvi arr1 = board_game;
     for(int i = 0 ; i < 4 ; i++)
    {
        int arr[4] = {0};
        int dem = 3 ;
        for(int j = 3 ; j >= 0 ; j --)
        {
            if(board_game[i][j])
                {
                    arr[dem] = board_game[i][j];
                    dem--;
                }
        }

        for(int j = 3 ; j > 0 ; j --)
        {
            if(arr[j] == arr[j - 1])
            {
                score += arr[j];
                arr[j] *= 2;

                arr[j - 1] = 0;
            }
        }

        for(int j = 3 ; j > 0 ; j --)
        {
            if(arr[j] == 0 )
            {
                arr[j] = arr[j - 1];
                arr[j - 1] = 0;
            }
        }
        for(int j = 3 ; j >= 0 ; j --)
            board_game[i][j] = arr[j];
    for(int i = 0 ; i < 4 ; i ++)
    {
        for(int j = 0 ; j < 4 ; j ++)
            if(arr1[i][j] != board_game[i][j])
            {
                check = true;

                break;
            }

    }
    }
     if(check) score++;

}
void move_up(vvi &board_game , bool &check , int &score)
{
    check = false;
    vvi arr1 = board_game;
    for(int j = 0 ; j < 4 ; j ++) // cột
    {
        int arr[4] = {0};
        int dem = 0 ;
        for(int i = 0 ; i < 4 ; i ++)
        {
            if(board_game[i][j]) {
                arr[dem] = board_game[i][j];
                dem ++;
            }
        }
        for(int i = 0 ; i < 4; i ++)
        {
            if(arr[i] == arr[i + 1])
            {
                score += arr[i];
                arr[i] *= 2;

                arr[i + 1] = 0 ;
            }
        }

        for(int i = 0; i < 3 ; i ++)
        {
            if(arr[i] == 0 )
            {
                arr[i] = arr[i + 1];
                arr[i + 1] = 0;
            }
        }
        for(int i = 0 ; i < 4 ; i++)
        {
            board_game[i][j] = arr[i];
        }

    }
    for(int i = 0 ; i < 4 ; i ++)
    {
        for(int j = 0 ; j < 4 ; j ++)
            if(arr1[i][j] != board_game[i][j])
            {
                check = true;
                break;
            }

    }
     if(check) score++;
}

void move_down(vvi & board_game , bool &check , int &score)
{
    check = false;
    vvi arr1 = board_game;
    for(int j = 0 ; j < 4 ; j ++)
    {
        int arr[4] = {0};
        int dem = 3;
        for(int i = 3 ; i >= 0 ; i --)
        {
            if(board_game[i][j])
            {
                arr[dem] = board_game[i][j];
                dem--;
            }
        }
        for(int i = 3 ; i > 0 ; i --)
        {
            if(arr[i] == arr[i - 1])
            {
                score += arr[i];
                arr[i] *= 2;

                arr[i - 1] = 0 ;
            }
        }
        for(int i = 3 ; i > 0 ; i --)
            if(arr[i] == 0 )
            {
                arr[i] = arr[i - 1];
                arr[i - 1] = 0;
            }
        for(int i = 0 ; i < 4 ; i ++)
            board_game[i][j] = arr[i];
    }
    for(int i = 0 ; i < 4 ; i ++)
    {
        for(int j = 0 ; j < 4 ; j ++)
            if(arr1[i][j] != board_game[i][j])
            {
                check = true;
                break;
            }

    }
     if(check) score++;
}


#endif // GAME_MOVE_HPP
