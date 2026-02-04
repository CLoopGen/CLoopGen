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
    uint16_t acc[2] = {0};
    for (y = 0; y < yblen; y++) {
        acc[0] = 0; acc[1] = 0;
        for (x = 0; x < xblen; x += 2) {
            acc[0] += dc * obmc_weight[x];
            acc[1] += dc * obmc_weight[x + 1];
        }
        dst[0] += acc[0];
        dst[1] += acc[1];
        dst += stride;
        obmc_weight += 32;
    }
}
