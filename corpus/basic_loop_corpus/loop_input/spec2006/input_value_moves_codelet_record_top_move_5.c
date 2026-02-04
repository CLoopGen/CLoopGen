#include <stdio.h>
#include <inttypes.h>

float best_move_values[10] = {0.0f};
int best_moves[10] = {0};
int move = 0;
float val = 0.0f;
int k = 0;

void init_vars() {
    for (int i = 0; i < 10; i++) {
        best_move_values[i] = (float)(9 - i) * 10.0f;
        best_moves[i] = i;
    }
    move = 42;
    val = 45.0f;
}