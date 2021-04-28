#ifndef GAME_CREATE_RANDOM_HPP_
#define GAME_CREATE_RANDOM_HPP_

#include<bits/stdc++.h>

struct pos{
    int x ;
    int y;
};

pos create_random_pos()
{
    pos a;
    a.x = rand() % 4;
    a.y = rand() % 4;
    return a;
}

int creat_random_value()
{
    int a = rand() % 20 ;
    if (a < 4) return 4;
    else return 2;
}

#endif // GAME_CREATE_RANDOM_HPP_
