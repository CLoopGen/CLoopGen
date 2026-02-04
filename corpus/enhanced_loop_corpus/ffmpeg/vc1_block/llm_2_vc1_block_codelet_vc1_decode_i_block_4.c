#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int16_t *ac_val;
extern int k;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access
    // Instead of strided access (k << sh), rewrite to access block consecutively
    // by precomputing the base index and using sequential offsets.
    int base_idx = 1 << sh;
    for (k = 0; k < 7; k++) {
        block[base_idx + k] += ac_val[k + 1];
    }
}
