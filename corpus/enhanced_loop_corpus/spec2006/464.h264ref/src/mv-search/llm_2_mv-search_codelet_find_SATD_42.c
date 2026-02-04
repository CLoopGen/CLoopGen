#include <stdio.h>

#include <inttypes.h>

extern int curr_diff[16][16];
extern int i;
extern int j;
extern int k;
extern int x;
extern int y;
extern int block_size_x;
extern int block_size_y;
extern int block_size;
extern int diff[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Linearization
    // Instead of accessing curr_diff[j][i] in nested loops, we precompute indices
    // to enable more predictable and consecutive memory writes to diff.
    int base_k = 0;
    for (y = 0; y < block_size_y; y += block_size)
        for (x = 0; x < block_size_x; x += block_size) {
            int idx = y * 16 + x; // Base index into flattened curr_diff
            for (j = 0; j < block_size; j++)
                for (i = 0; i < block_size; i++) {
                    diff[base_k] = curr_diff[y + j][x + i];
                    base_k++;
                }
        }
}
