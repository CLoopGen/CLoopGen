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
    uint16_t accum = 0;
    for (x = 0; x < 16; x += 2) {
        accum += src[x] * obmc_weight[x];
        dst[x] = accum;
        accum += src[x + 1] * obmc_weight[x + 1];
        dst[x + 1] = accum;
    }
}
