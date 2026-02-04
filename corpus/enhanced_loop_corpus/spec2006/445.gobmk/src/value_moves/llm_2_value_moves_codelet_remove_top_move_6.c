#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int move;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 10; k++) {
    if (best_moves[k] == move) {
        int l;
        for (l = k + 1; l < 10; l++) {
            best_moves[l - 1] = best_moves[l];
            best_move_values[l - 1] = best_move_values[l];
        }
        best_moves[9] = 0;
        best_move_values[9] = 0.;
    }
}
}
