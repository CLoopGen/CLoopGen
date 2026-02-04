#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int move;
extern float val;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    float *val_ptr = best_move_values + 9;
    int *move_ptr = best_moves + 9;
    for (k = 9; k >= 0; k--) {
        if (val > *val_ptr) {
            if (k < 9) {
                *(val_ptr + 1) = *val_ptr;
                *(move_ptr + 1) = *move_ptr;
            }
            *val_ptr = val;
            *move_ptr = move;
        }
        val_ptr--;
        move_ptr--;
    }
}
