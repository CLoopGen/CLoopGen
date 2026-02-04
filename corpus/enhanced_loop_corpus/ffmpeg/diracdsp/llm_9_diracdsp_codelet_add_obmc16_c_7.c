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
    for (x = 0; x < 8; x += 2) {
        uint16_t val0 = src[x] * obmc_weight[x];
        uint16_t val1 = src[x + 1] * obmc_weight[x + 1];
        dst[x] += val0;
        dst[x + 1] += val1;
    }
}
