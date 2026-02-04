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
    uint16_t accum[8] = {0};
    for (x = 0; x < 8; x += 2) {
        accum[x] = src[x] * obmc_weight[x];
        accum[x + 1] = src[x + 1] * obmc_weight[x + 1];
    }
    for (x = 0; x < 8; x++) {
        dst[x] += accum[x];
    }
}
