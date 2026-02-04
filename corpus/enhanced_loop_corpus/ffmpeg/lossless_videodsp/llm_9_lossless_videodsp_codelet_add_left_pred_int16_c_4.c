#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern ptrdiff_t w;
extern unsigned int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < w; i++) {
        acc += src[i] + src[i] * (src[i] & 1);
        acc &= mask;
        dst[i] = acc;
        i++;
        if (i < w) {
            acc += src[i] >> 1;
            acc &= mask;
            dst[i] = acc;
        }
    }
}
