#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int i;
extern uint8_t *dst;
extern int16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    int16_t *local_src = src;
    for (i = 0; i < 8; i++) {
        local_dst[7] += (unsigned int)local_src[7];
        local_dst[6] += (unsigned int)local_src[6];
        local_dst[5] += (unsigned int)local_src[5];
        local_dst[4] += (unsigned int)local_src[4];
        local_dst[3] += (unsigned int)local_src[3];
        local_dst[2] += (unsigned int)local_src[2];
        local_dst[1] += (unsigned int)local_src[1];
        local_dst[0] += (unsigned int)local_src[0];

        local_dst += stride;
        local_src += 8;
    }
    dst = local_dst - (stride * 8);
    src = local_src - 64;
}
