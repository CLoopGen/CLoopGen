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
    for (x = 0; x < w - 7; x += 8) {
        int offset = (x >> 1);
        dst[x + 0] = src[offset];
        dst[x + 1] = src[offset];
        dst[x + 2] = src[offset + 1];
        dst[x + 3] = src[offset + 1];
        dst[x + 4] = src[offset + 2];
        dst[x + 5] = src[offset + 2];
        dst[x + 6] = src[offset + 3];
        dst[x + 7] = src[offset + 3];
    }
}
