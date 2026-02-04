#include <stdint.h>

int move_history_color[500];
int move_history_pos[500];
int move_history_pointer;
int number_collapsed_moves;
int k;

void init_vars() {
    move_history_pointer = 500;
    number_collapsed_moves = 250;

    for (int i = 0; i < 500; i++) {
        move_history_color[i] = i * 3;
        move_history_pos[i] = i * 7;
    }
}