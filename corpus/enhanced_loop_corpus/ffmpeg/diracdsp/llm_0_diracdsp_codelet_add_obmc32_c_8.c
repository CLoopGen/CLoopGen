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
    for (int outer = 0; outer < 16; outer++) {
        x = outer * 2;
        dst[x] += src[x] * obmc_weight[x];
        dst[x + 1] += src[x + 1] * obmc_weight[x + 1];
    }
}
