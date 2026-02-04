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
    uint16_t temp0, temp1;
    for (y = 0; y < yblen; y++) {
        for (x = 0; x < xblen; x += 2) {
            temp0 = dc * obmc_weight[x];
            temp1 = dc * obmc_weight[x + 1];
            dst[x] += temp0;
            dst[x + 1] += temp1;
        }
        dst += stride;
        obmc_weight += 32;
    }
}
