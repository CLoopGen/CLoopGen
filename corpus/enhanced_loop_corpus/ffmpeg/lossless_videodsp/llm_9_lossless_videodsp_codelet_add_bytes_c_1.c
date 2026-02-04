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
    for (; i < w; i += 4) {
        dst[i + 0] += src[i + 0] * 2;
        dst[i + 1] += src[i + 1] * 2;
        dst[i + 2] += src[i + 2] * 2;
        dst[i + 3] += src[i + 3] * 2;
    }
}
