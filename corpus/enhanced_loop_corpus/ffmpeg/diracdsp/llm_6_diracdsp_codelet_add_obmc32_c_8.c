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
    uint16_t temp0, temp1;
    for (x = 0; x < 32; x += 2) {
        temp0 = src[x] * obmc_weight[x];
        temp1 = src[x + 1] * obmc_weight[x + 1];
        dst[x] += temp0;
        dst[x + 1] += temp1;
    }
}
