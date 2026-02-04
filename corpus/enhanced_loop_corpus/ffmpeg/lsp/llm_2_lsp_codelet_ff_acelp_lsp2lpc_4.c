#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lp;
extern int lp_half_order;
extern int i;
extern int f1[11];
extern int f2[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing f1[i], f1[i-1] and f2[i], f2[i-1], we pre-shift the base pointers
    // to make accesses consecutive and reduce index recalculations.
    // Also, lp is accessed symmetrically but rewritten with direct offsets.

    int16_t *lp_base = lp + 1;
    const int max_idx = lp_half_order;
    const int total_size = (lp_half_order << 1) + 1;

    for (i = 0; i < max_idx; i++) {
        int ff1 = f1[i + 1] + f1[i];
        int ff2 = f2[i + 1] - f2[i];
        ff1 += 1 << 10;
        lp_base[i] = (ff1 + ff2) >> 11;
        lp_base[total_size - 2 - i] = (ff1 - ff2) >> 11;
    }
}
