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
    for (x = 0; x < 16; x += 2) {
        if (obmc_weight[x] > 0) {
            dst[x] += src[x] * obmc_weight[x];
        }
        if (obmc_weight[x + 1] > 0) {
            dst[x + 1] += src[x + 1] * obmc_weight[x + 1];
        }
    }
}
