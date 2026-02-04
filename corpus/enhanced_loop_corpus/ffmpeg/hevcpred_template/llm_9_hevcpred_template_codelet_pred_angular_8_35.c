#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mode;
extern int x;
extern  uint8_t *left;
extern  int inv_angle[];
extern uint8_t *ref_tmp;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified indexing and expanded trip count
    // Loop runs over a larger range but uses precomputed base offset to minimize per-iteration math
    int base_shift = (last * inv_angle[mode - 11] + 128) >> 8;
    int step = inv_angle[mode - 11];
    int shift_accum = base_shift;

    for (x = last; x <= 1; x++) {  // Extended upper bound
        if (x <= -1) {
            ref_tmp[x] = left[-1 + shift_accum];
        }
        shift_accum += (step + 128) >> 8; // Simplified incremental update
    }
}
