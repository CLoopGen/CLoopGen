#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int move;
extern float val;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_val = val;
    int prev_move = move;
    int inserted = 0;
    for (k = 9; k >= 0; k--) {
        float current_val = best_move_values[k];
        int current_move = best_moves[k];
        if (!inserted && prev_val > best_move_values[k]) {
            if (k < 9) {
                best_move_values[k + 1] = current_val;
                best_moves[k + 1] = current_move;
            }
            best_move_values[k] = prev_val;
            best_moves[k] = prev_move;
            inserted = 1;
        } else if (!inserted) {
            inserted = 1;
            if (k < 9) {
                best_move_values[k + 1] = prev_val;
                best_moves[k + 1] = prev_move;
            }
            break;
        } else {
            break;
        }
    }
    if (!inserted && k < 0) {
        best_move_values[0] = prev_val;
        best_moves[0] = prev_move;
    }
}
