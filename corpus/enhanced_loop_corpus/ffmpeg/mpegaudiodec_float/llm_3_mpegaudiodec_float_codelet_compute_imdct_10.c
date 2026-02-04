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
    // Variant 2: Indirect Array Access via Index Array
    // Use an array of precomputed indices for buf to demonstrate indirect memory access.
    // This simulates scenarios where access patterns are data-dependent or non-uniform.

    static const int index_map[18] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68}; // 4*i for i in [0,17]
    float *out_ptr_base;
    for (j = sblimit; j < 32; j++) {
        out_ptr_base = sb_samples + j;
        for (i = 0; i < 18; i++) {
            int idx = index_map[i];              // Indirect access through lookup
            *out_ptr_base = buf[idx];
            buf[idx] = 0;
            out_ptr_base += 32;
        }
        buf += (j & 3) != 3 ? 1 : (4 * 18 - 3);
    }
}
