#include <stdio.h>
#include <inttypes.h>

float best_move_values[10] = {0.0f};
int best_moves[10] = {0};
int move = 0;
int k = 0;

void init_vars() {
    for (int i = 0; i < 10; i++) {
        best_moves[i] = i;
        best_move_values[i] = (float)(i * 1.5);
    }
    move = 5;
}