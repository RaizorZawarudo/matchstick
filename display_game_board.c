/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-mickael.riess
** File description:
** display_game_board
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/matchstick.h"
#include "include/my.h"

void print_border(int j, int board_width)
{
    if (j == 0 || j == (board_width - 1))
        my_putchar('*');
}

void print_spaces(int i, int j, int board_width, matchstick_board *game)
{
    if (j == 0 || j == (board_width - 1))
        return;
    if (j < (game->lines - i) || j > (game->lines + i))
        my_putchar(' ');
}

void print_matches(int i, int j, int board_width, matchstick_board *game)
{
    if (j == 0 || j == (board_width - 1))
        return;
    if (j < (game->lines - i) || j > (game->lines + i))
        return;
    if (game->remaining_matches_print > 0) {
        my_putchar('|');
        game->remaining_matches_print = game->remaining_matches_print -1;
    }
    else
        my_putchar(' ');
}

void display_game(matchstick_board *game)
{
    int board_width = game->lines * 2 - 1 + 2;

    for (int i = 0 ; i < board_width; i++)
        my_putchar('*');
    my_putchar('\n');
    for (int i = 0; i < game->lines; i++)
    {
        game->remaining_matches_print = game->board_as_int[i];
        for (int j = 0; j < board_width; j++)
        {
            print_border(j, board_width);
            print_spaces(i, j, board_width, game);
            print_matches(i, j, board_width, game);
        }
        my_putchar('\n');
    }
    for (int i = 0 ; i < board_width; i++)
        my_putchar('*');
}