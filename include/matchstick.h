/*
** EPITECH PROJECT, 2021
** B-PSU-200-BER-2-1-mysokoban-mickael.riess
** File description:
** sokoban
*/

#define FAIL_RETURN 84
#define SUCCESS_RETURN 0
#define AI 2
#define PLAYER 1

typedef struct matchstick_board {
    char *buffer;
    char *secondbufr;
    int *board_as_int;
    int lines;
    int max_sticks;
    int remaining_matches_print;
    int gameover;
    int player_line_choice;
    int player_match_amount;
    int who_can_win;
    size_t line_choice;
    size_t match_amount_choice;
} matchstick_board;

void apply_ai_move(matchstick_board *game);
void check_win(matchstick_board *game);
int ask_player(matchstick_board *game);
void apply_player_move(matchstick_board *game);
void play_a_round(matchstick_board *game);
matchstick_board *game_setup(char **argv);
void display_game(matchstick_board *game);
