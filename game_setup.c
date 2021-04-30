/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-mickael.riess
** File description:
** game_setup
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/matchstick.h"
#include "include/my.h"

matchstick_board *game_setup(char **argv)
{
    int n = 0;
    matchstick_board *game = malloc(sizeof(matchstick_board));
    game->lines = my_getnbr(argv[1]);
    game->max_sticks = my_getnbr(argv[2]);
    game->board_as_int = malloc(sizeof(int) * game->lines);
    game->gameover = 0;
    game->who_can_win = 0;
    srandom(my_getnbr(argv[1]));
    game->buffer = NULL;
    game->secondbufr = NULL;
    for (int i = 0; i < game->lines; i++) {
        game->board_as_int[i] =  1 + n;
        n = n + 2;
    }
    return game;
}