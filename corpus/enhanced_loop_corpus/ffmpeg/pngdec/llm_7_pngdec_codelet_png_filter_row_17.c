#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int bpp;
extern int i;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_dst_val = 0;
    for (i = 0; i < bpp; i++) {
        p = last[i];
        dst[i] = p + src[i] + prev_dst_val;
        prev_dst_val = dst[i];
    }
}
