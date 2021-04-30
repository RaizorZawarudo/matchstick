/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-mickael.riess
** File description:
** play_a _round_after_checks
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/matchstick.h"
#include "include/my.h"

void apply_player_move(matchstick_board *game)
{
    my_putstr("Player removed ");
    my_put_nbr(game->player_match_amount);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->player_line_choice);
    my_putchar('\n');
    game->board_as_int[game->player_line_choice - 1] =
    game->board_as_int[game->player_line_choice - 1] -
    game->player_match_amount;
    game->who_can_win = AI;
}

void check_win(matchstick_board *game)
{
    for (int i = 0; i < game->lines; i++) {
        if (game->board_as_int[i] > 0)
            return;
    }
    if (game->who_can_win == AI)
        my_putstr("\nYOU LOSE NOOB\n");
    if (game->who_can_win == PLAYER)
        my_putstr("\nCONGRATZ BIG BOI YOU WON\n");
    game->gameover = 1;
}