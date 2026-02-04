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
    // Variant 1: Consecutive Memory Access with Linear Buffer Layout
    // Instead of strided access in the original (buf[4*i]), we reorganize to access buf consecutively.
    // We assume buf is now laid out as a linear array where every 4th element is grouped together.
    // Here, we precompute indices to enable sequential reads and reduce stride.

    for (j = sblimit; j < 32; j++) {
        out_ptr = sb_samples + j;
        int *buf_base = buf + (j & 3) * 18; // Distribute access based on j mod 4
        for (i = 0; i < 18; i++) {
            *out_ptr = buf_base[i];         // Now accessing buf_base[i] consecutively
            buf_base[i] = 0;                // Zero out after use
            out_ptr += 32;
        }
        if ((j & 3) != 3) {
            buf++; // Advance buf base slowly
        } else {
            buf += (4 * 18 - 3); // Jump ahead when cycle completes
        }
    }
}
