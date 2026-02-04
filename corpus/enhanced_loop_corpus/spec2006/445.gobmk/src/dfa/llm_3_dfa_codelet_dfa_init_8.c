#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via arithmetic)
    int indices[4 * 21 * 4 * 21];
    for (int temp_ii = 0; temp_ii < 4 * 21 * 4 * 21; temp_ii++) {
        indices[temp_ii] = temp_ii; // Identity mapping for simplicity, could be randomized or reordered
    }
    for (ii = 0; ii < 4 * 21 * 4 * 21; ii++) {
        dfa_p[indices[ii]] = 3;
    }
}
