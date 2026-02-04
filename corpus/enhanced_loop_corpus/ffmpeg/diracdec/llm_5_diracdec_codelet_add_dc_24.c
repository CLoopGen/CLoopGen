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
    for (x = 0; x < xblen; x += 2) {
        if (obmc_weight[x] > 0) {
            dst[x] += dc * obmc_weight[x];
        }
        if (obmc_weight[x + 1] > 0) {
            dst[x + 1] += dc * obmc_weight[x + 1];
        }
    }
    dst += stride;
    obmc_weight += 32;
}
}
