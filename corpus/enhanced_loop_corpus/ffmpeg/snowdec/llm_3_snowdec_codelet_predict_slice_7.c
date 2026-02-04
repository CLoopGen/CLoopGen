#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Precompute valid linear indices and access buffer indirectly
    // Simulates irregular or gather-style access pattern
    int start_y = block_h * mb_y;
    int end_y = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);
    int total_elements = (end_y - start_y) * w;
    int *indices = (int*)malloc(total_elements * sizeof(int));
    
    if (!indices) return; // Handle allocation failure

    int idx = 0;
    for (y = start_y; y < end_y; y++) {
        for (x = 0; x < w; x++) {
            indices[idx++] = x + y * w;
        }
    }

    for (idx = 0; idx < total_elements; idx++) {
        buf[indices[idx]] -= 128 << 4;
    }

    free(indices);
}
