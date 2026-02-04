#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed input indexing
    // Instead of accessing input[k] and input[8+k] with decreasing k,
    // reindex to traverse input in a forward consecutive manner.
    int base = 7;
    for (i = 8; i < 16; i++) {
        int idx = base - (i - 8); // k decreases from 7 to 0 as i increases
        output[i] = input[idx] - input[8 + idx];
    }
}
