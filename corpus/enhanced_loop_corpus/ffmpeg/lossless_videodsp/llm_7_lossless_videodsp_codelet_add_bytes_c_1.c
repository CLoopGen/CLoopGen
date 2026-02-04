#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    ptrdiff_t local_w = w;
    for (; i < local_w; i++) {
        local_dst[i + 1] = local_dst[i + 0] + local_src[i + 0];
    }
    dst = local_dst;
}
