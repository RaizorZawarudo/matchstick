/*
** EPITECH PROJECT, 2021
** B-CPE-200-BER-2-1-matchstick-mickael.riess
** File description:
** play_a_round
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/matchstick.h"
#include "include/my.h"

int check_user_line_input(char *buffer, matchstick_board *game)
{
    if (!my_str_isnum(buffer)) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    }
    if (my_getnbr(buffer) <= 0 || my_getnbr(buffer) > game->lines) {
        my_putstr("Error: this line is out of range\n");
        return (0);
    }
    return (1);
}

int check_user_match_input(char *secondbuffer, matchstick_board *game)
{
    if (!my_str_isnum(secondbuffer)) {
        my_putstr("Please enter a number for the matches to be picked\n");
        return (0);
    }
    if (my_getnbr(secondbuffer) <= 0) {
        my_putstr("Please enter a number between 1 and the max matches\n");
        return (0);
    }
    if (my_getnbr(secondbuffer) > game->max_sticks) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->max_sticks);
        my_putstr(" matches per turn\n");
        return (0);
    }
    return (1);
}

int check_game_board(matchstick_board *game, char *buffer, char *secondbuffer)
{
    if (game->board_as_int[my_getnbr(buffer) - 1] < my_getnbr(secondbuffer)){
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    }
    return (1);
}

int ask_player(matchstick_board *game)
{
    my_putstr("Line: ");
    if ((getline(&game->buffer, &game->line_choice, stdin) == -1))
        return 9000;
    if (!check_user_line_input(game->buffer, game)) {
        game->buffer = NULL;
        ask_player(game);
        return 1;
    }
    my_putstr("Matches: ");
    if ((getline(&game->secondbufr, &game->match_amount_choice, stdin) == -1))
        return 9000;
    if (!check_user_match_input(game->secondbufr, game)) {
        game->secondbufr = NULL;
       ask_player(game);
       return 1;
    }
    if (!check_game_board(game, game->buffer, game->secondbufr)) {
        game->buffer = NULL;
        game->secondbufr = NULL;
        ask_player(game);
        return 1;
    }
    game->player_line_choice = my_getnbr(game->buffer);
    game->player_match_amount = my_getnbr(game->secondbufr);
    return 1;
}

void play_a_round(matchstick_board *game)
{
    if (ask_player(game) == 9000) {
        game->who_can_win = 0;
        game->gameover = 9000;
        return;
    }
    apply_player_move(game); 
    display_game(game);
    check_win(game);
    if (game->gameover != 0)
        return;
    apply_ai_move(game);
    display_game(game);
    check_win(game);
}