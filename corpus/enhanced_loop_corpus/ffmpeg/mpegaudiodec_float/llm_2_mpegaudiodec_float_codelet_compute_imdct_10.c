#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *sb_samples;
extern float *out_ptr;
extern float *buf;
extern int i;
extern int j;
extern int sblimit;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access with Linear Buffer Traversal
    // Instead of strided access in the inner loop, reorganize buf access to be consecutive.
    // We precompute indices to traverse buf in a linear fashion while maintaining correctness.

    float *base_out;
    int idx = 0;
    for (j = sblimit; j < 32; j++) {
        base_out = sb_samples + j;
        float *buf_offset = buf;
        for (i = 0; i < 18; i++) {
            *base_out = buf_offset[0];           // buf[4*i] accessed via pointer arithmetic
            buf_offset[0] = 0;                   // zero out the current element
            buf_offset += 4;                     // simulate 4*i stride incrementally
            base_out += 32;
        }
        buf += (j & 3) != 3 ? 1 : (4 * 18 - 3);  // original buf update preserved
    }
}
