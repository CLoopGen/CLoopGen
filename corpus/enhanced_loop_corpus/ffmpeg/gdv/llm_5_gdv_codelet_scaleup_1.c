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
    int offset = x >> 1;

    if (offset + 3 >= w / 2) break;

    dst[x + 0] = dst[x + 1] = src[offset + 0];
    dst[x + 2] = dst[x + 3] = src[offset + 1];
    
    x += 4;
    if (x >= w - 7) break;
    
    offset = x >> 1;
    dst[x + 0] = dst[x + 1] = src[offset + 0];
    dst[x + 2] = dst[x + 3] = src[offset + 1];
    dst[x + 4] = dst[x + 5] = src[offset + 2];
    dst[x + 6] = dst[x + 7] = src[offset + 3];
}
}
