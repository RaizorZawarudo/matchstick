/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-mickael.riess
** File description:
** ai_plays
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/matchstick.h"
#include "include/my.h"

void apply_ai_move(matchstick_board *game)
{
    int ai_line_choice = random() % (game->lines);
    int ai_match_amount;
    while (game->board_as_int[ai_line_choice] <= 0)
        ai_line_choice = random() % (game->lines);
    ai_match_amount = random() % (game->max_sticks + 1);
    while (ai_match_amount > game->board_as_int[ai_line_choice])
        ai_match_amount = random() % game->board_as_int[ai_line_choice];
    if (ai_match_amount == 0)
        ai_match_amount++;
    my_putstr("\n\nAI's turn...\n");
    game->board_as_int[ai_line_choice] =
    game->board_as_int[ai_line_choice] - ai_match_amount;
    my_putstr("AI removed ");
    my_put_nbr(ai_match_amount);
    my_putstr(" match(es) from line ");
    my_put_nbr(ai_line_choice + 1);
    my_putchar('\n');
    game->who_can_win = PLAYER;
}