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
for (x = 0; x < 4; x++) {
    uint16_t temp1 = src[x] * obmc_weight[x];
    uint16_t temp2 = src[x + 4] * obmc_weight[x + 4];
    dst[x] += temp1;
    dst[x + 4] += temp2;
}
}
