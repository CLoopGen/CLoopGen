#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int dc;
extern int stride;
extern uint8_t *obmc_weight;
extern int xblen;
extern int yblen;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < yblen; y++) {
    for (x = 0; x < xblen; x++) {
        int idx = x; // Consecutive access with direct indexing
        dst[idx] += dc * obmc_weight[idx];
    }
    dst += stride;
    obmc_weight += 32;
}
}
