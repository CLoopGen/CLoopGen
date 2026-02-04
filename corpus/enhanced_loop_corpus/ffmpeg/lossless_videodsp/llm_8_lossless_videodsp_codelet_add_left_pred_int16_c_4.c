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
    for (i = 0; i < w; i += 2) {
        acc += src[i];
        acc &= mask;
        dst[i] = acc;
        if (i + 1 < w) {
            acc += src[i + 1];
            acc &= mask;
            dst[i + 1] = acc;
        }
    }
}
