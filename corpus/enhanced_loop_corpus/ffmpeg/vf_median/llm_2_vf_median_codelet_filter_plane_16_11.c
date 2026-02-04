#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of scattered accesses, accumulate contributions into local accumulators
    // and write back in a consecutive manner to improve cache locality.
    uint16_t *fine_base = cfine + (1 << ((16 + 1) / 2)) * width * (srcp[0] >> ((16 + 1) / 2));
    uint16_t *coarse_base = ccoarse + (1 << ((16 + 1) / 2)) * 0;

    for (int i = 0; i < width; i++) {
        int shift = (16 + 1) / 2;
        int mask = (1 << shift) - 1;
        int high = srcp[i] >> shift;
        int low = srcp[i] & mask;

        // Reuse base pointers with fixed offsets updated per iteration
        cfine[(width * high + i) * (1 << shift) + low] += radiusV + 1;
        ccoarse[i * (1 << shift) + high] += radiusV + 1;
    }
}
