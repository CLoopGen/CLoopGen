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
        for (x = 0; x < xblen; x += 4) {
            if (x + 3 < xblen) {
                dst[x]     += dc * obmc_weight[x];
                dst[x + 1] += dc * obmc_weight[x + 1];
                dst[x + 2] += dc * obmc_weight[x + 2];
                dst[x + 3] += dc * obmc_weight[x + 3];
            } else {
                for (; x < xblen; x++) {
                    dst[x] += dc * obmc_weight[x];
                }
            }
        }
        dst += stride;
        obmc_weight += 32;
    }
}
