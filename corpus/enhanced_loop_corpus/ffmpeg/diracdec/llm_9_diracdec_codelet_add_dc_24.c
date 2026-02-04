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
    for (y = 0; y < yblen; y += 2) {
        for (x = 0; x < xblen; x++) {
            dst[x] += dc * obmc_weight[x];
        }
        dst += stride;
        obmc_weight += 32;

        if (y + 1 < yblen) {
            for (x = 0; x < xblen; x++) {
                dst[x] += (dc * 3 / 2) * obmc_weight[x];
            }
            dst += stride;
            obmc_weight += 32;
        }
    }
}
