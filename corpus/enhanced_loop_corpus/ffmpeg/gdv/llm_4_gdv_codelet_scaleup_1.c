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
    uint8_t val0 = src[(x >> 1) + 0];
    uint8_t val1 = src[(x >> 1) + 1];
    uint8_t val2 = src[(x >> 1) + 2];
    uint8_t val3 = src[(x >> 1) + 3];

    if (val0) {
        dst[x + 0] = dst[x + 1] = val0;
    } else {
        dst[x + 0] = dst[x + 1] = 0;
    }

    if (val1) {
        dst[x + 2] = dst[x + 3] = val1;
    } else {
        dst[x + 2] = dst[x + 3] = 0;
    }

    if (val2) {
        dst[x + 4] = dst[x + 5] = val2;
    } else {
        dst[x + 4] = dst[x + 5] = 0;
    }

    if (val3) {
        dst[x + 6] = dst[x + 7] = val3;
    } else {
        dst[x + 6] = dst[x + 7] = 0;
    }
}
}
