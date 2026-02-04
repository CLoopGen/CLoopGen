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
    // Variant 2: Strided memory access with increased stride (simulating larger data layout or padding)
    int stride = 4; // Assume arrays have a stride of 4 elements between valid data
    for (x = 0; x < 8; x += 2) {
        dst[x * stride] += src[x * stride] * obmc_weight[x * stride];
        dst[(x + 1) * stride] += src[(x + 1) * stride] * obmc_weight[(x + 1) * stride];
    }
}
