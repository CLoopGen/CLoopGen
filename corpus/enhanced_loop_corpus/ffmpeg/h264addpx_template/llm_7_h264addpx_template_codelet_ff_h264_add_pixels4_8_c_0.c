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
    for (i = 0; i < 4; i++) {
        local_dst[0] = (uint8_t)((unsigned int)(local_dst[0] + local_src[0]));
        local_dst[1] = (uint8_t)((unsigned int)(local_dst[1] + local_src[1]));
        local_dst[2] = (uint8_t)((unsigned int)(local_dst[2] + local_src[2]));
        local_dst[3] = (uint8_t)((unsigned int)(local_dst[3] + local_src[3]));
        local_dst += stride;
        local_src += 4;
    }
    dst = local_dst - (stride * 4);
    src = local_src - 16;
}
