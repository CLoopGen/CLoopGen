#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Higher trip count with nested loops and minimal per-iteration work
    int total_size = 4 * 21 * 4 * 21;
    int outer = total_size / 16;
    int inner = 16;
    for (ii = 0; ii < outer; ii++) {
        for (int jj = 0; jj < inner; jj++) {
            int index = ii * inner + jj;
            dfa_p[index] = 3;
            // Add light computation to maintain non-triviality
            index ^= index >> 2;
        }
    }
    // Handle any remaining elements if total_size is not divisible by 16
    for (int r = outer * inner; r < total_size; r++) {
        dfa_p[r] = 3;
    }
}
