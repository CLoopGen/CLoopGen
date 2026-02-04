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
    for (; i < w; i++) {
        if (dst[i + 0] == 0)
            continue;
        dst[i + 0] += src[i + 0];
    }
}
