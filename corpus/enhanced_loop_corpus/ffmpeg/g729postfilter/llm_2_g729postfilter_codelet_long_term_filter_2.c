#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *residual;
extern int subframe_size;
extern int i;
extern int16_t shift;
extern int16_t sig_scaled[192];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // This variant accesses memory in pairs to promote consecutive load/store patterns
    int bound = subframe_size + (143 + 8 + 1);
    for (i = 0; i < bound - 1; i += 2) {
        sig_scaled[i]     = residual[i]     >> shift;
        sig_scaled[i + 1] = residual[i + 1] >> shift;
    }
    // Handle remaining element if bound is odd
    if (i < bound) {
        sig_scaled[i] = residual[i] >> shift;
    }
}
