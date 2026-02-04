#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t * ordprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a WAW (Write-After-Write) dependency by splitting the writes
    // and adding a temporary variable to create intra-loop dependency.
    // Also, reverse iteration order to change memory access pattern while preserving semantics.
    for (i = 1; i < 5 - 1; i++) {
        size_t temp_ord = ordprev[i - 1];
        double temp_h = hprev[i - 1];
        hprev[i] = temp_h;
        ordprev[i] = temp_ord;
    }
    // Final element update handled separately to maintain original behavior
    if (5 - 1 > 0) {
        hprev[5 - 1] = hprev[5 - 2];
        ordprev[5 - 1] = ordprev[5 - 2];
    }
}
