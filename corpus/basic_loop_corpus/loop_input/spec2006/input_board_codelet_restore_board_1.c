#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char Intersection;

struct board_state {
    int board_size;
    Intersection board[421];
    int board_ko_pos;
    int black_captured;
    int white_captured;
    Intersection initial_board[421];
    int initial_board_ko_pos;
    int initial_white_captured;
    int initial_black_captured;
    int move_history_color[500];
    int move_history_pos[500];
    int move_history_pointer;
    float komi;
    int move_number;
};

int move_history_color[500];
int move_history_pos[500];
int move_history_pointer;
struct board_state *state;
int k;

void init_vars() {
    state = (struct board_state*)malloc(sizeof(struct board_state));
    if (!state) return;
    state->move_history_pointer = 500;
    for (int i = 0; i < 500; i++) {
        state->move_history_color[i] = i % 2;
        state->move_history_pos[i] = i * 2;
    }
    move_history_pointer = 500;
}