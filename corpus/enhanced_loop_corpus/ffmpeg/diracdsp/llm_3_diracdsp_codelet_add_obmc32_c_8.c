#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint8_t *src;
extern  uint8_t *obmc_weight;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (simulating block-like access)
    int stride = 4; // Increased stride to simulate non-consecutive access pattern
    for (x = 0; x < 32; x += stride) {
        if (x + 0 < 32) dst[x] += src[x] * obmc_weight[x];
        if (x + 1 < 32) dst[x + 1] += src[x + 1] * obmc_weight[x + 1];
        if (x + 2 < 32) dst[x + 2] += src[x + 2] * obmc_weight[x + 2];
        if (x + 3 < 32) dst[x + 3] += src[x + 3] * obmc_weight[x + 3];
    }
}
