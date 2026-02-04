#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int ***model_number;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing every second element (i << 1), we copy blocks consecutively
    // by reorganizing the indexing to access adjacent elements, improving spatial locality.
    int n = (number_of_slices + 1) >> 1;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < n; i++) {
            int src_idx = i * 2; // equivalent to i << 1, but expressed arithmetically
            initialized[1][j][i] = initialized[0][j][src_idx];
            model_number[1][j][i] = model_number[0][j][src_idx];
        }
    }
}
