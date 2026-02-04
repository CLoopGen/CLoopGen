#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int move;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 10; k += 2) {
    int indices[2] = {k, k + 1};
    for (int idx = 0; idx < 2; idx++) {
        int pos = indices[idx];
        if (pos < 10 && best_moves[pos] == move) {
            for (int l = pos; l < 9; l++) {
                best_moves[l] = best_moves[l + 1];
                best_move_values[l] = best_move_values[l + 1];
            }
            best_moves[9] = 0;
            best_move_values[9] = 0.;
        }
    }
}
}
