#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int k;
extern int curr_diff[8][8];
extern int diff8x8[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // Access is now row-major in the source, leading to better spatial locality
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            diff8x8[j * 8 + i] = curr_diff[j][i];
}
