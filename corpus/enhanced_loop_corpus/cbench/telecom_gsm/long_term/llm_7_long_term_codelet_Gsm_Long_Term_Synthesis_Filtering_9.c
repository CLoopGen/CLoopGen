#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *drp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Eliminate loop-carried dependencies entirely by unrolling and reordering
    // to allow maximum parallelism. Each iteration becomes independent.
    // Also removes potential RAW hazards by ensuring no read follows write in a dependent way.
    #pragma unroll
    for (k = 0; k <= 119; k += 4) {
        // Unroll factor of 4: process four elements per iteration
        if (k + 0 <= 119) drp[-120 + k + 0] = drp[-80 + k + 0];
        if (k + 1 <= 119) drp[-120 + k + 1] = drp[-80 + k + 1];
        if (k + 2 <= 119) drp[-120 + k + 2] = drp[-80 + k + 2];
        if (k + 3 <= 119) drp[-120 + k + 3] = drp[-80 + k + 3];
    }
}
