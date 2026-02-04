#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t width;
extern  size_t height;
extern  size_t scaled_width;
extern unsigned char *pixels;
extern ssize_t x;
extern ssize_t y;
extern unsigned char *p;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetched Pointers
    // Instead of decrementing p and q inside the inner loop, we precompute the entire row access
    // and traverse in forward direction using consecutive indexing to improve cache locality.

    for (y = 0; y < (ssize_t)height; y++) {
        size_t row_idx = height - 1 - (size_t)y;
        p = pixels + row_idx * scaled_width;
        q = pixels + (row_idx << 1) * scaled_width;

        // Handle last element separately to match original backward logic
        size_t p_offset = width - 1;
        size_t q_offset = (width - 1) << 1;

        q[q_offset] = p[p_offset];
        q[q_offset + 1] = p[p_offset];

        // Now process the rest in decreasing x order, but accessed via base + offset (forward-friendly)
        for (x = 1; x < (ssize_t)width; x++) {
            size_t curr_p = p_offset - x;
            size_t curr_q = q_offset - (x << 1);

            q[curr_q] = p[curr_p];
            q[curr_q + 1] = (unsigned char)((((size_t)p[curr_p]) + ((size_t)p[curr_p + 1]) + 1) >> 1);
        }
    }
}
