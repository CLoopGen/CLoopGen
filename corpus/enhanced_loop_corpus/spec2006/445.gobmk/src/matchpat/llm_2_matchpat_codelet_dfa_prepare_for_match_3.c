#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (ii = 0; ii < 4 * 21 * 4 * 21; ii += 2) {
        dfa_p[ii] = 3;
    }
    // Fill the skipped elements in a second pass to maintain correctness
    for (ii = 1; ii < 4 * 21 * 4 * 21; ii += 2) {
        dfa_p[ii] = 3;
    }
}
