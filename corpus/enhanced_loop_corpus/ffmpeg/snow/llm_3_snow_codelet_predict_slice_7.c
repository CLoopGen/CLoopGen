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



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Precompute memory indices into an indirect lookup table, then traverse using pointers.
    // This simulates scenarios where access patterns are non-regular or data-dependent.
    int end_y = ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h));
    int num_elements = (end_y - block_h * mb_y) * w;
    int *indices = (int*)malloc(num_elements * sizeof(int));
    if (!indices) return; // Handle allocation failure

    int idx = 0;
    for (int y = block_h * mb_y; y < end_y; y++) {
        for (int x = 0; x < w; x++) {
            indices[idx++] = x + y * w;
        }
    }

    for (int i = 0; i < num_elements; i++) {
        buf[indices[i]] -= 128 << 4;
    }

    free(indices);
}
