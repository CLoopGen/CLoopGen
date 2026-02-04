#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sb_samples;
extern int *out_ptr;
extern int *buf;
extern int i;
extern int j;
extern int sblimit;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Index Array
    // Use an index lookup table to perform indirect memory access into buf,
    // simulating non-regular or data-dependent access patterns.
    // This could model scenarios where access pattern is not compile-time predictable.

    static const int index_map[18] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68}; // 4*i precomputed

    for (j = sblimit; j < 32; j++) {
        out_ptr = sb_samples + j;
        for (i = 0; i < 18; i++) {
            int idx = index_map[i]; // Indirect indexing
            *out_ptr = buf[idx];
            buf[idx] = 0;
            out_ptr += 32;
        }
        buf += (j & 3) != 3 ? 1 : (4 * 18 - 3);
    }
}
