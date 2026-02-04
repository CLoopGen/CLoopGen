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
    // Variant 2: Strided memory access with increased stride (simulating larger data layout or tiling)
    int stride = 32; // Simulate a larger stride, e.g., rows in a padded image buffer
    for (x = 0; x < 16; x += 2) {
        dst[x * stride] += src[x * stride] * obmc_weight[x * stride];
        dst[(x + 1) * stride] += src[(x + 1) * stride] * obmc_weight[(x + 1) * stride];
    }
}
