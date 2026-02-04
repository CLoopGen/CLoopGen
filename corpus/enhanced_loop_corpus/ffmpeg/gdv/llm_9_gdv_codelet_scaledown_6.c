#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (; x < w; x += stride) {
        dst[x] = src[2 * x];
        if (x + 1 < w) dst[x + 1] = src[2 * (x + 1)];
        if (x + 2 < w) dst[x + 2] = src[2 * (x + 2)];
        if (x + 3 < w) dst[x + 3] = src[2 * (x + 3)];
    }
}
