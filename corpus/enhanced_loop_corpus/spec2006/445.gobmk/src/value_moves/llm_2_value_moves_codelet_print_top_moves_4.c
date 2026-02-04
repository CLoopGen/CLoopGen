#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, unrolled by processing two elements per iteration)
    for (k = 0; k < 10; k += 2) {
        int idx1 = k;
        int idx2 = k + 1;
        best_moves[idx1] = 0;
        best_move_values[idx1] = 0.;
        if (idx2 < 10) {
            best_moves[idx2] = 0;
            best_move_values[idx2] = 0.;
        }
    }
}
