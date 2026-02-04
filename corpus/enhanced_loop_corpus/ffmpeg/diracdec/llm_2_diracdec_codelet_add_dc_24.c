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
for (y = 0; y < yblen; y++) {
    uint16_t *dst_ptr = dst;
    uint8_t *weight_ptr = obmc_weight;
    for (x = 0; x < xblen; x += 2) {
        dst_ptr[x] += dc * weight_ptr[x];
        dst_ptr[x + 1] += dc * weight_ptr[x + 1];
    }
    dst += stride;
    obmc_weight += 32;
}
}
