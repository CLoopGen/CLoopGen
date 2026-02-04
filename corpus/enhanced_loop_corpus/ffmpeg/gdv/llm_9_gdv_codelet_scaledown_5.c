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
    for (x = 0; x < w - 3; x += 4) {
        int offset = 2 * x;
        dst[x + 0] = src[offset + 0];
        dst[x + 1] = src[offset + 2];
        dst[x + 2] = src[offset + 4];
        dst[x + 3] = src[offset + 6];
    }
}
