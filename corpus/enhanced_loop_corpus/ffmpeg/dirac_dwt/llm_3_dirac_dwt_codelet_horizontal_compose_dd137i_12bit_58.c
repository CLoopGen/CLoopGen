#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Reverse Traversal and Stride-2 Access
    // Traverse the loop backwards with a stride of 2 to alter memory access pattern.
    // This changes temporal and spatial locality, simulating a different cache behavior.
    for (x = w2 - (w2 % 2); x >= 0; x -= 2) {
        // Handle two iterations at once in reverse order with strided access
        // First handle x
        {
            int val = tmp[x];
            b[2 * x] = ((int)(val + 1U)) >> 1;
            int offset_b = x + w2;
            int sum_tmp = 9U * val + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8;
            int filtered = (int)(((unsigned int)(b[offset_b]) + ((int)(sum_tmp >> 4))) + 1U) >> 1;
            b[2 * x + 1] = filtered;
        }
        // Then handle x-1 if within bounds
        if (x > 0) {
            int prev = x - 1;
            int val_prev = tmp[prev];
            b[2 * prev] = ((int)(val_prev + 1U)) >> 1;
            int offset_b_prev = prev + w2;
            int sum_tmp_prev = 9U * val_prev + 9U * tmp[prev + 1] - tmp[prev + 2] - tmp[prev - 1] + 8;
            int filtered_prev = (int)(((unsigned int)(b[offset_b_prev]) + ((int)(sum_tmp_prev >> 4))) + 1U) >> 1;
            b[2 * prev + 1] = filtered_prev;
        }
    }
}
