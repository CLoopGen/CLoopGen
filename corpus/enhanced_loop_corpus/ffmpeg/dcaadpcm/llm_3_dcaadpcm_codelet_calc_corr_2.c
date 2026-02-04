#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *x;
extern int len;
extern int j;
extern int k;
extern int n;
extern int64_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with offset base pointer simulation
    // Rebase the array accesses to create consecutive access pattern by pre-adjusting indices
    // This variant simulates accessing two sliding windows with constant offsets
    int base_j = -j;
    int base_k = -k;
    for (n = 0; n < len; n++) {
        // Access pattern becomes x[base_j + n] and x[base_k + n] → more cache-friendly if base offsets are aligned
        s += ((int64_t)(x[base_j + n]) * (int64_t)(x[base_k + n]));
    }
}
