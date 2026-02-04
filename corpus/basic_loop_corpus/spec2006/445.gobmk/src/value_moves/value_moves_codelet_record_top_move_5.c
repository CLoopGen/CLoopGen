#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int move;
extern float val;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 9; k >= 0; k--)
    if (val > best_move_values[k]) {
        if (k < 9) {
            best_move_values[k + 1] = best_move_values[k];
            best_moves[k + 1] = best_moves[k];
        }
        best_move_values[k] = val;
        best_moves[k] = move;
    }

}
