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
    x = 0;
    while (x < xblen) {
        dst[x] += dc * obmc_weight[x];
        if (x + 1 < xblen) {
            dst[x + 1] += dc * obmc_weight[x + 1];
        }
        x += 2;
    }
    dst += stride;
    obmc_weight += 32;
}
}
