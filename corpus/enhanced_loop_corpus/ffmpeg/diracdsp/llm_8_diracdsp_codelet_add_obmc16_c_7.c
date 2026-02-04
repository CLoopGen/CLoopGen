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
    for (x = 0; x < 32; x += 4) {
        dst[x]     += src[x]     * obmc_weight[x];
        dst[x + 1] += src[x + 1] * obmc_weight[x + 1];
        dst[x + 2] += src[x + 2] * obmc_weight[x + 2];
        dst[x + 3] += src[x + 3] * obmc_weight[x + 3];
    }
}
