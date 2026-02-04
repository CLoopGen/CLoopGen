#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;
extern int a1;
extern int b1;
extern int a0;
extern int b0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access via Index Vector (Simulated Indirect Access)
    // Use an index array to simulate non-contiguous, strided memory access.
    // This models scenarios where data is accessed through precomputed indices.

    int stride = (int)line_size;
    // Precompute relative offsets for two consecutive rows (simplified as compile-time constants)
    int offset[2] = {0, stride};  // Simulate indirect access via offset table

    uint8_t *p_base = pixels;
    uint8_t *b_base = block;

    for (i = 0; i < h; i += 2) {
        // First row using offset[0]
        a1 = p_base[offset[0] + 0];
        b1 = p_base[offset[0] + 1];
        a1 += b1;
        b1 += p_base[offset[0] + 2];

        b_base[offset[0] + 0] = (a1 + a0) >> 2;
        b_base[offset[0] + 1] = (b1 + b0) >> 2;

        // Second row using offset[1]
        a0 = p_base[offset[1] + 0];
        b0 = p_base[offset[1] + 1] + 2;
        a0 += b0;
        b0 += p_base[offset[1] + 2];

        b_base[offset[1] + 0] = (a1 + a0) >> 2;
        b_base[offset[1] + 1] = (b1 + b0) >> 2;

        // Move base pointers forward by two strides
        p_base += stride * 2;
        b_base += stride * 2;
    }
}
