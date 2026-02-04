#include <stdio.h>

#include <inttypes.h>

extern float best_move_values[10];
extern int best_moves[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulates non-sequential access pattern)
    int access_order[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    for (k = 0; k < 10; k++) {
        int idx = access_order[k];
        best_moves[idx] = 0;
        best_move_values[idx] = 0.;
    }
}
