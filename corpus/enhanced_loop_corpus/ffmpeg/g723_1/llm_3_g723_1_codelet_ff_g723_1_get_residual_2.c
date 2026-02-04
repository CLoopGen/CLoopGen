#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *residual;
extern int16_t *prev_excitation;
extern int lag;
extern int offset;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write pattern with precomputed source indices
    // Reorder writes to residual in consecutive order and use direct offset progression
    int16_t *src = &prev_excitation[offset];
    int count = 60 + 5 - 1 - 2;
    for (i = 0; i < count; i++) {
        residual[i + 2] = src[i % lag];  // Consecutive writes, sequential reads with wrap-around
    }
}
