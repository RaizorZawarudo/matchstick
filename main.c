/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-mickael.riess
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/matchstick.h"
#include "include/my.h"

static int check_args(int argc, char **argv)
{
    int lines;
    int max_match_grab;
    if (argc != 3)
        return FAIL_RETURN;
    if (!my_str_isnum(argv[1]) || !my_str_isnum(argv[2])) {
        my_putstr("Only integer numbers as parameters");
        return FAIL_RETURN;
    }
    lines = my_getnbr(argv[1]);
    max_match_grab = my_getnbr(argv[2]);
    if (lines <= 1 || lines >= 100 || max_match_grab <= 0)
        return FAIL_RETURN;
    return SUCCESS_RETURN;
}

static void play_matchstick(matchstick_board *game)
{
     while (game->gameover == 0) {
        my_putstr("\n\nYour turn:\n");
        play_a_round(game);
    }
}

int main(int argc, char **argv)
{
    matchstick_board *game = NULL;

    if (check_args(argc, argv) == FAIL_RETURN)
        return FAIL_RETURN;
    game = game_setup(argv);
    display_game(game);
    play_matchstick(game);
    return game->who_can_win;
}