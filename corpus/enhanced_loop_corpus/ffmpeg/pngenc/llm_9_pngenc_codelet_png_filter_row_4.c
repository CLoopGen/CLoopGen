#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *top;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = (bpp + 3) / 4;
    for (i = 0; i < stride; i++) {
        int idx = i * 4;
        if (idx < bpp) dst[idx] = src[idx] - top[idx];
        if (idx + 1 < bpp) dst[idx + 1] = src[idx + 1] - top[idx + 1];
        if (idx + 2 < bpp) dst[idx + 2] = src[idx + 2] - top[idx + 2];
        if (idx + 3 < bpp) dst[idx + 3] = src[idx + 3] - top[idx + 3];
    }
}
